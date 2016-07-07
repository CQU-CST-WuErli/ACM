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
int u[10010], v[10010],c[10010];

struct SegmentTree {
	const static int maxn = 10010;
	int Max[maxn << 2], Min[maxn << 2], Neg[maxn << 2];

	void push_up(int rt) {
		Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
		Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
	}
	void push_down(int rt) {
		if (Neg[rt]) {
			Neg[rt << 1] ^= 1;
			Neg[rt << 1 | 1] ^= 1;
			Max[rt << 1] = -Max[rt << 1]; Min[rt << 1] = -Min[rt << 1];
			swap(Max[rt << 1], Min[rt << 1]);
			Max[rt << 1 | 1] = -Max[rt << 1 | 1]; Min[rt << 1 | 1] = -Min[rt << 1 | 1];
			swap(Max[rt << 1 | 1], Min[rt << 1 | 1]);
			Neg[rt] = 0;
		}
	}
	void update(int rt) {
		Max[rt] = -Max[rt];
		Min[rt] = -Min[rt];
		swap(Max[rt], Min[rt]);
	}
	void build(int l, int r, int rt) {
		Max[rt] = -INF_INT;
		Min[rt] = INF_INT;
		Neg[rt] = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, rt << 1);
		build(mid + 1, r, rt << 1 | 1);
		push_up(rt);
	}
	void change(int o, int v, int l, int r, int rt) {
		if (l == r) {
			Max[rt] = Min[rt] = v;
			Neg[rt] = 0;
			return;
		}
		push_down(rt);
		int mid = (l + r) >> 1;
		if (o <= mid) change(o, v, l, mid, rt << 1);
		else change(o, v, mid + 1, r, rt << 1 | 1);
		push_up(rt);
		return;
	}
	void negate(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			Max[rt] = -Max[rt]; Min[rt] = -Min[rt];
			swap(Max[rt], Min[rt]);
			Neg[rt] ^= 1;
			return;
		}
		push_down(rt);
		int mid = (l + r) >> 1;
		if (L <= mid) negate(L, R, l, mid, rt << 1);
		if (R > mid) negate(L, R, mid + 1, r, rt << 1 | 1);
		push_up(rt);
		return;
	}
	int query(int L, int R, int l, int r,int rt) {
		if (L <= l && r <= R) {
			return Max[rt];
		}
		push_down(rt);
		int mid = (l + r) >> 1;
		int ret = -INF_INT;
		if (L <= mid) ret = max(ret, query(L, R, l, mid, rt << 1));
		if (R > mid) ret = max(ret, query(L, R, mid + 1, r, rt << 1 | 1));
		push_up(rt);
		return ret;
	}
}T;

struct HLD {
	const static int N = 10010;
	const static int M = 10010 * 2;
	int pnt[M], nxt[M], head[N], cnt;
	int sz[N], fa[N], dep[N], pre[N], son[N], top[N], dfs_clock;

	void init() {
		cnt = dfs_clock = 0;
		CLR(son);
		OFF(head);
	}
	void add_edge(int u, int v) {
		pnt[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
	}
	void dfs1(int f, int u, int d) {
		sz[u] = 1; fa[u] = f; dep[u] = d;
		for (int i = head[u]; i != -1; i = nxt[i]) {
			int v = pnt[i];
			if (v == f) continue;
			dfs1(u, v, d + 1);
			if (son[u] == 0 || sz[son[u]] < sz[v]) son[u] = v;
			sz[u] += sz[v];
		}
	}
	void dfs2(int tp, int u) {
		pre[u] = ++dfs_clock;
		top[u] = tp;
		if (son[u]) dfs2(tp, son[u]);
		for (int i = head[u]; i != -1; i = nxt[i]) {
			int v = pnt[i];
			if (v == fa[u] || v == son[u]) continue;
			dfs2(v, v);
		}
	}
	void build() {
		dfs1(-1, 1, 0);
		dfs2(1, 1);
	}
	int queryMax(int u, int v) {
		int fu = top[u], fv = top[v];
		int ret = -INF_INT;
		while (fu != fv) {
			if (dep[fu] < dep[fv]) {
				swap(fu, fv);
				swap(u, v);
			}
			ret = max(ret, T.query(pre[fu], pre[u], 1, dfs_clock, 1));
			u = fa[fu], fu = top[u];
		}
		if (u == v) return ret;
		if (dep[u] > dep[v]) swap(u, v);
		ret = max(ret, T.query(pre[son[u]], pre[v], 1, dfs_clock, 1));
		return ret;
	}
	void Negate(int u, int v) {
		int fu = top[u], fv = top[v];
		while (fu != fv) {
			if (dep[fu] < dep[fv]) {
				swap(fu, fv);
				swap(u, v);
			}
			T.negate(pre[fu], pre[u], 1, dfs_clock, 1);
			u = fa[fu], fu = top[u];
		}
		if (u == v) return;
		if (dep[u] > dep[v]) swap(u, v);
		return T.negate(pre[son[u]], pre[v], 1, dfs_clock, 1);
	}
}hld;



int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
 	int t; SI(t);
 	while (t--) {
 		SI(n);
 		for (int i = 1; i < n; i++)
 			SIII(u[i], v[i], c[i]);
 		hld.init();
 		for (int i = 1; i < n; i++) {
 			hld.add_edge(u[i], v[i]);
 			hld.add_edge(v[i], u[i]);
 		}
 		hld.build();
 		T.build(1, hld.dfs_clock, 1);
 		for (int i = 1; i < n; i++) {
 			if (hld.dep[u[i]] > hld.dep[v[i]]) swap(u[i], v[i]);
 			T.change(hld.pre[v[i]], c[i], 1, hld.dfs_clock, 1);
 		}
 		// for (int i = 1; i < n; i++) cout << hld.pre[i] << endl;
 		char op[10];
 		// cout << T.query(32, 69, 1, hld.dfs_clock, 1) << endl;
 		// for (int i = 1; i <= 99; i++) {
 		// 	cout << T.query(i, i, 1, hld.dfs_clock, 1) << endl;
 		// }
 		while (scanf("%s", op) == 1) {
 			if (*op == 'D') break;
 			int a, b;
 			SII(a, b);
 			if (*op == 'Q') {
 				cout << hld.queryMax(a, b) << endl;
 			}
 			else if (*op == 'C') {
 				T.change(hld.pre[v[a]], b, 1, hld.dfs_clock, 1);
 			}
 			else if (*op == 'N') {
 				hld.Negate(a, b);
 			}
 		}
 	}
	return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			佛祖保佑		永无BUG
*/