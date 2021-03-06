//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <bitset>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int a[110];
int dp[110][3];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	a[0] = 0;
    	for (int i = 1; i <= n; i++)
    		SI(a[i]);
    	MEM(dp, INF_INT);
    	dp[0][0] = 0;
    	for (int i = 1; i <= n; i++) {
    		if (a[i] == 0) {
    			for (int j = 0; j < 3; j++)
    				dp[i][0] = min(dp[i - 1][j] + 1, dp[i][0]);
    		}
    		else if (a[i] == 1) {
    			for (int j = 0; j < 3; j++)
    				dp[i][0] = min(dp[i - 1][j] + 1, dp[i][0]);
    			if (a[i - 1] == 1)
    				dp[i][1] = dp[i - 1][0];
    			else dp[i][1] = min(dp[i][1], min(dp[i - 1][0], dp[i - 1][2]));
    		}
    		else if (a[i] == 2) {
    			for (int j = 0; j < 3; j++)
    				dp[i][0] = min(dp[i - 1][j] + 1, dp[i][0]);
    			if (a[i - 1] == 2)
    				dp[i][2] = dp[i - 1][0];
    			else dp[i][2] = min(dp[i][2], min(dp[i - 1][0], dp[i - 1][1]));
    		}
    		else {
    			for (int j = 0; j < 3; j++)
    				dp[i][0] = min(dp[i - 1][j] + 1, dp[i][0]);
    			if (a[i - 1] == 1)
    				dp[i][1] = dp[i - 1][0];
    			else dp[i][1] = min(dp[i][1], min(dp[i - 1][0], dp[i - 1][2]));
    			if (a[i - 1] == 2)
    				dp[i][2] = dp[i - 1][0];
    			else dp[i][2] = min(dp[i][2], min(dp[i - 1][0], dp[i - 1][1]));
    		}
    	}
    	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
    }
	return 0;
}