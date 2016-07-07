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
#define root 1,n,1         // segment tree
#define lson l,m,rt<<1     // segment tree
#define rson m+1,r,rt<<1|1 // segment tree
#define BigInteger bign    // For BigInteger
const int MAX_L=2005;// For BigInteger
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e4;
struct Edge{
	int v;
	int w;
};
vector<Edge> g[N];
int vis[N]; 
int d[N];
int T,n;

int spfa(){
	MEM(d,INF);
	CLR(vis);
	vis[n]=1;
	d[n]=0;
	queue<int> q;
	q.push(n);
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=0;i<g[x].size();i++){
			int v=g[x][i].v;
			if (v==x) continue;
			int cost=g[x][i].w;
			if (d[v]>d[x]+cost){
				d[v]=d[x]+cost;
				if (!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return d[1];
} 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> T >> n){
		for (int i=0;i<=n;i++) g[i].clear();
		for (int i=1;i<=T;i++){
			int u,v,w;
			SIII(u,v,w);
//			cout << u <<  ' ' << v << ' ' << w << endl;
			g[u].push_back(Edge{v,w});
			g[v].push_back(Edge{u,w});
		}
		cout << spfa() << endl;
	}
	return 0;
}

