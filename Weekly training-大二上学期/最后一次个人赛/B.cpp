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
const int MOD=1e8+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,k;
int dp[1100][1100*2][2];

void init(){
	CLR(dp);
	dp[1][1][0]=1;
	dp[1][1][1]=0;
	dp[1][2][0]=0;
	dp[1][2][1]=1;
	for (int i=2;i<=1000;i++) {
		for (int j=1;j<=2*i;j++) {
			dp[i][j][0]=(dp[i-1][j][0]+2*dp[i-1][j][1]+dp[i-1][j-1][0]+dp[i-1][j-1][1])%MOD;  
            if(j>=2)  
                dp[i][j][1]=(dp[i-1][j][1]+2*dp[i-1][j-1][0]+2*dp[i-1][j-1][1]+dp[i-1][j-2][0]+dp[i-1][j-2][1])%MOD;  
            else  
                dp[i][j][1]=(2*dp[i-1][j-1][0]+dp[i-1][j][1]+2*dp[i-1][j-1][1])%MOD; 
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;SI(_);
	init();
	while (_--){
		cin >> n >> k;
		cout << (dp[n][k][1]+dp[n][k][0])%MOD << endl; 
	}
	return 0;
}

