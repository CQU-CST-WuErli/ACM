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

const int N=20010;

int n,m;
int ans;
vector<int> T[N],G[N];
int vis[N],dp[N];

void dfs(int f,int u) {
	vis[u]=1;
	for (int i=0;i<T[u].size();i++) {
		int v=T[u][i];
		if (v==f || vis[v]) continue;
		dfs(u,v);
		dp[u]+=dp[v]-1;
	}
	ans=min(ans,dp[u]);
	for (int i=0;i<G[u].size();i++) {
		int v=G[u][i];
		if (vis[v]) dp[v]--;
	}
	vis[u]=0;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	for (int kase=scanf("%d",&_);kase<=_;kase++) {
		SII(n,m);CLR(dp);CLR(vis);ans=INF_INT;
		for (int i=1;i<=n;i++) {
			T[i].clear();
			G[i].clear();
		}
		for (int i=1;i<n;i++) {
			int u,v;
			SII(u,v);
			T[u].push_back(v);
			T[v].push_back(u);
			dp[v]++;dp[u]++;
		}
		for (int i=n;i<=m;i++) {
			int u,v;
			SII(u,v);
			G[u].push_back(v);
			G[v].push_back(u);
			dp[v]++;dp[u]++;
		}
		dfs(-1,1);
		cout << "Case #" << kase << ": " << ans << endl;
	}
	return 0;
}

