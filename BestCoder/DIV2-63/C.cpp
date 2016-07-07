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
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1100;

int mp[N][N];
int n,m;
ll dp[N][N];
ll flag[N][N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) 
				scanf("%d",&mp[i][j]);
		}
		CLR(dp);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) {
				if (i==1) {
					if (j%2) dp[i][j]=dp[i][j-1];
					else dp[i][j]=dp[i][j-1]+mp[i][j]*mp[i][j-1];
				}
				else if (j==1) {
					if (i%2) dp[i][j]=dp[i-1][j];
					else dp[i][j]=dp[i-1][j]+mp[i-1][j]*mp[i][j];
				}
				else {
					int step=i+j-1;
					if (step%2) {
						dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
					}
					else {
						dp[i][j]=min(dp[i-1][j]+mp[i-1][j]*mp[i][j],dp[i][j-1]+mp[i][j-1]*mp[i][j]);
					}
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}

