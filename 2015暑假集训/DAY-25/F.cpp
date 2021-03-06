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
string s;
int dp[N][N];

int dfs(int l,int r){
	int &ans=dp[l][r];
	if (l==r) return ans=0;
	if (l-r==1) return ans=0;
	if (l>r) return ans=0;	
	if (ans!=-1) return ans;
	ans=INF;
	if (s[l]==s[r]) ans=min(ans,dfs(l+1,r-1));
	else if (s[l]!=s[r]) {
		if (dfs(l+1,r)<dfs(l,r-1)){
			ans=dp[l+1][r]+1;
		}
		else {
			ans=dp[l][r-1]+1;
		}
	}
	return ans;
}

void print(int l,int r){
	if (l>r) return ;
	if (l==r) {
		cout << s[l] ;
	}
	else if (s[l]==s[r] && dp[l][r]==dp[l+1][r-1]) {
		cout << s[l];
		print(l+1,r-1);
		cout << s[r];
		return;
	}
	else if (dp[l][r]==dp[l+1][r]+1){
		cout << s[l];
		print(l+1,r);
		cout << s[l];
	}
	else {
		cout << s[r];
		print(l,r-1);
		cout << s[r];
	}
	return ;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s){
		int ls=s.size();
		OFF(dp);
		cout << dfs(0,ls-1) <<' ';
		print(0,ls-1);
		cout << endl;
	}
	return 0;
}


