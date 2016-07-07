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

const int N=110;
int mp[N][N];
int dp[N][N];
int n,k;
int dir[4][2]={1,0,0,1,-1,0,0,-1};

int dfs(int x,int y){
	int Max=0;
	if (dp[x][y]!=-1) return dp[x][y];
	for (int i=0;i<4;i++){
		for (int j=1;j<=k;j++){
			int tx=x+dir[i][0]*j,ty=y+dir[i][1]*j;
			if (tx>=0 && tx<n && ty>=0 && ty<n && mp[tx][ty]>mp[x][y]){
				Max=max(Max,dfs(tx,ty));
			}
		}
	}
	return dp[x][y]=Max+mp[x][y];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> k){
		if (n==-1 && k==-1) break;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) scanf("%d",&mp[i][j]);
		OFF(dp);
		cout << dfs(0,0) << endl;
	}
	return 0;
}


