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
int a[100010];
struct SparseTable {
	int gcd[21][100010];
	void init() {
		for (int i = 1; i <= n; i++)
			gcd[0][i] = a[i];
		for (int i = 1; (1 << i) <= n; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				gcd[i][j] = __gcd(gcd[i - 1][j], gcd[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	int query(int L, int R) {
		int k = 31 - __builtin_clz(R - L + 1);
		return __gcd(gcd[k][L], gcd[k][R - (1 << k) + 1]);
	}
}st;

struct Q {
	int l, r, id, val;
	Q() {}
};
Q q[100010];
map<int, int> mp;
ll ans[100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    int iCase = 1;
    while (t--) {
    	SI(n);
    	for (int i = 1; i <= n; i++)
    		scanf("%d", a + i);
    	st.init();
    	mp.clear();
    	CLR(ans);
    	int m; SI(m);
    	int cnt = 0;
    	for (int i = 1; i <= m; i++) {
    		scanf("%d%d", &q[i].l, &q[i].r);
    		int tmp = st.query(q[i].l, q[i].r);
    		if (mp.find(tmp) == mp.end()) mp[tmp] = ++cnt;
    		q[i].id = mp[tmp];
    		q[i].val = tmp;
    	}
    	for (int i = 1; i <= n; i++) {
    		int pos = i, tmp = a[i];
    		while (1) {
    			int L = pos, R = n;
    			int rb = L;
    			while (L <= R) {
    				int mid = L + R >> 1;
    				if (st.query(i, mid) >= tmp) rb = mid, L = mid + 1;
    				else R = mid - 1;
    			}
    			if (mp.find(tmp) != mp.end()) {
    				int id = mp[tmp];
    				ans[id] += rb - pos + 1;
    			}
    			pos = rb + 1;
    			tmp = __gcd(tmp, a[pos]);
    			if (pos > n) break;
    		}
    	}
    	printf("Case #%d:\n", iCase++);
    	for (int i = 1; i <= m; i++) {
    		printf("%d %lld\n", q[i].val, ans[q[i].id]);
    	}
    }
	return 0;
}