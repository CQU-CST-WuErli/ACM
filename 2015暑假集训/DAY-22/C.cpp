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
const int N=18;

int t;
int n;
int dp[1<<N];
int mp[N][N];

int dfs(int s,int cnt){
	int &ans=dp[s];
	if (ans>=0) return ans;
	if (cnt==n) return 0;
	for (int i=0;i<n;i++) if (!(s>>i&1)){
		ans=max(ans,dfs(s|(1<<i),cnt+1)+mp[cnt][i]);
	}
	return dp[s]=ans;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	scanf("%d",&t);
	for (int kase=1;kase<=t;kase++){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) scanf("%d",&mp[i][j]);
		OFF(dp);
		printf("Case %d: ",kase);
		printf("%d\n",dfs(0,0));
	}
	return 0;
}


