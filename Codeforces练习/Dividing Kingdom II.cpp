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

int n, q, m;
struct Edge {
	int u, v, w, id;
	Edge(int u, int v, int w, int id):u(u), v(v), w(w), id(id) {}
	Edge() {}
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
};
vector<Edge> es;
int par[1010 << 1], rnk[1010 << 1];

void init() {
	for (int i = 1; i <= 2 * n; i++) par[i] = i, rnk[i] = 0;
}

int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) par[x] = y;
	else {
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

int query(int l, int r) {
	init();
	for (int i = es.size() - 1; i >= 0; i--) {
		Edge& e = es[i];
		if (e.id < l || e.id > r) continue;
		if (!same(e.u, e.v)) {
			unite(e.u, e.v + n);
			unite(e.u + n, e.v);
		}
		else return e.w;
	}
	return -1;
}



int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	// freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SIII(n, m, q) == 3) {
		es.clear();
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			SIII(u, v, w);
			es.push_back(Edge(u, v, w, i));
		}
		sort(es.begin(), es.end());
		int l, r;
		while(q--) {
			SII(l, r);
			printf("%d\n", query(l, r));
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