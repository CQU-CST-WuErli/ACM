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

int n, m;
int a[400];
int b[10];
int dp[41][41][41][41];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SII(n, m);
        for (int i = 1; i <= n; i++)
        	SI(a[i]);
        CLR(b);
        for (int i = 1; i <= m; i++) {
        	int x; SI(x);
        	b[x]++;
        }
        CLR(dp);
        dp[0][0][0][0] = a[1];
        for (int i = 0; i <= b[1]; i++) {
        	for (int j = 0; j <= b[2]; j++) {
        		for (int x = 0; x <= b[3]; x++) {
        			for (int y = 0; y <= b[4]; y++) {
        				int currpos = i * 1 + j * 2 + x * 3 + y * 4 + 1;
        				int& now = dp[i][j][x][y];
        				if (i) now = max(now, dp[i - 1][j][x][y] + a[currpos]);
        				if (j) now = max(now, dp[i][j - 1][x][y] + a[currpos]);
        				if (x) now = max(now, dp[i][j][x - 1][y] + a[currpos]);
        				if (y) now = max(now, dp[i][j][x][y - 1] + a[currpos]);
        			}
        		}
        	}
        }
        cout << dp[b[1]][b[2]][b[3]][b[4]] << endl;
    }
	return 0;
}