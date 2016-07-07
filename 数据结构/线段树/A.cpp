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
typedef long long  ll;
using namespace std;

const int N=5e4+10;
const int INF=0x3f3f3f3f;
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int T,n;
int sum[N*3];

void push_up(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt){
	if (l==r){
		scanf("%d",&sum[rt]);
		return;
	}
	int m=l+r>>1;
	build(lson);
	build(rson);
	push_up(rt);
}

void update(int o,int v,int l,int r,int rt){
	if (l==r){
		sum[rt]+=v;
		return;
	} 
	int m=l+r>>1;
	if (o<=m) update(o,v,lson);
	else update(o,v,rson);
	push_up(rt);
}

int query(int L,int R,int l,int r,int rt){
	if (L<=l && r<=R){
		return sum[rt];
	}
	int m=l+r>>1;
	int ret=0;
	if (L<=m) ret+=query(L,R,lson);
	if (R>m)  ret+=query(L,R,rson);
	return ret;
}

int main()
{
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		printf("Case %d:\n",i);
		scanf("%d",&n);
		build(root);
		char s[10];
		int x,y;
		while (scanf("%s",s)){
			if (s[0]=='E') break;
			scanf("%d%d",&x,&y);
			if (s[0]=='A') update(x,y,root);
			else if (s[0]=='S') update(x,-y,root);
			else if (s[0]=='Q') printf("%d\n",query(x,y,root));
		}
	}
	return 0;
}


