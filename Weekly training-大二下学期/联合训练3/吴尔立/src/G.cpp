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
#include <ctime>
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


inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

const int N=1100;
const int M=2e5+10;
// spfa;
struct Edge{
	int v;int w;
};
vector<Edge> g[N];
vector<Edge> revg[N];
int d[N],dr[N];
int vis[N];
int n,m;

// Dinic;
int pnt[M],head[N],nxt[M],cap[M];
int cnt;
int iter[N],level[N];


//initial
void init(){
	for (int i=0;i<=n;i++) g[i].clear();
	for (int i=0;i<=n;i++) revg[i].clear();
	OFF(head);cnt=0;
}

// spfa
void spfa(int s,int *dp,vector<Edge> *G){
	CLR(vis);
	for (int i=1;i<=n;i++) dp[i]=INF_INT;
	queue<int> q;
	q.push(s);
	vis[s]=1;dp[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i].v;
			int w=G[x][i].w;
			if (dp[v]>dp[x]+w){
				dp[v]=dp[x]+w;
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

// Dinic
void add_edge(int u,int v,int c){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=c;
}

bool bfs(int s,int t){
	OFF(level);
	queue<int> q;
	q.push(s);
	level[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (level[v]==-1 && cap[i]){
				level[v]=level[x]+1;
				q.push(v);
			}
		}
	}
	return level[t]!=-1;
}

int dfs(int u,int t,int Flow){
	if (u==t) return Flow;
	int left=Flow;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(left,cap[i]));
			cap[i]-=d;
			cap[i^1]+=d;
			left-=d;
			if (!left) return Flow;
		}
	}
	level[u]=-1;
	return Flow-left;
}

int Dinic(int s,int t){
	int Max_flow=0;
	while (bfs(s,t)){
		for (int i=1;i<=n;i++) iter[i]=head[i];
		Max_flow+=dfs(s,t,INF_INT);
	}
	return Max_flow;
}

int main(){
    int start = clock();
	int _;SI(_);
	// cout << _ << endl;
	while (_--){
		SII(n,m);
		init();

		int st = 1,ed = n;
		for (int i=1;i<=m;i++){
			int u,v,c;
			u=read();v=read();c=read();
//			if (u==v) continue;
			g[u].push_back(Edge{v,c});
			revg[v].push_back(Edge{u,c});
		}
		SII(st,ed);
		spfa(st,d,g);
		spfa(ed,dr,revg);
		// ×î´óÁ÷
		for (int i=1;i<=n;i++){
			for (int j=0;j<g[i].size();j++){
				int v=g[i][j].v;
				int w=g[i][j].w;
				if (d[i]+dr[v]+w==d[ed]) {
					add_edge(i,v,1);
					add_edge(v,i,0);
				}
			}
		}
		int ans=Dinic(st,ed);
		cout << ans << endl;
	}
	return 0;
}

