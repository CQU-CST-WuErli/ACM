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

const int N=1e5+100;
ll sum[N*3],add[N*3];
int n;

void push_up(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void push_down(int l,int r,int rt) {
	if (add[rt]) {
		int mid=(l+r)>>1;
		add[rt<<1]=add[rt];
		sum[rt<<1]=(mid-l+1)*add[rt];
		add[rt<<1|1]=add[rt];
		sum[rt<<1|1]=(r-mid)*add[rt];
		add[rt]=0;
	}
}

void build(int l,int r,int rt) {
	add[rt]=0;
	if (l==r) {
		sum[rt]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	push_up(rt);
}

void update(int L,int R,int v,int l,int r,int rt) {
	if (L<=l && r<=R) {
		add[rt]=v;
		sum[rt]=v*(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	push_down(l,r,rt);
	if (L<=mid) update(L,R,v,l,mid,rt<<1);
	if (R>mid) update(L,R,v,mid+1,r,rt<<1|1);
	push_up(rt);
}

ll query(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return sum[rt];
	}
	ll ret=0;
	int mid=(l+r)>>1;
	if (L<=mid) ret+=query(L,R,l,mid,rt<<1);
	if (R>mid) ret+=query(L,R,mid+1,r,rt<<1|1);
	push_up(rt);
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
		int q;SI(q);
		while (q--) {
			int x,y,z;
			SIII(x,y,z);
			update(x,y,z,1,n,1);
		}
		printf("Case %d: The total value of the hook is %lld.\n",kase,query(1,n,1,n,1));
	}
	return 0;
}

