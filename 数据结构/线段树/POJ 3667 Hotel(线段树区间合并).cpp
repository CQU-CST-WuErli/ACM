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
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=50100;

int n,m;
int ans[N<<2],pre[N<<2],suf[N<<2],cover[N<<2];

void pushup(int rt,int len) {
	pre[rt]=pre[rt<<1];
	if (pre[rt<<1]==len-(len>>1)) pre[rt]+=pre[rt<<1|1];
	suf[rt]=suf[rt<<1|1];
	if (suf[rt<<1|1]==(len>>1)) suf[rt]+=suf[rt<<1];
	ans[rt]=max(max(ans[rt<<1],ans[rt<<1|1]),suf[rt<<1]+pre[rt<<1|1]);
}

void pushdown(int rt,int len) {
	if (~cover[rt]) {
		pre[rt<<1]=suf[rt<<1]=ans[rt<<1]=cover[rt]?len-(len>>1):0;
		pre[rt<<1|1]=suf[rt<<1|1]=ans[rt<<1|1]=cover[rt]?len>>1:0;
		cover[rt<<1]=cover[rt<<1|1]=cover[rt];
		cover[rt]=-1;
	}
}

void build(int l,int r,int rt) {
	cover[rt]=-1;
	ans[rt]=pre[rt]=suf[rt]=r-l+1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
}

void updata(int L,int R,int v,int l,int r,int rt) {
	if (L<=l && r<=R) {
		cover[rt]=v;
		pre[rt]=suf[rt]=ans[rt]=cover[rt]?r-l+1:0;
		return;
	}
	pushdown(rt,r-l+1);
	int mid=(l+r)>>1;
	if (L<=mid) updata(L,R,v,Lson);
	if (R>mid) updata(L,R,v,Rson);
	pushup(rt,r-l+1);
}


int query(int o,int l,int r,int rt) {
	if (l==r) return l;
	pushdown(rt,r-l+1);
	int mid=(l+r)>>1;
	if (ans[rt<<1]>=o) return query(o,Lson);
	else if (suf[rt<<1]+pre[rt<<1|1]>=o) return mid-suf[rt<<1]+1;
	else return query(o,Rson);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2) {
		// BUG;
		build(Root);
		int op;
		// lookln(ans[1]);
		while (SI(op)==1) {
			if (op==1) {
				int x;SI(x);
				if (ans[1]<x) cout << 0 << endl;
				else {
					int tt=query(x,Root);
					cout << tt << endl;
					updata(tt,tt+x-1,0,Root);
				}
			}
			if (op==2) {
				int l,r;
				SII(l,r);
				updata(l,l+r-1,1,Root);
			}
		}
	}
	return 0;
}