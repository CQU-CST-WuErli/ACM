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

const int N=1e5+100;
int w[N],n;
int ans[N];
int up[N],down[N],minv[N],maxv[N];
int vis[N],par[N];
int cnt;

struct Edge{
	int v,nxt;
}E[N];
int headE[N];

void add_edge(int u,int v) {
	E[cnt]=(Edge) {v,headE[u]};
	headE[u]=cnt++;
	E[cnt]=(Edge) {u,headE[v]};
	headE[v]=cnt++;
} 

struct Query {
	int u,v,nxt;
}Q[N];
int headQ[N];

void add_query(int u,int v) {
	Q[cnt]=(Query) {u,v,headQ[u]};
	headQ[u]=cnt++;
	Q[cnt]=(Query) {v,u,headQ[v]};
	headQ[v]=cnt++;
}

struct LCA{
	int id,nxt;
}L[N];
int headL[N];

void add_lca(int lca,int id) {
	L[cnt]=(LCA) {id,headL[lca]};
	headL[lca]=cnt++;
}

int find(int u) {
	if (par[u]==u) return u;
	int f=par[u];
	par[u]=find(par[u]);
	up[u]=max(max(up[u],up[f]),maxv[f]-minv[u]);
	down[u]=max(max(down[u],down[f]),maxv[u]-minv[f]);
	maxv[u]=max(maxv[u],maxv[f]);
	minv[u]=min(minv[u],minv[f]);
	return par[u];
}

void tarjan_lca(int u) {
	vis[u]=1;
	par[u]=u;
	for (int i=headE[u];~i;i=E[i].nxt) {
		int v=E[i].v;
		if (vis[v]) continue;
		tarjan_lca(v);
		par[v]=u; 
	}
	for (int i=headQ[u];~i;i=Q[i].nxt) {
		int v=Q[i].v;
		if(!vis[v]) continue;
		int lca=find(v);
		add_lca(lca,i); 
	}
	for (int i=headL[u];~i;i=L[i].nxt) {
		int id=L[i].id;
		if (id&1) id^=1;
		int u=Q[id].u,v=Q[id].v;
		find(u);find(v);
		ans[id>>1]=max(max(up[u],down[v]),maxv[v]-minv[u]);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		for (int i=1;i<=n;i++) {
			scanf("%d",w+i);
			minv[i]=maxv[i]=w[i];
			up[i]=down[i]=0;
		}
		cnt=0;OFF(headE);
		for (int i=1;i<n;i++) {
			int u,v;SII(u,v);
			add_edge(u,v);
		}
		cnt=0;OFF(headQ);
		int q;SI(q);
		for (int i=1;i<=q;i++) {
			int u,v;
			SII(u,v);
			add_query(u,v);
		} 
		cnt=0;OFF(headL);
		CLR(vis);
		tarjan_lca(1);
		for (int i=1;i<=q;i++) printf("%d\n",ans[i-1]);
	} 
	return 0;
}

