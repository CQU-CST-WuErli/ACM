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

const int N = 2e5 + 100;
const int M = 1e5 + 100;
int n, q;
int pnt[M << 1], nxt[M << 1], head[M], cnt;
int pre[M], ed[M], label[M], dep[M], dfs_clock;
int root[N << 5], ls[N << 5], rs[N << 5];
int Max[N << 5], Min[N << 5], sum[N << 5];
int add[N << 5];
int tot;
void add_edge(int u, int v) {
	pnt[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
}
void init() {
	cnt = 0; OFF(head);
	dfs_clock = 0;
	tot = 0;
}
void dfs1(int fa, int u, int d) {
	pre[u] = ++dfs_clock;
	label[dfs_clock] = u;
	dep[u] = d;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (v == fa) continue;
		dfs1(u, v, d + 1);
	}
	ed[u] = dfs_clock;
}
int newNode(int val) {
	int rt = ++tot;
	sum[rt] = Max[rt] = Min[rt] = val;
	add[rt] = 0;
	ls[rt] = rs[rt] = -1;
	return rt;
}
int build(int l, int r) {
	if (l == r) return newNode(dep[label[l]]);
	int mid = l + r >> 1;
	int rt = newNode(0);
	ls[rt] = build(l, mid);
	rs[rt] = build(mid + 1, r);
	Max[rt] = max(Max[ls[rt]], Max[rs[rt]]);
	Min[rt] = min(Min[ls[rt]], Min[rs[rt]]);
	sum[rt] = sum[ls[rt]] + sum[rs[rt]];
	return rt;
}
int update(int last, int L, int R, int val, int l, int r) {
	int rt = ++tot;
	sum[rt] = sum[last]; Max[rt] = Max[last]; Min[rt] = Min[last];
	add[rt] = add[last];
	ls[rt] = ls[last]; rs[rt] = rs[last];
	if (L <= l && r <= R) {
		sum[rt] += val * (r - l + 1);
		Max[rt] += val;
		Min[rt] += val;
		add[rt] += val;
		return rt;
	}
	int mid = l + r >> 1;
	if (L <= mid) ls[rt] = update(ls[last], L, R, val, l, mid);
	if (R > mid) rs[rt] = update(rs[last], L, R, val, mid + 1, r);
	sum[rt] = sum[ls[rt]] + sum[rs[rt]] + add[rt] * (r - l + 1);
	Max[rt] = max(Max[ls[rt]], Max[rs[rt]]) + add[rt];
	Min[rt] = min(Min[ls[rt]], Min[rs[rt]]) + add[rt];
	return rt;
}
int change(int val, int x, int op) {
	if (op == 1) return val + x;
	if (op == 2) return min(val, x);
	return max(val, x);
}
int query(int rt, int L, int R, int op, int l, int r) {
	// lookln(Max[rt]);
	if (L <= l && r <= R) {
		if (op == 1) return sum[rt];
		if (op == 2) return Min[rt];
		if (op == 3) return Max[rt];
	}
	int mid = l + r >> 1;
	int ret;
	if (op == 1) ret = 0;
	else if (op == 2) ret = INF_INT;
	else ret = -INF_INT;
	if (L <= mid) ret = change(ret, query(ls[rt], L, R, op, l, mid), op);
	if (R > mid) ret = change(ret, query(rs[rt], L, R, op, mid + 1, r), op);
	if (op == 1) {
		if (L <= mid) ret += add[rt] * (min(mid, R) - max(L, l) + 1);
		if (R > mid) ret += add[rt] * (min(R, r) - max(mid, L - 1));
	}
	else ret += add[rt];
	return ret;
}
void dfs2(int fa, int u) {
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (v == fa) continue;
		root[v] = update(root[u], pre[v], ed[v], -1, 1, n);
		if (pre[v] > 1) root[v] = update(root[v], 1, pre[v] - 1, 1, 1, n);
		if (ed[v] < n) root[v] = update(root[v], ed[v] + 1, n, 1, 1, n);
		dfs2(u, v);
	}
}
pair<int, int> a[200202];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n, q) == 2) {
    	init();
    	int u, v;
    	for (int i = 1; i < n; i++) {
    		SII(u, v);
    		add_edge(u, v);
    		add_edge(v, u);
    	}
    	dfs1(-1, 1, 0);
    	// lookln(dfs_clock);
    	root[1] = build(1, n);
    	dfs2(-1, 1);
    	int lastans = 0;
    	int k, p, t;
    	while (q--) {
    		SIII(k, p, t);
    		p = (p + lastans) % n + 1;
    		// lookln(p);
    		int flag = 0;
    		for (int i = 1; i <= k; i++) {
    			int x; SI(x);
    			a[i].first = pre[x];
    			a[i].second = ed[x];
    			if (x == 1) flag = 1;
    		}
    		if (flag) {
    			puts("-1");
    			lastans = 0;
    			continue;
    		}
    		sort(a + 1, a + 1 + k);
    		a[k + 1] = make_pair(n + 1, n + 1);
    		int ans;
    		if (t == 1) ans = 0;
    		else if (t == 2) ans = INF_INT;
    		else ans = -INF_INT;
    		int endtime = 1;
    		for (int i = 1; i <= k + 1; i++) {
    			if (endtime < a[i].first) {
    				ans = change(ans, query(root[p], endtime, a[i].first - 1, t, 1, n), t);
    			}
    			endtime = max(endtime, a[i].second + 1);
    		}
    		lastans = ans;
    		printf("%d\n", ans);
    	}
    }
	return 0;
}