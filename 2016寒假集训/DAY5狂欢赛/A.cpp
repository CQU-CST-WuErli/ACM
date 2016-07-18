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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int a,b;
int h[202]; 
int dp[202][40005][2];
int tot[202];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (scanf("%d",&n)==1) {
		scanf("%d%d",&a,&b);
		for (int i=1;i<=n;i++) {
			scanf("%d",h+i);
			tot[i]=i==1?h[i]:tot[i-1]+h[i];
		}
		MEM(dp,INF_INT);
		dp[0][0][0]=dp[0][0][1]=0;
		int ans=INF_INT;
		rep(i,1,n) {
			for (int j=min(tot[i],a);j>=0;j--) {
            	if(tot[i]-j<=b){  // b is enough
                	if(tot[i]-j>=h[i])  // paint b
                  	  	dp[i][j][1]=min(dp[i-1][j][1],dp[i-1][j][0]+min(h[i],h[i-1]));  
              		if(j>=h[i])  // paint a
                    	dp[i][j][0]=min(dp[i-1][j-h[i]][0],dp[i-1][j-h[i]][1]+min(h[i],h[i-1]));  
            	}
			}
		}
		for (int i=0;i<=min(tot[n],a);i++) ans=min(ans,min(dp[n][i][0],dp[n][i][1]));
		if (ans>=INF_INT) ans=-1;
		cout << ans << endl;
	}
	return 0;
}
