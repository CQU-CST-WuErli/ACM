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
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=4e5;
int pnt[N],head[1010],nxt[N],cap[N];
int cnt;
int n,F,D;

void add_edge(int u,int v,int f){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=f;
}

int iter[1010],level[1010];

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
	if (u==t || Flow==0) return Flow;
	int left=Flow;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(cap[i],left));
			iter[u]=i;
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
		for (int i=s;i<=t;i++) iter[i]=head[i];
		Max_flow+=dfs(s,t,INF);
	}
	return Max_flow;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> F >> D){
		OFF(head);cnt=0;
		int s=0,t=F+2*n+D+1;
		for (int i=1;i<=F;i++) {
			int x;SI(x);
			add_edge(s,i,x);
			add_edge(i,s,0);
		}
		for (int i=1;i<=D;i++) {
			int x;SI(x);
			add_edge(F+2*n+i,t,x);
			add_edge(t,F+2*n+i,0);
		}	
		getchar();
		char tt[250];
		for (int i=1;i<=n;i++){
			gets(tt+1);
//			puts(tt+1);
			for (int j=1;j<=F;j++) {
				if (tt[j]=='Y') {
					add_edge(j,F+i,1);
					add_edge(F+i,j,0);
				}
			}
		}
		for (int i=1;i<=n;i++){
			gets(tt+1);
//			puts(tt+1);
			for (int j=1;j<=D;j++){
				if (tt[j]=='Y'){
					add_edge(F+n+i,F+2*n+j,1);
					add_edge(F+2*n+j,F+n+i,0);
				}
			} 
		}
		for (int i=1;i<=n;i++) {
			add_edge(F+i,F+n+i,1);
			add_edge(F+n+i,F+i,0);
		}
		cout << Dinic(s,t) << endl;
	}
	return 0;
}

