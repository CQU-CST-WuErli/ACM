//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
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
int t;
int n,m;
const int MOD=10000;
int mp[N][N];
int dp[N][N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	while (t--){
		cin >> n >> m;
		CLR(mp);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) cin >> mp[i][j]];
		CLR(dp);
		dp[1][1]=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				for (int x=1;x<=i;x++)
					for (int y=1;y<=j;y++){
						if (x==i && y==j) continue;
						int cnt=mp[x][y];
						if (i-x+j-y<=cnt) dp[i][j]=(dp[i][j]+dp[x][y])%MOD;
					}
			}	
		cout << dp[n][m] << endl;
	}
	return 0;
}
