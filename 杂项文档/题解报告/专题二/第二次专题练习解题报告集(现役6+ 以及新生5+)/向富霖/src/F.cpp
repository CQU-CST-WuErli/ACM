#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson id << 1
#define rson id << 1 | 1
#define ml m
#define mr m + 1
using namespace std;
const int maxn = 1e5 + 5e4 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

struct firework {
	int a, b, t;
	bool operator < (const firework& rhs) const {
		return t < rhs.t;
	}
}fire[305];

class SegTree {
public:
	struct Node {
		int l, r; ll max;
	}st[maxn << 2];

	void build(int l, int r, int id = 1) {
		st[id].l = l, st[id].r = r, st[id].max = 0;
		if(l == r) return;	
		int m = l + r >> 1;
		build(l, ml, lson);
		build(mr, r, rson);
	}

	void up(int id) {
		st[id].max = max(st[lson].max, st[rson].max);
	}

	ll query(int L, int R, int id = 1) {
		int l = st[id].l, r = st[id].r, m = l + r >> 1;
		if(L <= l and r <= R)
			return st[id].max;
		ll res = -inf;
		if(L <= m) res = max(res, query(L, R, lson));	
		if(R  > m) res = max(res, query(L, R, rson));
		return res;	
	}

	void update(int pos, ll v, int id = 1) {
		int l = st[id].l, r = st[id].r, m = l + r >> 1;
		if(l == r) { st[id].max = v; return; }
		if(pos <= m) update(pos, v, lson);	
		if(pos  > m) update(pos, v, rson);
		up(id);
	}

}seg;

ll dp[maxn];

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t); fire[0].t = 1;
	while(t--) {
		int n, m, d; 
		scanf("%d %d %d", &n, &m, &d);
		for(int i = 1; i <= m; i++)
			scanf("%d %d %d", &fire[i].a, &fire[i].b, &fire[i].t);
		sort(fire + 1, fire + 1 + m);
		seg.build(1, n);
		ll ans = -inf;
		for(int i = 1; i <= m; i++) {
			int dt = fire[i].t - fire[i - 1].t;
			for(int cur = 1; cur <= n; cur++) {
				dp[cur] = seg.query(max(1, cur - dt * d), min(n, cur + dt * d));
				dp[cur] += fire[i].b - abs(fire[i].a - cur);
			}
			for(int cur = 1; cur <= n; cur++)
				seg.update(cur, dp[cur]);
		}
		for(int i = 1; i <= n; i++)
			ans = max(ans, dp[i]);
		printf("%lld\n", ans);
	}
	return 0;
}
