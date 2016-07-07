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
const int N=1e5+10;
int n,t;
vector<int> boss[N]; 
int dp[N];

int dfs(int u){
	if (dp[u]!=-1) return dp[u];
	if (!boss[u].size()) return dp[u]=1;
	vector<int> son;
	for (int i=0;i<boss[u].size();i++){
		son.push_back(dfs(boss[u][i]));
	}
	sort(ALL(son));
	int c=(boss[u].size()*t-1)/100+1;     // 这里就是几个人就可以，有一个向上取整的方法 
	int tmp=0;
	for (int i=0;i<c;i++)  tmp+=son[i];
	return dp[u]=tmp;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> t && (n ||t )){
		for (int i=1;i<=n;i++){
			int x;
			cin >> x;
			boss[x].push_back(i);	
		}
		OFF(dp);
		dfs(0);
		cout << dp[0] << endl;
		for (int i=0;i<=n;i++) boss[i].clear();
	}
	return 0;
}


