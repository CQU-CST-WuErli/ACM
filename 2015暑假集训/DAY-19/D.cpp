//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=1e4+20;

int n;
vector<int> g[N]; 
int dp[N][3];   
// dp[i][0] 表示本身是服务器  
// dp[i][1] 表示自己不是但父亲是服务器
// dp[i][2] 表示自己不是，父亲也不是，那么只有根节点是 

void dfs(int par,int u){
	dp[u][0]=1;dp[u][1]=0;dp[u][2]=100000;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==par) continue;
		dfs(u,v);
		dp[u][0]+=min(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][2];
	}
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==par) continue;
		dp[u][2]=min(dp[u][2],dp[u][1]-dp[v][2]+dp[v][0]);
	}
	return ;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		if (n==-1) break;
		for (int i=0;i<n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		OFF(dp);
		dfs(0,1);
		cout << min(dp[1][0],dp[1][2]) << endl;    // 根节点没有父亲 
		for (int i=0;i<=n;i++) g[i].clear();
		cin >> n;
	}
	return 0;
}


