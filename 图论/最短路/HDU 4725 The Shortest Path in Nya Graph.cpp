
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

const int N=(1e5+10)*20;
int pnt[N],nxt[N],head[100010*2],cost[N];
int cnt=0;

void add_edge(int u,int v,int c){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cost[cnt++]=c;
}
int n,m,c;
int lay[100010*2];
int vis[100010*2],d[100010*2];

int spfa(){
	CLR(vis);
	MEM(d,INF_INT);
	queue<int> q;
	q.push(1);
	vis[1]=1;
	d[1]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
//			if (v==x) continue;
			if (d[v]>d[x]+cost[i]){
				d[v]=d[x]+cost[i];
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return d[n];
}

int is[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	// 1->n nodes  n+1->n+n layer 
	int _;
	for (int kase=scanf("%d",&_);kase<=_;kase++){
		CLR(is);cnt=0;OFF(head);
		SIII(n,m,c);
		for (int i=1;i<=n;i++){
			int x;SI(x);x+=n;
			lay[i]=x;
			is[x]=1;
		}
		for (int i=n+1;i<n+n;i++){
			if (is[i] && is[i+1]) {
				add_edge(i,i+1,c);
				add_edge(i+1,i,c);
			}
		}
		for (int i=1;i<=n;i++){
			add_edge(lay[i],i,0);
			if (lay[i]>n+1) add_edge(i,lay[i]-1,c);
			if (lay[i]<n+n) add_edge(i,lay[i]+1,c);
		}
		for (int i=1;i<=m;i++){
			int u,w,v;
			SIII(u,v,w);
			add_edge(u,v,w);
			add_edge(v,u,w); 
		}
		printf("Case #%d: ",kase);
		int ans=spfa();
		if (ans>=INF_INT) cout << "-1\n";
		else cout << ans << endl;
	}
	return 0;
}

