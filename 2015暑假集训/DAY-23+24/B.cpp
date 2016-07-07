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
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=50;
int n;
int pile[5][N];
int dp[N][N][N][N];   // 从每个里面选几个 
int pot[5];
int vis[N];

int dfs(int cnt,int a,int b,int c,int d){
	int &ret=dp[a][b][c][d];
	if (ret>0) return ret;
	if (cnt==5) return 0;
	for (int i=0;i<4;i++){
		int top=pile[i][pot[i]];
		if (vis[top]){
			if (pot[i]==n) continue;
			vis[top]=0;	
			pot[i]++;
			ret=max(ret,dfs(cnt-1,pot[0],pot[1],pot[2],pot[3])+1);
			pot[i]--;
			vis[top]=1;
		}
		else {
			if (pot[i]==n) continue;
			vis[top]=1;
			pot[i]++;
			ret=max(ret,dfs(cnt+1,pot[0],pot[1],pot[2],pot[3]));
			vis[top]=0;
			pot[i]--;
		}
	}
	return ret;
}
 
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n && n){
		CLR(dp);
		CLR(vis);
		for (int i=0;i<n;i++)
			for (int j=0;j<4;j++){
				scanf("%d",&pile[j][i]);
			}	
		cout << dfs(0,0,0,0,0) << endl;
	}
	return 0;
}


