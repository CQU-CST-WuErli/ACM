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

const int N=5e5+10;
const int M=3000;

int n,m,p;
int pnt[N],head[M],nxt[N],cap[N];
int cnt; 
int level[M],iter[M];
char mp[50][50];

void add_edge(int u,int v,int f){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=f;
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
	if (u==t || Flow==0) return Flow;
	int left=Flow;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(cap[i],left));
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
		Max_flow+=dfs(s,t,INF_INT);
	}
	return Max_flow;
}

int id(int i,int j) {
	return (i-1)*m+j;
}

int dir[4][2]={1,0,0,1,0,-1,-1,0};

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m >> p) {
		getchar();
		cnt=0;OFF(head);
		int source=0,sink=2*n*m+1;
		vector<int> ice,fice,lice,wood;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				cin >> mp[i][j];
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (mp[i][j]=='~') continue;
				else if (mp[i][j]=='*') {
					add_edge(source,id(i,j),1);
					add_edge(id(i,j),source,0);
				}
				else if (mp[i][j]=='#') {
					add_edge(id(i,j)+m*n,sink,p);
					add_edge(sink,id(i,j)+m*n,0);
				}
				int w=INF_INT;
				if (mp[i][j]=='.' || mp[i][j]=='*') w=1;
				add_edge(id(i,j),id(i,j)+m*n,w);
				add_edge(id(i,j)+m*n,id(i,j),0);
				for (int k=0;k<4;k++) {
					int x=i+dir[k][0],y=j+dir[k][1];
					if (x<1 || y<1 || x>n || y>m || mp[i][j]=='~') continue; 
					int u=id(i,j);
					int v=id(x,y);
//						if (mp[i][j]=='.') 
					u+=m*n;
					add_edge(u,v,INF_INT);
					add_edge(v,u,0);
				}
			}
		}
		int ans=Dinic(source,sink);
		cout << ans << endl; 
	}
	return 0;
}

