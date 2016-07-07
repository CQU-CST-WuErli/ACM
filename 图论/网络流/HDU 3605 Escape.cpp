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
const int INF_INT=0x3fffffff;
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

const int N=2e5,M=1e4+100;
int pnt[N],nxt[N],head[M],cap[N];
int cnt;
int n,m;
int sta[1200];

void add_edge(int u,int v,int c){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=c;
}

int pla(int i) {
	return i+1100;
}

int iter[M],level[M];

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
			int d=dfs(v,t,min(cap[i],left));
			left-=d;
			iter[u]=i;
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
	while(bfs(s,t)){
		for (int i=0;i<=1500;i++) iter[i]=head[i];
		Max_flow+=dfs(s,t,INF_INT);
	}
	return Max_flow;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while  (cin >> n >> m){
		OFF(head);cnt=0;CLR(sta);
		int source=0,sink=m+(1<<m);
		for (int i=1;i<=n;i++) {
			int tmp=0;
			for (int j=0;j<m;j++) {
				int x;x=read();
				if (x) tmp|=(1<<j);
			}
			sta[tmp]++;
		}
		for (int i=1;i<=1024;i++) {
			if (sta[i]){
				add_edge(source,i,sta[i]);
				add_edge(i,source,0);
				for (int j=0;j<m;j++) {
					if (i & (1<<j)) {
						add_edge(i,pla(j),INF_INT);
						add_edge(pla(j),i,0);
					}
				}
			}
		}
		for (int i=0;i<m;i++) {
			int x;x=read();
			if (x) {
				add_edge(pla(i),sink,x);
				add_edge(sink,pla(i),0);
			}
		}
		int ans;
		if (sta[0]) {
			ans=0;
		}
		else ans=Dinic(source,sink);
		if (ans>=n) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

