//
//  Created by  CQUWEL
//  Copyright (c) 2015年 CQUWEL. All rights reserved.
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

const int N=5e4+5;
const int INF=0x3f3f3f3f;
#define root 1,n,1
#define lson l,m,rt << 1
#define rson m+1,r, rt<<1|1
 
int n,q;
int sum[N*3], maxv[N*3], minv[N*3];

//rt表示节点编号 
void push_up(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
	minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
}

void build(int l,int r,int rt){
	if (l==r){
		int x;scanf("%d",&x);
		sum[rt]=minv[rt]=maxv[rt]=x;
		return; 
	}
	int m=l+r>>1;
	build(lson);
	build(rson);
	push_up(rt);
}

int query(int op,int L,int R,int l,int r,int rt){
	if (L<=l && r<=R){
		if (op==0) return sum[rt];
		if (op==1)  return maxv[rt];
		if (op==2)  return minv[rt];
	}
	int m=l+r>>1;
	if (op==0){
		int ret=0;
		if (L<=m) ret+=query(op,L,R,lson);
		if (R>m) ret+=query(op,L,R,rson);
		return ret; 
	}
	else if (op==1){
		int Max=-INF;
		if (L<=m) Max=max(Max,query(op,L,R,lson));
		if (R>m)  Max=max(Max,query(op,L,R,rson));
		return Max;
	}
	else if (op==2){
		int Min=INF;
		if (L<=m) Min=min(Min,query(op,L,R,lson));
		if (R>m)  Min = min(Min,query(op,L,R,rson));
		return Min;
	}
}
int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%d%d",&n,&q)==2){
		build(root);
		while (q--){
			int l,r;scanf("%d%d",&l,&r);
			int mmax=query(1,l,r,root);
			int mmin=query(2,l,r,root);
			printf("%d\n",mmax-mmin);
		}
	}
	return 0;
}


