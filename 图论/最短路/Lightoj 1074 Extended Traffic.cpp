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

const int N=250;
int n,m,q;
struct Edge{
	int v;
	int w;
};
vector<Edge> g[N];
int a[N];
int counter[N];
int vis[N];
int d[N];
void spfa(){
	CLR(vis);CLR(counter);
	MEM(d,INF_INT);
	queue<int> q;
	q.push(1);
	vis[1]=1;
	d[1]=0;
	counter[1]=1;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=0;i<g[x].size();i++){
			int v=g[x][i].v;
			int w=g[x][i].w;
			if (counter[v]>n) continue;
			if (d[v]>d[x]+w){
				d[v]=d[x]+w;
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
					counter[v]++;
				}
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	for (int kase=scanf("%d",&_);kase<=_;kase++){
		for (int i=0;i<=n;i++) g[i].clear();
		SI(n);
		for (int i=1;i<=n;i++) scanf("%d",a+i);
		SI(m);
		for (int i=1;i<=m;i++){
			int u,v;
			SII(u,v);
			int w=(a[v]-a[u])*(a[v]-a[u])*(a[v]-a[u]);
			g[u].push_back(Edge{v,w});
		}
		spfa();
		SI(q);
		printf("Case %d:\n",kase);
		while (q--){
			int v;
			SI(v);
			if (counter[v]>n || d[v]>=INF_INT || d[v]<3) puts("?");
			else cout << d[v] << endl; 
		}
	}
	return 0;
}

