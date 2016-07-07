//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int k;
int n,m;
const int N=1e5+10; 
int vis[N];
int deg[N],col[N];
int pnt[N<<1],nxt[N<<1],head[N<<1],cnt;

void addedge(int u,int v){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
}

void dfs(int u){
	for (int i=head[u];~i;i=nxt[i]){
		int v=pnt[i];
		col[vis[v]]=u;
	}
	for (int i=1;i<=k;i++){            // 精华所在 
		if (col[i]!=u){
			vis[u]=i;break;
		}
	}
	for (int i=head[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (!vis[v]) dfs(v);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (scanf("%d%d",&n,&m)==2){
		if (kase!=1) cout << endl; kase++;
		CLR(vis);CLR(deg);
		OFF(head);cnt=0;
		k=0;
		for (int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
			deg[u]++;deg[v]++;
			k=max(k,max(deg[u],deg[v]));
		}
		if (k%2==0) k++;
		dfs(1);
		printf("%d\n",k);
		for (int i=1;i<=n;i++) printf("%d\n",vis[i]);
	}
	return 0;
}


