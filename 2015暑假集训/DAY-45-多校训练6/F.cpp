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

struct P{
	int x,y;
}p[100010];
int pnt[N],head[N],nxt[N],cap[N];
int cnt;
int n,m;

void add_edge(int u,int v,int c){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=c;
}

int iter[100100],level[100100];

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

int dfs(int u,int t,int Flow){
	if (u==t || !Flow) return Flow;
	int left=Flow;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(cap[i],left));
			iter[u]=i;
			cap[i]-=d;
			cap[i^1]+=d;
			iter[u]=i;
			left-=d;
			if (!left) return Flow;
		}
	}
	level[u]=-1;
	return Flow-left;
}

int Dinic(int s,int t){
	int Max_flow=0;
	while (bfs(s,t)) {
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
	int T;
	SI(T);
	while (T--){
		OFF(head);cnt=0;
		SII(n,m);
		int s=0,t=n+1;
		int sx=INF_INT,sy=INF_INT,tx=-INF_INT,ty=-INF_INT;
		int a,b;
		for (int i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			if (p[i].x<sx ){
				sx=p[i].x;sy=p[i].y;
				a=i;
			}
			if (p[i].x>tx){
				tx=p[i].x;ty=p[i].y;
				b=i;
			}
		} 
		add_edge(s,a,INF_INT);
		add_edge(a,s,INF_INT);
		add_edge(b,t,INF_INT);
		add_edge(t,b,INF_INT);
		for (int i=1;i<=m;i++){
			int u,v,c;
			SIII(u,v,c);
			add_edge(u,v,c);
			add_edge(v,u,c);
		}
		cout << Dinic(s,t) << endl;
	}
	return 0;
}

