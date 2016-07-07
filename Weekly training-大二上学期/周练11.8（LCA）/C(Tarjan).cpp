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

const int N=40100;

int n,m,q;
struct Edge{
	int v,dis;
};
vector<Edge> g[N];
int par[N],vis[N],dis[N],ans[40010];

struct P{
	int v,id;
};
vector<P> query[N];

int find(int x) {
	return par[x]=par[x]==x?x:find(par[x]);
}

void dfs(int u,int d) {
	vis[u]=1;
	par[u]=u;
	dis[u]=d;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i].v;
		if (vis[v]) continue;
		dfs(v,d+g[u][i].dis);
		par[v]=u;
	}
	for (int i=0;i<query[u].size();i++){
		P& q=query[u][i];
		if (vis[q.v]) ans[q.id]=dis[u]+dis[q.v]-2*dis[find(q.v)];
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;cin >> T_T;
	while (T_T--) {
		cin >> n >> q;
		for (int i=0;i<=n;i++) g[i].clear(),query[i].clear();
		int root=0;
		for (int i=1;i<n;i++) {
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			if (!root) root=u;
			g[u].push_back(Edge{v,d});
			g[v].push_back(Edge{u,d});
		}
//		lookln(q);
		for (int i=1;i<=q;i++){
			int u,v;
			SII(u,v);
			query[u].push_back(P{v,i});
			query[v].push_back(P{u,i});
		}
		CLR(vis);CLR(dis);
		dfs(root,0);
		for (int i=1;i<=q;i++)	cout << ans[i] << endl;
	}
	return 0;
}

