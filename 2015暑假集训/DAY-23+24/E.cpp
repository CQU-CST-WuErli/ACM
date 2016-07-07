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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=100;
string s,t;
int dp[N][N];
ll num[N][N];
int T;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> T;
	getchar();
	for (int kase=1;kase<=T;kase++){
		getline(cin,s);
		getline(cin,t); 
		int ls=s.size(),lt=t.size();
		CLR(dp);
		for (int i=0;i<=ls;i++) num[i][0]=1;
		for (int j=0;j<=lt;j++) num[0][j]=1;
		// µ¥¶ÀÒ»¸ö 
		for (int i=1;i<=ls;i++)
			for (int j=1;j<=lt;j++){
				if(s[i-1]==t[j-1]) {
					dp[i][j]=dp[i-1][j-1]+1;
					num[i][j]=num[i-1][j-1];
				}
				else {
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					if (dp[i-1][j]>dp[i][j-1])
						num[i][j]=num[i-1][j];
					else if (dp[i-1][j]<dp[i][j-1])
						num[i][j]=num[i][j-1];
					else num[i][j]=num[i-1][j]+num[i][j-1];
				}
			}
//		cout << ls+lt-dp[ls-1][lt-1] << endl;
//		cout << num[ls][lt] << endl;
		printf("Case #%d: %d %lld\n",kase,ls+lt-dp[ls][lt],num[ls][lt]);
	}	
	return 0;
}


