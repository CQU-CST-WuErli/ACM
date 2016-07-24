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

int x, y, n, d;
int dp[1111][1111];
int offset = 210;
vector<pair<int, int> > v;

int dfs(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	if ((x - offset) * (x - offset) + (y - offset) * (y - offset) >= d * d) return 1;
	for (auto& it : v) {
		int tx = x + it.first, ty = y + it.second;
		if (!dfs(tx, ty)) return dp[x][y] = 1;
	}
	return dp[x][y] = 0;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(x, y) ==2) {
    	SII(n, d);
    	OFF(dp); v.clear();
    	x += offset, y += offset;
    	for (int i = 1; i <= n; i++) {
    		int a, b; SII(a, b);
    		v.push_back(make_pair(a, b));
    	}
    	if (dfs(x, y)) puts("Anton");
    	else puts("Dasha");
    }
	return 0;
}