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

string s,t;
int n,dp[1010][10][10];
// dp[i][j][k] 表示t串中前i-1个已经匹配好，j是s串中第i个数，k是第i+1个数 

int dfs(int d,int d1,int d2){
	int &ans=dp[d][d1][d2];
	if (ans>=0) return ans;
	if (d==s.size()) return 0;
	ans=INF;
	int up=(t[d]-d1+10)%10; // 若向上应该转多少 
	for (int i=0;i<=up;i++)
		for (int j=0;j<=i;j++)
			ans=min(ans,dfs(d+1,(d2+i)%10,(s[d+2]+j)%10)+up);
	int down=(d1-t[d]+10)%10;
	for (int i=0;i<=down;i++) // 若向下应该转多少 
		for (int j=0;j<=i;j++)
			ans=min(ans,dfs(d+1,(d2-i+10)%10,(s[d+2]-j+10)%10)+down);
	return ans;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s){
		cin >> t;
		for (int i=0;s[i];i++){
			s[i]-='0';
			t[i]-='0';
		}
		OFF(dp);
		printf("%d\n",dfs(0,s[0],s[1]));
	}
	return 0;
}


