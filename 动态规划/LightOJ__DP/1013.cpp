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

const int N=40;
int len[N][N];
ll dp[N][N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;cin >> T_T;
	getchar();
	for (int kase=1;kase<=T_T;kase++) {
		char s[N],t[N];
		gets(s+1);gets(t+1);
//		puts(s+1);puts(t+1);
		CLR(len);CLR(dp);
		int ls=strlen(s+1),lt=strlen(t+1);
		for (int i=1;i<=ls;i++) {
			for (int j=1;j<=lt;j++) {
				if (s[i]==t[j]) len[i][j]=len[i-1][j-1]+1;
				else len[i][j]=max(len[i-1][j],len[i][j-1]);
			}
		}
		for (int i=0;i<=ls;i++) dp[i][0]=1;
		for (int i=0;i<=lt;i++) dp[0][i]=1;
		for (int i=1;i<=ls;i++) {
			for (int j=1;j<=lt;j++) {
				if (s[i]==t[j]) dp[i][j]+=dp[i-1][j-1];
				else {
					if (len[i][j]==len[i-1][j]) dp[i][j]+=dp[i-1][j];
					if (len[i][j]==len[i][j-1]) dp[i][j]+=dp[i][j-1];
				}
			}
		}
		printf("Case %d: %d %lld\n",kase,ls+lt-len[ls][lt],dp[ls][lt]);
	}
	return 0;
}

