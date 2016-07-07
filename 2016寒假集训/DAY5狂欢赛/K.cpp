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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100;
int a[N];
int n;
int dp[N];
int cnt; 
int prime[N],is_prime[N];
vector<int> fac[N];

void get_prime() {
	CLR(is_prime);
	for (int i=2;i<N;i++) if (!is_prime[i]) {
		for (int j=i+i;j<N;j+=i) is_prime[j]=1;
	}
	cnt=0;
	for (int i=2;i<N;i++) if (!is_prime[i]) prime[cnt++]=i;
}

void FTA(int x,int i) {
	for (int j=0;j<cnt;j++) {
		int p=prime[j];
		if (p>x) break;
		if (x%p==0) {
			fac[i].push_back(p);
			while (x%p==0) x/=p;
		}
		if (x==1) break;
	}
	if (x>1) fac[i].push_back(x);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	get_prime();
	while (cin >> n ) {
		for (int i=1;i<=n;i++) {
			scanf("%d",a+i);
			fac[i].clear();
			FTA(a[i],i);
		}
		CLR(dp);
		int ans=1;
		for (int i=1;i<=n;i++) {
			if (a[i]==1) continue;
			int tt=0;
			for (int j=0;j<fac[i].size();j++) {
				int tmp=fac[i][j];
//				cout << tmp << ' ';
				tt=max(tt,dp[tmp]+1);
			}
			for (int j=0;j<fac[i].size();j++) {
				int tmp=fac[i][j];
				dp[tmp]=tt;
			}
			ans=max(ans,tt);
		}
		cout << ans << endl;
	}
	return 0;
}
