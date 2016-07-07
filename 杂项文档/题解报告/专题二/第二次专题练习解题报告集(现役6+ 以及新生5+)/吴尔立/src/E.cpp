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
int h[55];

int dp[2][600000];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SI(n);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        	SI(h[i]), sum += h[i];
        MEM(dp, -INF_INT);
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
        	// lookln(i);
        	int s = i & 1;
        	for (int j = 0; j <= sum; j++)
        		dp[s][j] = -INF_INT;
        	int k = s ^ 1;
        	for (int j = 0; j <= sum; j++) {
        		dp[s][j] = max(dp[s][j], dp[k][abs(j - h[i])] + h[i]);
        		dp[s][j] = max(dp[s][j], dp[k][j + h[i]] + h[i]);
        		dp[s][j] = max(dp[s][j], dp[k][j]);
        	}
        }
        if (dp[n & 1][0] <= 0) puts("GG");
        else cout << dp[n & 1][0] / 2 << endl;
    }
	return 0;
}