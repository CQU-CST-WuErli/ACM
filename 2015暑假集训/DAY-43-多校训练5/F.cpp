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
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,k; 
vector<int> g[50010];
ll ans;
ll dp[50010][510];

void dfs(int f,int u){
	dp[u][0]=1;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==f) continue;
		dfs(u,v);
		for (int j=0;j<k;j++) ans+=dp[v][j]*dp[u][k-j-1];
		for (int j=1;j<=k;j++) dp[u][j]+=dp[v][j-1];
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> k){
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=n-1;i++) {
			int u,v;
			SII(u,v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=0;
		CLR(dp);
		dfs(-1,1);
		cout << ans << endl;
	} 
	return 0;
}

