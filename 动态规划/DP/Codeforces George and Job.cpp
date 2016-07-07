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
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=5010;
int p[N];
ll dp[N][N];
int m,n,k;
ll sum[N]; 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m >> k) {
		for (int i=1;i<=n;i++) scanf("%d",p+i);
		for (int i=1;i<=n;i++) sum[i]=(i==1?p[i]:sum[i-1]+p[i]);
		CLR(dp);
		// dp[i][j] 前i个选j对
		// 选或者不选 
//		for (int i=m;i<=n;i++) {
//			for (int j=1;j*m<=i;j++) {
//				dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
//			}
//		}
//		cout << dp[n][k] << endl;
		for (int i=1;i<=k;i++) {
			for (int j=m;j<=n;j++) {
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+sum[j]-sum[j-m]);
			}
		}
		cout << dp[k][n] << endl;
	}
	return 0;
}

