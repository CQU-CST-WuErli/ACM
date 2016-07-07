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

const int N=110;
int n,m,k;
int cost[N];
double value[N];
double dp[30][60][30][N];
// i天第j个做了s次剩t钱


void print(double s,int cnt,int Cost,int pre){
	if(cnt<=0)return;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(dp[cnt][i][j][Cost]==s && i!=pre){
				if(j>=1)print(s-1.5*value[i],cnt-j-1,Cost-(j+1)*cost[i],i);
				else print(s-value[i],cnt-1,Cost-cost[i],i);
				for(int p=0;p<=j;p++){
					printf("%d ",i);
				}
				return;
			}
		}
	}
	return;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> k >> n >> m && (n+m+k)) {
		for (int i=1;i<=n;i++) cin >> cost[i] >> value[i];
		CLR(dp);
		for (int i=1;i<=n;i++) dp[1][i][0][cost[i]]=value[i]; 
		for (int i=2;i<=k;i++) {
			for (int j=1;j<=n;j++) {
				for(int s=m;s>=cost[j];s--){
					for(int t=1;t<=k;t++){
						if(t==1 && dp[i-1][j][t-1][s-cost[j]]) dp[i][j][t][s]=max(dp[i][j][t][s],dp[i-1][j][t-1][s-cost[j]]+value[j]*1.0/2);
						else dp[i][j][t][s]=max(dp[i][j][t][s],dp[i-1][j][t-1][s-cost[j]]);
					}
					for(int t=1;t<=n;t++){
						if(j!=t){
							for(int cnt=0;cnt<=k;cnt++){
								if(dp[i-1][t][cnt][s-cost[j]])dp[i][j][0][s]=max(dp[i][j][0][s],dp[i-1][t][cnt][s-cost[j]]+value[j]);
							}
						}
						//printf("%d %d %d %d %lf\n",i,j,0,s,dp[i][j][0][s]);
					}
				}
			}
		}
		double ans=0.00;
		for(int i=1;i<=n;i++) for(int j=0;j<=m;j++) for(int cnt=0;cnt<=k;cnt++)
			ans=max(ans,dp[k][i][cnt][j]);
		int mincost=INF_INT;
		for(int j=0;j<=m;j++) for(int i=1;i<=n;i++) for(int cnt=0;cnt<=k;cnt++) if(dp[k][i][cnt][j]==ans)
			mincost = min(mincost,j);
		printf("%.1lf\n",ans);
		if (ans!=0.0) print(ans,k,mincost,-1);
		puts(""); 
	}
	return 0;
}

