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

const int N=3e5;
const int M=1010;
int pnt[N],head[M],nxt[N],cap[N];
int cnt;
int iter[M],level[M];
int n,m;

void add_edge(int u,int v,int w){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=w;
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
			left-=d;
			cap[i]-=d;
			cap[i^1]+=d;
			if (!left) return Flow;
		}
	}
	level[u]=-1;
	return Flow-left;
}

int Dinic(int s,int t){
	int Max_flow=0;
	while (bfs(s,t)){
		for (int i=s;i<=t;i++) iter[i]=head[i];
		Max_flow+=dfs(s,t,INF_INT);
	}
	return Max_flow;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	for (int kase=scanf("%d",&_);kase<=_;kase++){
		OFF(head);cnt=0;
		SII(n,m);
		int source=0,sink=0,maxd=0;
		int sum=0;
		for (int i=1;i<=n;i++){
			int p,st,ed;
			SIII(p,st,ed);
			sum+=p;
			add_edge(source,i,p);
			add_edge(i,source,0);
			maxd=max(maxd,ed);
			for (int j=st;j<=ed;j++){
				add_edge(i,j+n,1);
				add_edge(j+n,i,0);
			}
		}
		sink=maxd+n+1;
		for (int i=1;i<=maxd;i++){
			add_edge(i+n,sink,m);
			add_edge(sink,i+n,0);
		}
		int ans=Dinic(source,sink);
//		lookln(ans);
		cout << "Case " << kase << ": ";
		if (ans==sum) cout << "Yes\n";
		else cout << "No\n";
		puts("");
	}
	return 0;
}

