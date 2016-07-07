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
ll W;
ll x[200010];
ll dp[200020];

ll getup(int i, int j) {
	return dp[i] + x[i + 1] * x[i + 1] - dp[j] - x[j + 1] * x[j + 1];
}

ll getdown(int i, int j) {
	return 2 * (x[i + 1] - x[j + 1]);
}

void solve() {
	deque<int> q;
	q.push_back(0);
	CLR(dp);
	for (int i = 1; i <= n; i++) {
		while (q.size() >= 2 && getup(q[1], q[0]) <= x[i] * getdown(q[1], q[0])) q.pop_front();
		int h = q[0];
		dp[i] = dp[h] + W + (x[i] - x[h + 1]) * (x[i] - x[h + 1]);
		h = q.size();
		if (h >= 2 && getup(i, q[h - 1]) * getdown(q[h - 1], q[h - 2]) <= getup(q[h - 1], q[h - 2]) * getdown(i, q[h - 1]))
			q.pop_back();
		q.push_back(i);
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
	while(t--) {
		cin >> n >> W;
	    for (int i = 1; i <= n; i++)
	    	cin >> x[i];
	    sort(x + 1, x + 1 + n);
	    x[0] = 0;
	    solve();
	    cout << dp[n] << endl;
	}
	return 0;
}