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

int sum[110][110];
int len[110];
int n,m;

int dp[110][10010];
int Max[110][110];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2) {
		CLR(sum);
		rep(i,1,n) {
			SI(len[i]);
			rep(j,1,len[i]) SI(sum[i][j]);
		}
		rep(i,1,n) {
			rep(j,2,len[i]) sum[i][j]+=sum[i][j-1];
		}
		CLR(Max);
		rep(i,1,n) {
			rep(j,1,len[i]) {
				rep(k,0,j) {
					Max[i][j]=max(Max[i][j],sum[i][k]+sum[i][len[i]]-sum[i][len[i]-j+k]);
				}
			}
		}
//		rep(i,1,n) {
//			rep(j,1,len[i]) cout << Max[i][j] << ' ';
//			cout << endl;
//		}
		int ans=0;
		CLR(dp); 
		for (int i=1;i<=n;i++) {
			for (int j=m;j>=0;j--) {
				for (int k=0;k<=len[i];k++) {
					if (k<=j) {
						dp[i][j]=max(dp[i][j],dp[i-1][j-k]+Max[i][k]);
					}
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}

