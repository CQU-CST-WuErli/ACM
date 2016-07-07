//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long  ll;
using namespace std;

const int N=1e5+10;
const int INF=0x3f3f3f3f;


ll sum[N*3],add[N*3];
ll n,q;

void push_up(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
} 

void push_down(int rt,int m){
	if (add[rt]){
		add[rt<<1] += add[rt];
		add[rt<<1|1]+=add[rt];
		sum[rt<<1]+=add[rt]*(m-(m>>1));
		sum[rt<<1|1] += add[rt]*(m>>1);
		add[rt]=0;
	} 
}

void build(int l,int r,int rt){
	add[rt]=0;
	if (l==r){
		scanf("%lld",&sum[rt]);
		return ;
	}
	int m=l+r>>1;
	build(lson);
	build(rson);
	push_up(rt);
}

void update(int L,int R,int v,int l,int r,int rt){
	if (L<=l && r<=R) {
		add[rt]+=v;
		sum[rt]+=(ll) v*(r-l+1);
		return ;
	}
	push_down(rt,r-l+1);
	int m=l+r>>1;
	if (L<=m) update(L,R,v,lson);
	if (R>m ) update(L,R,v,rson);
	push_up(rt); 
}

ll query(int L,int R,int l,int r,int rt){
	if (L<=l && r<=R) return sum[rt];
	push_down(rt,r-l+1);
	ll ret=0;
	int m=l+r>>1;
	if (L<=m) ret+=query(L,R,lson);
	if (R>m)  ret+=query(L,R,rson);
	return ret; 
}

int main()
{
	while (scanf("%lld%lld",&n,&q)==2){
		build(root);
		while (q--){
			char op[2];
			int a,b,c;
			scanf("%s",op);
			if (op[0]=='Q'){
				scanf("%d%d",&a,&b);
				printf("%lld\n",query(a,b,root));
			}
			else {
				scanf("%d%d%d",&a,&b,&c);
				update(a,b,c,root);
			}
		}
	}
	return 0;
}


