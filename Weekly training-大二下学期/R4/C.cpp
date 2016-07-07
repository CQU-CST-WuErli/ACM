//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=100010;

ll sum[N<<2],add[N<<2];
int n,m;

void push_up(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void push_down(int l,int r,int rt) {
	if (add[rt]) {
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		int mid=(l+r)>>1;
		sum[rt<<1]+=(mid-l+1)*add[rt];
		sum[rt<<1|1]+=(r-mid)*add[rt];
		add[rt]=0;
	}
}

void build(int l,int r,int rt) {
	add[rt]=0;
	if (l==r) {
		scanf("%I64d",&sum[rt]);
		return ;
	}
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
	push_up(rt);
}

void update(int L,int R,ll v,int l,int r,int rt) {
	if (L<=l && r<=R) {
		add[rt]+=v;
		sum[rt]+=(r-l+1)*v;
		return;
	}
	push_down(l,r,rt);
	int mid=(l+r)>>1;
	if (L<=mid) update(L,R,v,Lson);
	if (R>mid) update(L,R,v,Rson);
	push_up(rt);
}

ll query(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return sum[rt];
	}
	push_down(l,r,rt);
	int mid=(l+r)>>1;
	ll ret=0LL;
	if (L<=mid) ret+=query(L,R,Lson);
	if (R>mid) ret+=query(L,R,Rson);
	push_up(rt);
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
	    build(1,n,1);
	    getchar();
	    rep(i,1,m) {
	    	char op;
	    	cin >> op;
	    	int l,r;
	    	SII(l,r);
	    	if (r<l) swap(l,r);
	    	if (op=='Q') {
	    		printf("%I64d\n",query(l,r,1,n,1));
	    	}
	    	else if (op=='C') {
	    		ll v;
	    		scanf("%I64d",&v);
	    		update(l,r,v,1,n,1);
	    	}
	    }
	}
	return 0;
}