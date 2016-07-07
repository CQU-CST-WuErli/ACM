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

const int N = 1001;
int a[N];
int n;

struct SparseTable
{
	int dp[11][N];
	void init(int n) {
		for (int i = 1; i <= n; i++) dp[0][i] = a[i];
		for (int i = 1; (1 << i) <= n; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j + (1 << (i - 1))]);
			}
		}
	}
	int query(int l, int r) {
		int k = 31 - __builtin_clz(r - l + 1);
		return max(dp[k][l], dp[k][r - (1 << k) + 1]);
	}
}st;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t; SI(t);
	while(t--) {
	    SI(n);
	    for (int i = 1; i <= n; i++) SI(a[i]);
	    st.init(n);
		int q; SI(q);
		while (q--) {
			int l, r;
			SII(l, r);
			printf("%d\n", st.query(l, r));
		}
	}
	return 0;
}