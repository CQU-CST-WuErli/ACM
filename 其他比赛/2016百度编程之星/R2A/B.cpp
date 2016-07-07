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

ll a[20];
int p[20];
ll dp[1 << 20][20];
int n;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    int kase = 1;
    while(t--) {
        SI(n);
        for (int i = 0; i < n; i++)
        	scanf("%I64d%I64d", a + i, p + i);
        MEM(dp, -INF_INT);
        a[n] = 0; p[n] = n; dp[0][n] = 0;
        for (int i = 0; i < n; i++) {
        	for (int state = 0; state < (1 << n); state++) {
        		if (__builtin_popcount(state) != i) continue;
        		for (int j = 0; j <= n; j++) {
        			if (dp[state][j] <= -INF_INT) continue;
        			for (int k = 0; k < n; k++) {
        				if ((p[k] != i && p[k] != -1) || (state >> k & 1)) continue;
        				dp[state | (1 << k)][k] = max(dp[state | (1 << k)][k], dp[state][j] + a[j] * a[k]);
        			}
        		}
        	}
        }
        cout << "Case #" << kase++ <<":" << endl;
        ll ans = -INF_INT;
        for (int i = 0; i < n; i++) if (dp[(1 << n) - 1][i] < INF_INT) ans = max(ans, dp[(1 << n) - 1][i]);
        cout << ans << endl;
    }
	return 0;
}