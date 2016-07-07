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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=2e6;

int sum[N<<2];
int color[N<<2];
string s;

void push_up(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	if (color[rt<<1]==color[rt<<1|1] && color[rt<<1]!=-1) {
		color[rt]=color[rt<<1];
	}
	else color[rt]=-1;
}

void push_down(int l,int r,int rt) {
	if (color[rt]!=-1) {
		int mid=(l+r)>>1;
		color[rt<<1]=color[rt<<1|1]=color[rt];
		sum[rt<<1]=(mid-l+1)*color[rt];
		sum[rt<<1|1]=(r-mid)*color[rt];
		color[rt]=-1;
	}
}

void build(int l,int r,int rt) {
	if (l==r) {
		sum[rt]=color[rt]=s[l]-'0';
		return;
	}
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
	push_up(rt);
}

void update(int L,int R,int v,int op,int l,int r,int rt) {
	if (L<=l && r<=R && (op!=-1 || color[rt]!=-1)) {
		if (op==-1) {
			color[rt]^=1;
			sum[rt]=(r-l+1)*color[rt];
		}
		else {
			color[rt]=op;
			sum[rt]=(r-l+1)*op;
		}
		return;
	}
	push_down(l,r,rt);
	int mid=(l+r)>>1;
	if (L<=mid) update(L,R,v,op,Lson);
	if (R>mid) update(L,R,v,op,Rson);
	push_up(rt);
}

int query(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return sum[rt];
	}
	push_down(l,r,rt);
	int mid=(l+r)>>1;
	int ret=0;
	if (L<=mid) ret+=query(L,R,Lson);
	if (R>mid) ret+=query(L,R,Rson);
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif

	for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
		s="x";
		int m;
		SI(m);
		while (m--) {
			int x;string tt;
			SI(x);
			cin >> tt;
			rep(i,1,x) s+=tt;
		}
		int n=s.size()-1;
//		cout << s << endl;
		build(1,n,1);
		int q;
		SI(q);
		printf("Case %d:\n",kase);
		int Q=1;
		while (q--) {
			char op;
			int a,b;
			cin >> op >> a >> b;
			a++,b++;
			if (op=='F') {
				update(a,b,1,1,1,n,1);
			}
			else if (op=='E') {
				update(a,b,0,0,1,n,1);
			}
			else if (op=='I') {
				update(a,b,1,-1,1,n,1);
			}
			else if (op=='S') {
				printf("Q%d: %d\n",Q++,query(a,b,1,n,1));
			}
		}
	}
	return 0;
}
