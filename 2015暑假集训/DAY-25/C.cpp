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
#define BUG(x) cout << "I am in line" << x << endl
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
const int N=1600;
int n;
vector<int> g[1600];
int dp[N][2];
// dp[i][0] yes for itself
// dp[i][1] no for itself

void dfs(int par,int u){
	dp[u][0]=1;dp[u][1]=0;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==par) continue;
		dfs(u,v);
		dp[u][0]+=min(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
	return ;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1){
		for (int i=1;i<=n;i++){
			int u,v,x;
			scanf("%d:(%d)",&u,&x);
			for (int j=1;j<=x;j++) {
				scanf("%d",&v);
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		OFF(dp);
		dfs(-1,0);
		cout << min(dp[0][0],dp[0][1]) << endl;
		for (int i=0;i<=n;i++) g[i].clear();
	}
	return 0;
}


