//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.

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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 100100
int N,M,Q;

struct Node{
	int item,city;
}es[maxn*4];
int par[maxn*4],rank[maxn*4],loc[maxn*4];

void init(int n){
	for (int i=1;i<=n;i++){
		rank[i]=0;par[i]=i;
	}
} 
int find(int x){
	if (par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y){
	x=find(x);y=find(y);
	if (x==y) return ;
	else{
		if (rank[x]<rank[y]){
			par[x]=y;
			if (!loc[y]) loc[y]=loc[x];
		}
		else{
			par[y]=x;
			if (!loc[x]) loc[x]=loc[y];
			if (rank[x]==rank[y]) rank[x]++;
		}
	}
}
int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (cin >> N >> M >> Q){
		CLR(loc);
		init(M+N);
		int cnt=0;
		for (int i=1;i<=N;i++)
			scanf("%d%d",&es[i].item,&es[i].city);	
		for (int i=1;i<=M;i++){
			int user,item,city;
			scanf("%d%d%d",&user,&item,&city);
			unite(user+N,item);
			item=find(item);
			if (city && !loc[item]) loc[item]=city;
		}
		for (int i=1;i<=N;i++){
			int t=es[i].item;
			t=find(t);
			if (!loc[t] && es[i].city) loc[t]=es[i].city;
		}
		while (Q--){
			int id,Id;
			scanf("%d%d",&id,&Id);
			Id+=id*N;
			printf("%d\n",loc[find(Id)]);
		}
	}
	return 0;
}


