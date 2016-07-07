//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=1000+50;
int n;
char s[N];
int ispal[N][N];
int dp[N];

bool dfs(int l,int r){
	if (l-r==1) return 1;    // 往下数4行的边界 
	if (l>r) return 0;       // 往下数6行的边界 
	ispal[l][l]=ispal[r][r]=1;
	if (ispal[l][r]!=-1) return ispal[l][r];
	if (s[l]==s[r] && dfs(l+1,r-1)) ispal[l][r]=1;
	else ispal[l][r]=0;
	dfs(l+1,r);dfs(l,r-1);
	return ispal[l][r];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> n;
	getchar();
	for (int i=0;i<n;i++){
		gets(s+1);
		MEM(dp,0x3f3f);
		OFF(ispal);
		int len=strlen(s+1);
		dfs(1,len);
		for (int i=1;i<=len;i++){
			if (ispal[1][i]==1) dp[i]=1;
			else {
				for (int j=1;j<i;j++){
					if (ispal[j+1][i]==1) dp[i]=min(dp[i],dp[j]+1);
				}
			}
		}
		cout << dp[len] << endl;
	} 
	return 0;
}


