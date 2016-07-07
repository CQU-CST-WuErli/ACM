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

int n, m, q;
struct Edge
{
	int u, v, w;
	Edge() {}
	Edge(int u, int v, int w):u(u), v(v), w(w){}
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
};
vector<Edge> es;

struct Q
{
	int x;
	int id;
	Q() {}
	Q(int x, int id):x(x), id(id) {}
	bool operator < (const Q& rhs) const {
		return x < rhs.x;
	}
};
vector<Q> query;

int ans[5050];
int par[20020];
int size[20020];
int sum;

int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	// sum += size[x] * size[y];
	par[x] = y;
	size[y] += size[x];
	size[x] = 0;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
    	es.clear(); query.clear();
    	CLR(ans);
        SIII(n, m, q);
        for (int i = 1; i <= m; i++) {
        	int u, v, w;
        	SIII(u, v, w);
        	es.push_back(Edge(u, v, w));
        }
        sort(es.begin(), es.end());
        // BUG;
        for (int i = 1; i <= q; i++) {
        	int x; SI(x);
        	query.push_back(Q(x, i));
        }
        sort(query.begin(), query.end());
        // BUG;
        for (int i = 1; i <= n; i++) par[i] = i, size[i] = 1;
        int cnt = 0;
    	int tmp = 0;
        for (int i = 0; i < query.size(); i++) {
        	while(cnt < es.size() && es[cnt].w <= query[i].x) {
        		int fu = find(es[cnt].u);
        		int fv = find(es[cnt].v);
        	    if (fu != fv) {
        	    	tmp += size[fu] * size[fv];
        	    	unite(fu, fv);
        	    }
        	    cnt++;
        	}
        	ans[query[i].id] = tmp;
        }
        for (int i = 1; i <= q; i++) cout << ans[i] * 2 << endl;
    }
	return 0;
}