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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=1e4+10;

int n;
int dp[N][N][2];
int pos[N],t[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		for (int i=1;i<=n;i++) scanf("%d%d",pos+i,t+i);
		for (int i=n;i>=0;i--){
			for (int j=i+1;j<=n;j++){
				dp[i][j][0]=dp[i][j][1]=INF;
				dp[i][j][0]=min(dp[i+1][j][0]+pos[i+1]-pos[i],dp[i+1][j][1]+pos[j]-pos[i]);
				if (dp[i][j][0]>=t[i])
					dp[i][j][0]=INF;
				dp[i][j][1]=min(dp[i][j-1][0]+pos[j]-pos[i],dp[i][j-1][1]+pos[j]-pos[j-1]);
				if (dp[i][j][1]>=t[j])
					dp[i][j][1]=INF;		
			}
		}
		int ans=min(dp[1][n][0],dp[1][n][1]);
		if (ans>=INF) cout << "No solution\n";
		else cout << ans << endl;
	}
	return 0;
}


