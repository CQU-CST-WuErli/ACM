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

const int N = 2e5 + 10;
struct Q {
	int id, l, r, k;
	Q() {}
	Q(int id, int l, int r, int k):id(id), l(l), r(r), k(k) {}
};
Q q[N], q1[N], q2[N];
int discretize[N << 1];
int n, m;
int val[N];
int ans[N];
struct Bit {
	int val[N];
	int n;
	void init(int _n) {
		CLR(val);
		n = _n;
	}
	int lowbit(int x) {
		return x & (-x);
	}
	void update(int pos, int v) {
		while (pos <= n) {
			val[pos] += v;
			pos += lowbit(pos);
		}
	}
	int sum(int pos) {
		int ret = 0;
		while (pos) {
			ret += val[pos];
			pos -= lowbit(pos);
		}
		return ret;
	}
	int query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
}bit;

void cdq(int qL, int qR, int l, int r) {
	if (l == r) {
		for (int i = qL; i <= qR; i++) {
			if (q[i].id)
				ans[q[i].id] = discretize[l];
		}
		return;
	}
	int mid = l + r >> 1;
	int cnt1 = 0, cnt2 = 0;
	for (int i = qL; i <= qR; i++) {
		if (q[i].id == 0) {
			if (q[i].k <= mid) {
				q1[++cnt1] = q[i];
				bit.update(q[i].l, q[i].r);
			}
			else q2[++cnt2] = q[i];
		}
		else {
			int rnk = bit.query(q[i].l, q[i].r);
			if (q[i].k <= rnk)
				q1[++cnt1] = q[i];
			else {
				q[i].k -= rnk;
				q2[++cnt2] = q[i];
			}
		}
	}
	for (int i = 1; i <= cnt1; i++)
		if (q1[i].id == 0)
			bit.update(q1[i].l, -q1[i].r);
	for (int i = 1; i <= cnt1; i++)
		q[qL + i - 1] = q1[i];
	for (int i = 1; i <= cnt2; i++)
		q[qL + cnt1 - 1 + i] = q2[i];
	cdq(qL, qL + cnt1 - 1, l, mid);
	cdq(qL + cnt1, qR, mid + 1, r);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n, m) == 2) {
 		int qcnt = 0, tid = 0, cnt = 0;
    	for (int i = 1; i <= n; i++) {
    		SI(val[i]);
    		q[++qcnt] = Q(0, i, 1, val[i]);
    		discretize[++cnt] = val[i];
    	}
    	for (int i = 1; i <= m; i++) {
    		int l, r, k;
    		SIII(l, r, k);
    		q[++qcnt] = Q(++tid, l, r, k);
    	}
    	sort(discretize + 1, discretize + 1 + cnt);
    	cnt = unique(discretize + 1, discretize + 1 + cnt) - discretize - 1;
    	for (int i = 1; i <= n; i++) {
    		if (q[i].id == 0) {
    			q[i].k = lower_bound(discretize + 1, discretize + 1 + cnt, q[i].k) - discretize;
    		}
    	}
    	bit.init(n);
    	cdq(1, qcnt, 1, cnt);
    	for (int i = 1; i <= m; i++)
    		printf("%d\n", ans[i]);
    }
	return 0;
}