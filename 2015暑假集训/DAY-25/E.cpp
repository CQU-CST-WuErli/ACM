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
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1010;
int t[N];
int n,L,C;
int c[N];
int sum[N];
int dp[N][N];

int DI(int x){
	if (x>=1 && x<=10) return -C;
	else if (x==0) return 0;
	else return (x-10)*(x-10);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (SI(n)==1 && n){
		For_UVa;
		printf("Case %d:\n",kase++);
		SII(L,C);
		int cnt=1;int tmp=0;
		for (int i=1;i<=n;i++) {
			scanf("%d",t+i);
			tmp+=t[i];
			sum[i]=(i==1?t[i]:sum[i-1]+t[i]);
			if (tmp>L){
				c[cnt++]=i-1;
				tmp=t[i];
			} 
		}
		printf("Minimum number of lectures: %d\n",cnt);
		c[cnt]=n;
		MEM(dp,0x3f3f3f3f);
		for (int i=0;i<=cnt;i++) dp[i][0]=0;
		for (int i=1;i<=cnt;i++){
			for (int j=i;j<=c[i];j++){
				for (int k=i-1;k<=j;k++){
					if (sum[j]-sum[k]<=L){
						dp[i][j]=min(dp[i][j],dp[i-1][k]+DI(L-sum[j]+sum[k]));
					}
				}
			}
		}
		printf("Total dissatisfaction index: %d\n",dp[cnt][n]);
	}
	return 0;
}


