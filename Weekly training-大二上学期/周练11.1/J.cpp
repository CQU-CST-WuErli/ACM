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

int mp[20][20];
int has[20];
ll dp[20][20];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	while (cin >> s) {
		CLR(mp);CLR(has);CLR(dp); 
		int n=s.size();
		for (int i=0;i<n;i++) {
			if (s[i]!='?') {
				int tmp;
				if (s[i]>='0' && s[i]<='9') tmp=s[i]-'0';
				else if (s[i]>='A' && s[i]<='F') tmp=s[i]-'A'+10;
				mp[i+1][tmp]=1;
				has[i+1]=tmp;
			}			
		}
		ll ans=0;
		if (!has[1]) {
			for (int j=1;j<=n;j++) dp[1][j]=1;
		}
		else dp[1][has[1]]=1;
		for (int i=1;i<=n;i++) {
			if (has[i]) {
				for (int j=1;j<has[i]-1;j++) dp[i][has[i]]+=dp[i-1][j];
				for (int j=has[i]+2;j<=n;j++) dp[i][has[i]]+=dp[i-1][j];
			}
			else {
				for (int j=1;j<=n;j++) {
					for (int k=1;k<j-1;k++) dp[i][j]+=dp[i-1][k];
					for (int k=j+2;k<=n;k++) dp[i][j]+=dp[i-1][k]; 
				}
			}
		}
		for (int i=1;i<=n;i++) ans+=dp[n][i];
		cout << ans << endl;
	}
	return 0;
}

