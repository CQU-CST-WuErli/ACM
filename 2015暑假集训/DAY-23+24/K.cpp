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
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=5000;
int t;
int n,k;
ll a[N];
ll dp[N][N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	while (t--){
		cin >> k >> n;
		for (int i=1;i<=n;i++) scanf("%d",a+i);
		k+=8;
		reverse(a+1,a+1+n);     // 大的在前面没有后效性 
		MEM(dp,0x3f3f3f3f);
		for (int i=1;i<=n;i++) dp[0][i]=0;
		for (int i=1;i<=k;i++)    // 用j个拼成i对s 
			for (int j=3*i;j<=n;j++){
				ll &ans=dp[i][j];
				ans=min(ans,dp[i][j-1]);
				ans=min(ans,dp[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]));
			}
		cout << dp[k][n] << endl;
	}
	return 0;
}


