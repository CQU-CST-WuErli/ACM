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
#define filetest freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin)
#define BUG(x) puts("In line x\n")
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;

const int N=2e5+10;
int n,m;
int maxv[N*3];

void push_up(int rt){
	maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
} 

void build(int l,int r,int rt){
	if (l==r){
		scanf("%d",&maxv[rt]);
		return ;
	}
	int m=l+r>>1;
	build (lson);
	build (rson);
	push_up(rt);
}

void update(int o,int v,int l,int r,int rt){
	if (l==r) {
		maxv[rt]=v;
		return ;
	}
	int m=l+r>>1;
	if (o<=m) update(o,v,lson);
	else update(o,v,rson);
	push_up(rt);
}

int query(int L,int R,int l,int r,int rt){
	if (L<=l && r<=R){
		return maxv[rt];
	}
	int m=l+r>>1;
	int mret=-INF;
	if (L<=m) mret=max(mret,query(L,R,lson));
	if (R>m)  mret=max(mret,query(L,R,rson));
	return mret;
}

int main()
{
	while (scanf("%d%d",&n,&m)==2){
		build(root);
		while (m--){
			char op[2];
			int a,b;
			scanf("%s%d%d",op,&a,&b);
			if (op[0]=='Q'){
				printf("%d\n",query(a,b,root));
			}
			else update(a,b,root);
		}
	}
	return 0;
}


