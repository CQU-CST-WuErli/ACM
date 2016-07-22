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
typedef pair<int, int> pii;

const int N = 550;
int n, m;
int cor[N];
int mp[N][N];
vector<int> g[N];
int dis[N][N];
int par[N][N];
int vis[N];

bool bipartite(int u, int color) {
	vis[u] = color;
	for (auto &v : g[u]) {
		if (!vis[v]) if (!bipartite(v, -color)) return false;
		else if (vis[v] == vis[u]) return false;
	}
	return true;
}

pii getNum(int fa, int u) {
	pii ret(0, 0);
	vis[u] = 1;
	if (cor[u] == 0) ret.first++;
	else ret.second++;
	for (auto &v : g[u]) {
		if (v == fa || vis[v]) continue;
		pii tmp = getNum(u, v);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}
	return ret;
}

void getPoint(int fa, int u, int color, vector<int>& l, vector<int>& r) {
	vis[u] = color;
	if (vis[u] == 1) l.push_back(u);
	else r.push_back(u);
	for (auto& v : g[u]) {
		if (v == fa) continue;
		if (!vis[v]) getPoint(u, v, -color, l, r);
	}
}

struct MCMF {
	const static int N = 550;
	const static int M = 2e6;
	int pnt[M],head[N],nxt[M],cap[M],cost[M],pre[M];
	int cnt;
	int a[N],p[N],vis[N];
	ll d[N];
	void init() {
		OFF(head); cnt = 0;
	}
	void add_edge(int u, int v, int f, int w) {
		pnt[cnt] = v; pre[cnt] = u; nxt[cnt] = head[u]; head[u] = cnt;
		cap[cnt] = f; cost[cnt++] = w;
	}
	bool spfa(int s, int t, int& Flow, ll& Cost) {
		memset(a, 0, sizeof a);
		memset(vis, 0, sizeof vis);
		for (int i = s; i <= t; i++) d[i] = INF_INT;
		stack<int> q;
		vis[s] = 1;
		a[s] = INF_INT;
		d[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.top(); q.pop();
			vis[x] = 0;
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = pnt[i];
				if (d[v] > d[x] + cost[i] && cap[i]) {
					d[v] = d[x] + cost[i];
					p[v] = i;
					a[v] = min(a[x], cap[i]);
					if (!vis[v]) {
						q.push(v);
						vis[v] = 1;
					}
				}
			}
		}
		if (d[t] >= INF_INT) return false;
		Flow += a[t];
		Cost += a[t] * d[t];
		for (int u = t; u != s; u = pre[p[u]]) {
			cap[p[u]] -= a[t];
			cap[p[u] ^ 1] += a[t];
		}
		// lookln(Flow);
		return true;
	}
	pair<int ,ll> solve(int s, int t, vector<int>& l, vector<int>& r, vector<pii>& op) {
		int Flow = 0;
		ll Cost = 0;
		while (spfa(s, t, Flow, Cost));
		for (auto& u : l) {
			for (int i = head[u]; ~i; i = nxt[i]) {
				int v = pnt[i];
				if (cap[i] == 0 && v != 0) {
					// cout << "u = " << u << endl;
					while (par[u][v] != v) {
						// cout << v << ' ' << par[u][v] << endl;
						op.push_back(make_pair(v, par[u][v]));
						v = par[u][v];
					}
				}
			}
		}
		return make_pair(Flow, Cost);
	}
}mfmc;

int getAns(vector<int>& l, vector<int>& r, vector<pii>& op, int id) {
	mfmc.init();
	int source = 0, sink = n + 1;
	for (auto& it : l) {
		mfmc.add_edge(source, it, 1, 0);
		mfmc.add_edge(it, source, 0, 0);
	}
	for (auto& it : r) {
		mfmc.add_edge(it, sink, 1, 0);
		mfmc.add_edge(sink, it, 0, 0);
	}
	int cnt = 0;
	for (auto &u : l) if (cor[u] == id) {
		cnt++;
		for (auto &v : r) if (cor[v] == (id ^ 1)) {
			// cout << "u = " << u << " v = " << v << endl;
			mfmc.add_edge(u, v, 1, mp[u][v]);
			mfmc.add_edge(v, u, 0, -mp[u][v]);
		}
	}
	pair<int, ll> ret = mfmc.solve(source, sink, l, r, op);
	if (ret.first == cnt) {
		return ret.second;
	}
	else {
		op.clear();
		return -1;
	}
}

int gao(vector<int>& l, vector<int>& r, vector<pii>& ans) {
	map<int, int> mp1, mp2;
	for (auto& it : l)
		mp1[cor[it]]++;
	for (auto& it : r)
		mp2[cor[it]]++;
	if (mp1.size() != mp2.size()) return 0;
	if (mp1[0] != mp2[1] || mp1[1] != mp2[0]) return 0;
	vector<pii> op1, op2;
	int ta = getAns(l, r, op1, 0);
	int tb = getAns(l, r, op2, 1);
	if (ta == -1 || (ta > tb)) {
		ta = tb;
		op1.swap(op2);
	}
	ans.swap(op1);
	return ta;
}

void getpre() {
	MEM(dis, INF_INT);
	queue<int> q;
	for (int s = 1; s <= n; s++) {
		CLR(vis);
		q.push(s);
		vis[s] = 1;
		dis[s][s] = 0;
		par[s][s] = s;
		while (q.size()) {
			int u = q.front(); q.pop();
			vis[u] = 0;
			for (auto&v : g[u]) {
				if (dis[s][v] > dis[s][u] + 1)  {
					dis[s][v] = dis[s][ u] + 1;
					par[s][v] = u;
					if (!vis[v]) {
						vis[v] = 1;
						q.push(v);
					}
				}
			}
		}
	}
}

bool solve() {
	SII(n, m);
 	for (int i = 1; i <= n; i++)
    	scanf("%1d", cor + i);
    for (int i = 1; i <= n; i++)
    	g[i].clear();
    MEM(mp, INF_INT);
    for (int i = 1; i <= n; i++)
    	mp[i][i] = 0;

    for (int i = 1; i <= m; i++) {
    	int u, v; SII(u, v);
    	mp[u][v] = mp[v][u] = 1;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for (int k = 1; k <= n; k++) {
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
    		}
    	}
    }
    getpre();
    CLR(vis);
    for (int i = 1; i <= n; i++) if (!vis[i]) {
    	if (!bipartite(i, 1)) return false;
    }
    CLR(vis);
    for (int i = 1; i <= n; i++) if (!vis[i]) {
    	pii tmp = getNum(-1, i);
    	if (tmp.first != tmp.second) return false;
    }
    CLR(vis);
    vector<pii> ans;
    int num = 0;
    for (int i = 1; i <= n; i++) if (vis[i] == 0) {
    	vector<int> l, r;
    	getPoint(-1, i, 1, l, r);
	    vector<pii> tmp;
    	num += gao(l, r, tmp);
    	ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    printf("%d\n", num);
    if (ans.size()) {
    	for (auto &it : ans)
    		printf("%d %d\n", it.first, it.second);
    }
    return true;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
    	if (!solve()) puts("-1");
    }
	return 0;
}