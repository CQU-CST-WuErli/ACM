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

const int N=2e5+10;
const int M=500;
int pnt[N],nxt[N],head[M],cap[N]; 
int cnt;
int info;
int n,m;
int source,sink;
int num[M];
map<int,int> mp;
int A[M],B[M],C[M];
vector<int> g[M];

int get_id(int x) {
	if (!mp.count(x)) mp[x]=info++;
	return mp[x];
}

void add_edge(int u,int v,int w){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=w;
} 

int level[M],iter[M];

bool bfs(int s,int t){
	OFF(level);
	queue<int> q;
	level[s]=0;
	q.push(s);
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

int dfs(int u,int t,int f){
	if (u==t || !f) return f;
	int left=f;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(cap[i],left));
			iter[u]=i;
			cap[i]-=d;
			cap[i^1]+=d;
			left-=d;
			if (!left) return f; 
		}
	}
	level[u]=-1;
	return f-left;
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
	while (cin >> n) {
		OFF(head);cnt=0;info=n+1;source=0;mp.clear();
		for (int i=0;i<=n;i++) g[i].clear();
		// 1->n student;  n+1->n+m info;  source=0;
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d",A+i,B+i,C+i);
			for (int j=1;j<=A[i];j++) {
				int x;SI(x);
				int id=get_id(x);
				g[i].push_back(id);
			}
		}
		SI(m);set<int> st;
		for (int i=0;i<g[m].size();i++) st.insert(g[m][i]);
		for (int i=1;i<=n;i++) {
			if (i==m) continue;
			add_edge(source,i,C[i]);
			add_edge(i,source,0);
			for (int j=0;j<g[i].size();j++) {
				int v=g[i][j];
				add_edge(i,v,1);
				add_edge(v,i,0);
			}
		}
		for (int i=n+1;i<info;i++) {
			if (st.count(i)) continue;
			add_edge(i,m,1);
			add_edge(m,i,0);
		}
		sink=info+1;
		add_edge(m,sink,INF_INT);
		add_edge(sink,m,0);
		int ans=Dinic(source,sink);
		cout << ans+A[m] << endl;
	}
	return 0;
}

