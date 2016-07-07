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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <functional>
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

const int N=1e5+10;
int pnt[N],nxt[N],head[N],pre[N],cap[N],cost[N];
int cnt;
int n,m,k;
void add_edge(int u,int v,int c){
	pnt[cnt]=v;pre[cnt]=u;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=c;
//	lookln(w);
}

map<string,int> mp;
int ID_start;
int device[1000],target[1000],from[1000],to[1000];
int get_id(char *s){
	if (!mp.count(s)) mp[s]=ID_start++;
	return mp[s];
}

int level[1000],iter[1000];
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
		Max_flow+=dfs(s,t,INF);
	}
	return Max_flow;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;cin >> T_T;
	int kase=1;
	while (T_T--){
		For_UVa;
		char s[30];
		cnt=0;OFF(head);ID_start=1;mp.clear();	
		cin >> n;
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			target[i]=get_id(s);
		}
		SI(m);
		for (int i=1;i<=m;i++){
			scanf("%s",s);
			scanf("%s",s);
			device[i]=get_id(s);
		}
		SI(k);
		for (int i=1;i<=k;i++){
			scanf("%s",s);
			from[i]=get_id(s);
			scanf("%s",s);
			to[i]=get_id(s);
		}
		int source=0,sink=mp.size()+2;
		for (int i=1;i<=n;i++) {
			add_edge(target[i],sink,1);
			add_edge(sink,target[i],0);
		}
		for (int i=1;i<=m;i++){
			add_edge(source,device[i],1);
			add_edge(device[i],source,0);
		}
		for (int i=1;i<=k;i++){
			add_edge(from[i],to[i],INF);
			add_edge(to[i],from[i],0);
		}
		int ans=Dinic(source,sink);
		printf("%d\n",m-ans);
		kase++;
	}
	return 0;
}
