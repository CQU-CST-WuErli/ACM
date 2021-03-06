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
#define null NULL
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int dp[1100][1100];
string s;

int dfs(int l,int r) {
	int &ans=dp[l][r];
	if (l==r) return ans=0;
	if (l-r==1) return ans=0;
	if (l>r) return ans=0;
	if (ans!=-1) return ans;
	ans=INF_INT;
	if (s[l]==s[r]) ans=min(ans,dfs(l+1,r-1));
	else {
		ans=min(dfs(l+1,r),dfs(l,r-1))+1;
	} 
	return ans;
}

void print(int l,int r) {
	if (l>r) return;
	if (l==r) {
		cout << s[l];
		return; 
	}
	if (s[l]==s[r] && dp[l][r]==dp[l+1][r-1]) {
		cout << s[l];
		print(l+1,r-1);
		cout << s[r];
	}
	else {
		if (dp[l][r]==dp[l+1][r]+1) {
			cout << s[l];
			print(l+1,r);
			cout << s[l];
		}
		else if (dp[l][r]==dp[l][r-1]+1) {
			cout << s[r];
			print(l,r-1);
			cout << s[r];
		}
	}
} 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s) {
		OFF(dp);
		int ans=dfs(0,s.size()-1);
		cout << ans << ' '; 
		print(0,s.size()-1);
		cout << endl;
	}
	return 0;
}

