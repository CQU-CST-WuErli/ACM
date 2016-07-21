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

const int N = 5e4 + 10;
const int M = N * 4 * 100;

int n, m;
int root[M], ls[M], rs[M], add[M], sum[M];
int cnt, ql, qr;

void update(int& rt, int l, int r) {
	if (!rt) rt = ++cnt;
	if (ql <= l && r <= qr) {
		add[rt]++, sum[rt] += (r - l + 1);
	}
	else {
		int mid = l + r >> 1;
		if (ql <= mid) update(ls[rt], l, mid);
		if (qr > mid) update(rs[rt], mid + 1, r);
		sum[rt] = sum[ls[rt]] + sum[rs[rt]] + add[rt] * (r - l + 1);
	}
}

void query(int& rt, int l, int r, int& qsum, int val) {
	if (!rt) rt = ++cnt;
	if (ql <= l && r <= qr) {
		qsum += sum[rt] + val * (r - l + 1);
	}
	else {
		int mid = l + r >> 1;
		if (ql <= mid) query(ls[rt], l, mid, qsum, val + add[rt]);
		if (qr > mid) query(rs[rt], mid + 1, r, qsum, val + add[rt]);

	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n, m) == 2) {
    	cnt = 0; CLR(add); CLR(sum); CLR(root); CLR(ls); CLR(rs);
    	for (int i = 1; i <= m; i++) {
    		int op;
    		int c;
    		SI(op);
    		SIII(ql, qr, c);
    		// cout << op << ' ' << ql <<  ' ' << qr <<  ' ' << c << endl;
    		if (op == 1) {
    			int l = 1, r = n;
    			int rt = 1;
 	  			while (1) {
    				update(root[rt], 1, n);
    				if (l == r) break;
    				int mid = l + r >> 1;
    				if (c <= mid) {
    					rt = rt << 1;
    					r = mid;
    				}
    				else {
    					rt = rt << 1 | 1;
    					l = mid + 1;
    				}
    			}
    		}
    		else if (op == 2) {
    			int l = 1, r = n;
    			int rt = 1;
    			while (1) {
    				if (l == r) break;
    				int mid = l + r >> 1;
    				int tmp = 0;
    				query(root[rt << 1 | 1], 1, n, tmp, 0);
    				if (tmp >= c) {
    					rt = rt << 1 | 1;
    					l = mid + 1;
    				}
    				else {
    					c -= tmp;
    					rt = rt << 1;
    					r = mid;
    				}
    			}
    			printf("%d\n", l);
    		}
    	}
    }
	return 0;
}