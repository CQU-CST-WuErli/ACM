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
#include <assert.h>
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

const int N=5e5+10;
int pnt[N],nxt[N],head[N],cap[N],cost[N],pre[N];
int cnt;
int n,m;
char mp[200][200];

void add_edge(int u,int v,int c,int w){
	pnt[cnt]=v;pre[cnt]=u;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt]=c;cost[cnt++]=w;
}

int ID(int i,int j){
	return (i-1)*n+j;
}

void get_ID(int pos,int &x,int &y){
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (((i-1)*n+j)==pos) {
		x=i;y=j;return;
	}
}

int dis(int s,int t){
	int x1,x2,y1,y2;
	get_ID(s,x1,y1);
	get_ID(t,x2,y2);
	return abs(x1-x2)+abs(y1-y2);
}

int a[N],d[N],p[N];
int vis[N];
bool spfa(int s,int t,int &f,int &Cost){
	CLR(vis);
	for (int i=s;i<=t;i++) d[i]=INF_INT;
	queue<int> q;
	q.push(s);
	a[s]=INF_INT;
	d[s]=0;
	vis[s]=1;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (d[v]>d[x]+cost[i] && cap[i]>0){
				d[v]=d[x]+cost[i];
				a[v]=min(a[x],cap[i]);
				p[v]=i;
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
				} 
			}
		}
	}
	if (d[t]==INF_INT) return false;
	f+=a[t];
	Cost+=d[t]*a[t];
	for (int u=t;u!=s;u=pre[p[u]]){
		cap[p[u]]-=a[t];
		cap[p[u]^1]+=a[t];
	}
	return true;
}

int Max_flow_cost(int s,int t){
	int f=0,Cost=0;
	while (spfa(s,t,f,Cost)) ;
	return Cost;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m && (n || m)){
		OFF(head);cnt=0;
		getchar();
		set<int> H,M;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			cin >> mp[i][j];
			if (mp[i][j]=='H') H.insert(ID(i,j));
			else if (mp[i][j]=='m') M.insert(ID(i,j));
		}
		int source=0,sink=m*n+1;
		set<int>::iterator it,jt;
		for (it=M.begin();it!=M.end();it++) {
			add_edge(source,*it,1,0);
			add_edge(*it,source,0,0);
		}
		for (it=H.begin();it!=H.end();it++) {
			add_edge(*it,sink,1,0);
			add_edge(sink,*it,0,0);
		}
		for (it=M.begin();it!=M.end();it++) {
			for (jt=H.begin();jt!=H.end();jt++) {
				add_edge(*it,*jt,1,dis(*it,*jt));
				add_edge(*jt,*it,0,-dis(*it,*jt)); 
//				cout << *it << ' ' << *jt << ' ' << dis(*it,*jt) << endl;
			}
		}
		cout << Max_flow_cost(source,sink) << endl;
	}
	 
	return 0;
}

