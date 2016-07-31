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

const int N = 100010;

int root[N];
int ls[N * 30], rs[N * 30];
int sum[N * 30];
int a[N];
int Hash[N];
int n, q;
int tot;
int len;

int build(int l, int r) {
	int rt = ++tot;
	sum[rt] = 0;
	if (l == r) return rt;
	int mid = l + r >> 1;
	ls[rt] = build(l, mid);
	rs[rt] = build(mid + 1, r);
	return rt;
}

int update(int last, int pos, int l, int r) {
	int rt = ++tot;
	sum[rt] = sum[last] + 1;
	if (l == r) return rt;
	int mid = l + r >> 1;
	if (pos <= mid) {
		ls[rt] = update(ls[last], pos, l, mid);
		rs[rt] = rs[last];
	}
	else {
		ls[rt] = ls[last];
		rs[rt] = update(rs[last], pos, mid + 1, r);
	}
	return rt;
}

int query(int Lrt, int Rrt, int k, int l, int r) {
	if (l == r) return l;
	int mid = l + r >> 1;
	int tmp = sum[ls[Rrt]] - sum[ls[Lrt]];
	if (tmp >= k) return query(ls[Lrt], ls[Rrt], k, l, mid);
	else return query(rs[Lrt], rs[Rrt], k - tmp, mid + 1, r);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T; SI(T);
    while (T--) {
    	SII(n, q);
    	for (int i = 1; i <= n; i++) {
    		SI(a[i]);
    		Hash[i] = a[i];
    	}
    	sort(Hash + 1, Hash + 1 + n);
    	len = unique(Hash + 1, Hash + 1 + n) - Hash - 1;
    	tot = 0;
    	root[0] = build(1, len);
    	for (int i = 1; i <= n; i++) {
    		int pos = lower_bound(Hash + 1, Hash + 1 + len, a[i]) - Hash;
    		root[i] = update(root[i - 1], pos, 1, len);
    	}
    	while (q--) {
    		int l, r, k;
    		SIII(l, r, k);
    		int ans = query(root[l - 1], root[r], k, 1, len);
    		// lookln(ans);
    		printf("%d\n", Hash[ans]);
    	}
    }
	return 0;
}