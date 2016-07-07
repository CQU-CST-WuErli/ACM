//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

string s;
int n;
int dp[110];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("B-large.in","r",stdin);
    freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
		cin >> s;
		// cout << s << endl;
		CLR(dp);
		dp[0]=s[0]=='+'?0:1;
		for (int i=1;i<s.size();i++) {
			if (s[i]=='+') dp[i]=dp[i-1];
			else if (s[i]!=s[i-1]) dp[i]=dp[i-1]+2;
			else dp[i]=dp[i-1];
		}
		printf("Case #%d: ", kase);
		cout << dp[s.size()-1] << endl;
	}
	return 0;
}