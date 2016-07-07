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

const int N=250;
int n,T,m1,m2;
int dp[N][N];
int t[N],d[N],e[N];
int has_train[N][N][2];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && n) {
		cin >> T;
		for (int i=1;i<n;i++) cin >> t[i];
		cin >> m1;
		for (int i=1;i<=m1;i++) cin >> d[i];
		cin >> m2;
		for (int i=1;i<=m2;i++) cin >> e[i];
		CLR(has_train);
		for (int i=1;i<=m1;i++) {
			int tt=d[i];
			for (int j=1;j<=n;j++) {
				if (tt<=T) {
					has_train[tt][j][0]=1;
					tt+=t[j];
				} 
				else break;
			}
		}
		for (int i=1;i<=m2;i++) {
			int tt=e[i];
			for (int j=n;j>=1;j--) {
				if (tt<=T) {
					has_train[tt][j][1]=1;
					tt+=t[j-1];
				}
				else break;
			}
		}
		for (int i=1;i<n;i++) dp[T][i]=INF_INT;
		dp[T][n]=0;
		for (int i=T-1;i>=0;i--) {
			for (int j=1;j<=n;j++) {
				dp[i][j]=dp[i+1][j]+1;
				if (i+t[j]<=T && has_train[i][j][0] && j<n)
					dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
				if (i+t[j-1]<=T && has_train[i][j][1] && j>1)
					dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
			}
		}
		cout << "Case Number " << kase++ << ": ";
		if (dp[0][1]>=INF_INT) cout << "impossible\n";
		else cout << dp[0][1] << endl;
	}
	return 0;
}

