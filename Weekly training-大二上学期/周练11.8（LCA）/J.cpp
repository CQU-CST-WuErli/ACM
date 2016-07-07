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
const int M=1e5+100;

struct Edge{
	int u,v,dis;
	Edge(){}
	Edge(int _,int __,int ___) {
		u=_;v=__;dis=___;
	}
	bool operator < (const Edge& rhs) const {
		return dis<rhs.dis;
	}
};
Edge es[M];
int par[N],rnk[N];
//tree
int pnt[M],nxt[M],head[N],cost[M];
int cnt;
//
int n,m,q;

void add_edge(int u,int v,int w) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cost[cnt++]=w;
}

void init(int n) {
	for (int i=0;i<=n;i++) {
		par[i]=i;
		rnk[i]=0;
	}
	OFF(head);cnt=0;
} 

int find(int x) {
	return par[x]=par[x]==x?x:find(par[x]);
}

bool same(int x,int y) {
	x=find(x);y=find(y);
	return x==y;
}

void unite(int x,int y) {
	x=find(x);y=find(y);
	if (x==y) return ;
	if (rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
	return;
}

void kruskal(int n) {
	sort(es+1,es+1+n);
	for (int i=1;i<=n;i++) {
		Edge &e=es[i];
		if (!same(e.v,e.u)) {
			unite(e.u,e.v);
//			cout << e.u << ' ' << e.v << endl;
			add_edge(e.u,e.v,e.dis);
			add_edge(e.v,e.u,e.dis); 
		}
	}
}

int ans[20][N],p[20][N];
int dep[N];
void dfs(int fa,int u,int d,int w) {
	p[0][u]=fa;
	ans[0][u]=w;
	dep[u]=d;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (v==fa) continue;
		dfs(u,v,d+1,cost[i]);
	} 
}

void process(){
	OFF(p);OFF(dep);OFF(ans);
	dfs(-1,1,0,0);
	for (int i=0;i+1<20;i++) {
		for (int v=1;v<=n;v++) {
			if (p[i][v]==-1) p[i+1][v]=-1;
			else p[i+1][v]=p[i][p[i][v]];
			ans[i+1][v]=max(ans[i][v],ans[i][p[i][v]]);
		}
	}
}

int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	for (int i=0;i<20;i++)
		if (dep[v]-dep[u]>>i&1) v=p[i][v];
	if (u==v) return u;
	for (int i=19;i>=0;i--) {
		if (p[i][u]!=p[i][v]) {
			u=p[i][u];
			v=p[i][v];
		}
	}
	return p[0][u];
}

int query(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	int ret=-1;
	for (int i=19;i>=0;i--) 
		if (dep[v]-dep[u]>>i&1) {
			ret=max(ret,ans[i][v]);
			v=p[i][v];
		}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (SII(n,m)==2) {
		For_UVa;kase++;
		init(max(n,m));
		for (int i=1;i<=m;i++) {
			int u,v,w;
			u=read();v=read();w=read();
			es[i]=Edge(u,v,w);
		}
		kruskal(m);
		q=read();
		process();
		while (q--) {
			int u,v;
			u=read();v=read();
			int LCA=lca(u,v);
//			lookln(LCA);
			printf("%d\n",max(query(u,LCA),query(v,LCA)));
		}
	}
	return 0;
}

