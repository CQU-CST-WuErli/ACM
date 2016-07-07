//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=5e4+100;

int sum[N*4];
int n;

void push_up(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt) {
	if (l==r) {
		scanf("%d",sum+rt);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	push_up(rt);
} 

void update(int o,int v,int l,int r,int rt) {
	if (l==r) {
		sum[rt]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if (o<=mid) update(o,v,l,mid,rt<<1);
	else update(o,v,mid+1,r,rt<<1|1);
	push_up(rt);
}

int query(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return sum[rt];
	}
	int mid=(l+r)>>1;
	int ret=0;
	if (L<=mid) ret+=query(L,R,l,mid,rt<<1);
	if (R>mid) ret+=query(L,R,mid+1,r,rt<<1|1);
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		SI(n);
		build(1,n,1);
		string s;
		printf("Case %d:\n",kase);
		while (cin >> s) {
			if (s[0]=='E') break;
			int x,y;
			SII(x,y);
			if (s[0]=='Q') {
				int ans=query(x,y,1,n,1);
				printf("%d\n",ans);
			} 
			else if (s[0]=='A') {
				update(x,y,1,n,1);
			}
			else if (s[0]=='S') {
				update(x,-y,1,n,1);
			}
		}
	}
	return 0;
}

