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
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=300;
int a[N][N];
int dp[N][N];
int n;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	int kase=1;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=i;j++) {
				scanf("%d",&a[i][j]);
//				cout << a[i][j] << ' ';
			}
//			cout << endl;;
		}
		for (int i=n+1;i<=2*n-1;i++){
			for (int j=1;j<=2*n-i;j++) {
				scanf("%d",&a[i][j]);
//				cout << a[i][j] << ' ';
			}
//			cout << endl;
		}
		CLR(dp);
		dp[1][1]=a[1][1];
		for (int i=2;i<=n;i++) {
			for (int j=1;j<=i;j++){
				if (j==1) dp[i][j]=dp[i-1][j]+a[i][j];
				else if (j==i) dp[i][j]=dp[i-1][j-1]+a[i][j];
				else {
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
				}
			}
		}
		for (int i=n+1;i<=2*n-1;i++) {
			for (int j=1;j<=2*n-i;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+a[i][j];
			}
		}
		printf("Case %d: %d\n",kase,dp[2*n-1][1]);
	}
	return 0;
}

