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

int dp[1000010];
int num[1000010];
int w;
int cost[110];
int n;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	cin >> T_T;
	while (T_T--) {
		int n;
		cin >> w >> n;
		int sum=0;
		for (int i=1;i<=n;i++) {
			cin >> cost[i];
			sum+=cost[i];
		}
		sum-=w;
		CLR(num);CLR(dp);
		for (int i=1;i<=n;i++) {
			for (int j=sum;j>=cost[i];j--) {
				if (dp[j]<=dp[j-cost[i]]+cost[i]) {
					if (dp[j]==dp[j-cost[i]]+cost[i]) 
						num[j]=max(num[j],num[j-cost[i]]+1);
					else num[j]=num[j-cost[i]]+1;
					dp[j]=dp[j-cost[i]]+cost[i];
				}
			}
		}
//		cout << dp[sum] << ' ' << num[sum] << endl;
		cout << sum+w-dp[sum] << ' ' << n-num[sum] << endl;
	}
	return 0;
}

