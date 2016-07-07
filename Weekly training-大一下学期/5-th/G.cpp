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
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m,s,t;
struct Edge{
	int v;
	int a,b,t;
};
vector<Edge> g[305];
int vis[305];
ll dp[305];
typedef pair<ll,int> sta;

ll dijkstra(){
	MEM(dp,INF);
	CLR(vis);
	priority_queue<sta,vector<sta>,greater<sta> > pq;
	dp[s]=0;pq.push(sta(0,s));
	while (!pq.empty()){
		sta x=pq.top();pq.pop();
		int u=x.second;
		vis[u]=1;
		for (int i=0;i<g[u].size();i++){
			Edge &e=g[u][i];
			if (e.a<e.t) continue;
			int lft=dp[u]%(e.a+e.b);
			int tmp;
			if (lft<e.a && e.a-lft>=e.t) tmp=e.t;
			else tmp=e.a+e.b-lft+e.t;
			if (!vis[e.v] && dp[e.v]>dp[u]+tmp){
				dp[e.v]=dp[u]+tmp;
				pq.push(sta(dp[e.v],e.v));
			}
		}
	}
	return dp[t];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n >> m >> s >> t){
		for (int i=1;i<=m;i++){
			int u,v,a,b,T;
			SII(u,v);
			SIII(a,b,T);
			g[u].push_back(Edge{v,a,b,T});
		}
		printf("Case %d: %lld\n",kase++,dijkstra());
		for (int i=0;i<=n;i++) g[i].clear();	
	}
	return 0;
}


