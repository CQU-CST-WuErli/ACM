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

const int N = 111111;
const int P = 1000000007, Q = 100000007;
int pos[N];
int pre[N];
int cnt, head[N], pnt[N << 1], nxt[N << 1];
struct HashMap {
	map<string, int> mp;
	vector<string> vec;
	int ID_cnt;
	int getID(const string& name) {
		if (mp.find(name) == mp.end()) {
			mp.insert(make_pair(name, ID_cnt++));
			vec.push_back(name);
		}
		return mp[name];
	}
	void init() {
		mp.clear();
		vec.clear();
		ID_cnt = 0;
	}
};
struct Hash {
	int u;
	int value;
	Hash(int u, int value): u(u), value(value) {}
	bool operator < (const Hash& x) const {
		return value < x.value;
	}
};
vector<Hash> cha[N];
vector<Hash> chb[N];
void add_edge(int u, int v) {
	pnt[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}
pii findFarthest(int fa, int u) {
	pii ret(u, -1);
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (v == fa) continue;
		pii cur = findFarthest(u, v);
		if (cur.second > ret.second) {
			pre[u] = v;
			ret = cur;
		}
	}
	ret.second++;
	return ret;
}

pii findRoot() {
	int a = findFarthest(-1, 0).first;
	pii t = findFarthest(-1, a);
	for (int i =0; i < t.second / 2; i++)
		a = pre[a];
	return make_pair(a, t.second % 2 ? pre[a] : -1);
}
int dfs(int fa, int u, vector<Hash>* tgt) {
	vector<Hash> vec;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (v == fa) continue;
		vec.push_back(Hash(v, dfs(u, v, tgt)));
	}
	sort(vec.begin(), vec.end());
	int ret = 1;
	for (int i =0; i < (int) vec.size(); i++) {
		ret = ((ll) ret * Q + vec[i].value) % P;
	}
	tgt[u].swap(vec);
	return ret;
}

bool match(vector<Hash> &vs, vector<Hash>& vt, int *res) {
	if (vs.size() != vt.size()) {
		return false;
	}
	for (int i = 0; i < (int)vt.size(); i++) {
		for (int j = i; j < (int) vt.size() && vs[i].value == vt[j].value; j++) {
			swap(vt[i].u, vt[j].u);
			if (match(cha[vs[i].u], chb[vt[i].u], res)) {
				goto lblMatch;
			}
		}
		return false;
		lblMatch:
		res[vs[i].u] = vt[i].u;
	}
	return true;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    while (~scanf("%d", &n)) {
    	string name;
    	cnt = 0;
    	OFF(head);
    	HashMap a, b;
    	a.init(); b.init();
    	for (int i = 1; i < n; i++) {
    		cin >> name;
    		int u = a.getID(name);
    		cin >> name;
    		int v = a.getID(name);
    		add_edge(u, v);
    		add_edge(v, u);
    	}
    	pii ra = findRoot();
    	vector<Hash> vs, vt;
    	vs.push_back(Hash(ra.first, dfs(ra.second, ra.first, cha)));
    	if (ra.second != -1)
    		vs.push_back(Hash(ra.second, dfs(ra.first, ra.second, cha)));
    	sort(vs.begin(), vs.end());
    	cnt = 0;
    	OFF(head);
    	for (int i = 1; i < n; i++) {
    		cin >> name;
    		int u = b.getID(name);
    		cin >> name;
    		int v = b.getID(name);
    		add_edge(u, v);
    		add_edge(v, u);
    	}
    	pii rb = findRoot();
    	vt.push_back(Hash(rb.first, dfs(rb.second, rb.first, chb)));
    	if (rb.second != -1)
    		vt.push_back(Hash(rb.second, dfs(rb.first, rb.second, chb)));
    	sort(vt.begin(), vt.end());
    	if (match(vs, vt, pos)) {
    		for (int i = 0; i <n; i++) {
    			cout << a.vec[i] << ' ' << b.vec[pos[i]] << '\n';
    		}
    	}
    }
	return 0;
}