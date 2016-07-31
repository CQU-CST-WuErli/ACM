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
const int MOD=1000000007;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

string a, b;
int nxt[100010];
int vis[100010];
int dp[100010];

void getnxt(string &t) {
    nxt[0]=-1;
    int i=0,j=-1;
    while (i<t.size()) {
        while (j != -1 && t[i] != t[j]) j = nxt[j];
       	nxt[++i] = ++j;
    }
}

void kmp(string& s, string& t) {
	getnxt(t);
	int i = 0, j = 0;
	while (i < s.size() && j < t.size()) {
		while (j != -1 && s[i] != t[j]) j = nxt[j];
		i++; j++;
		if (j >= t.size()) {
			vis[i - 1] = 1;
			j = nxt[j];
		}
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    int kase = 1;
    while (t--) {
    	cin >> a >> b;
    	CLR(vis);
    	kmp(a, b);
    	CLR(dp);
		if (vis[0]) dp[0] = 2;
		else dp[0] = 1;
		for (int i = 1; i < a.size(); i++) {
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
			if (vis[i]) {
				int pos = i - b.size();
				if (pos < 0)
					dp[i] = (dp[i] + 1) % MOD;
				else dp[i] = (dp[i] + dp[pos]) % MOD;
			}
		}

		printf("Case #%d: %d\n", kase++, dp[a.size() - 1]);
    }
	return 0;
}