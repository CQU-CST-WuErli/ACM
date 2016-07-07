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

int per[40];
int dp[40][110];
int n,m;

bool check(int x){
	int cnt=0;
	for (int i=1;i<=m;i++)
		cnt+=per[i]/x;
	return cnt<n;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m && (n || m)){
		for (int i=1;i<=m;i++) scanf("%d",per+i);
		int l=0,r=1010;
		while (l+1<r){
			int mid=(l+r)/2;
			if (check(mid)) r=mid;
			else l=mid;
			if (mid==0) break;
		}
		if (l==0) {
			cout << "0 0\n";
			continue;
		}
		MEM(dp,0x3f);
		dp[0][0]=0;
		// 第i个人守卫j个仓库 
		for (int i=1;i<=m;i++){
			for (int j=0;j<=n;j++){
				dp[i][j]=dp[i-1][j];
				for (int k=0;k<=per[i]/l;k++){
					if (k>j) break;
					dp[i][j]=min(dp[i][j],dp[i-1][j-k]+per[i]);
				}
					
			}
		}		
		cout << l << ' ' << dp[m][n] << endl;
	}
	return 0;
}


