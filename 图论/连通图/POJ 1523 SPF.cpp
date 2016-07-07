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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1002;
vector<int> g[N];
int vis[N],pre[N],low[N];
int iscut[N];
int u,v; 
int ne;
int dfs_clock;

void DFS(int u) {
	vis[u]=1;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (!vis[v]) {
			DFS(v);
		}
	}
}

int dfs(int fa,int u) {
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (!pre[v]) {
			child++;
			int lowv=dfs(u,v);
			lowu=min(lowu,lowv);
			if (lowv>=pre[u]) {
				iscut[u]=1;
			}
		}
		else if (pre[v]<pre[u] && v!=fa) {
			lowu=min(pre[v],lowu);
		}
	}
	if (fa<0 && child==1) iscut[u]=0;
	low[u]=lowu;
	return lowu;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (SI(u)==1 && u) {
		for (int i=0;i<N;i++) g[i].clear();
		ne=0;dfs_clock=0;
		CLR(pre);CLR(low);CLR(iscut);
		SI(v);
		g[u].push_back(v);
		g[v].push_back(u);
		ne=max(ne,max(u,v));
		while (SI(u)==1 && u) {
			SI(v);
			g[u].push_back(v);
			g[v].push_back(u);
			ne=max(ne,max(u,v));
		}
		dfs(-1,1);
		printf("Network #%d\n",kase++);
		int flag=0;int scc;
		for (int i=1;i<=ne;i++) {
			if (iscut[i]) {
//				lookln(i);
				CLR(vis);
				vis[i]=1;
				scc=0;
				for (int j=0;j<g[i].size();j++) {
					int x=g[i][j];
					if (!vis[x]) {
						scc++;
						DFS(x);
						flag=1;
					}
				}
				printf("  SPF node %d leaves %d subnets\n",i,scc);
			}
		}	
		if (!flag) printf("  No SPF nodes\n");
		printf("\n");
	}
	return 0;
}

