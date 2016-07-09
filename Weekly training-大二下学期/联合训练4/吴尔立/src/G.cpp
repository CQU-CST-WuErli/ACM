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

const int N = 100010 * 5;

int sum[N];
int a1[N], d[N];
int same[N], val[N];
int add[N];
int n, m;

void push_up(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int l, int r, int rt) {
	int mid = (l + r) >> 1;
	int len = r - l + 1;
	int len1 = mid - l + 1, len2 = r - mid;
	if (same[rt]) {
		same[rt << 1] = same[rt << 1 | 1] = 1;
		val[rt << 1] = val[rt << 1 | 1] = val[rt];
		sum[rt << 1] = len1 * val[rt];
		sum[rt << 1 | 1] = len2 * val[rt];
		a1[rt << 1] = d[rt << 1] = add[rt << 1] = 0;
		a1[rt << 1 | 1] = d[rt << 1 | 1] = add[rt << 1 | 1] = 0;
		same[rt] = val[rt] = 0;
	}
	if (a1[rt] || d[rt]) {
		a1[rt << 1] += a1[rt]; d[rt << 1] += d[rt];
		sum[rt << 1] += len1 * a1[rt] + len1 * (len1 - 1) * d[rt] / 2;

		a1[rt] += len1 * d[rt];

		a1[rt << 1 | 1] += a1[rt]; d[rt << 1 | 1] += d[rt];
		sum[rt << 1 | 1] += len2 * a1[rt] + len2 * (len2 - 1) * d[rt] / 2;

		a1[rt] = d[rt] = 0;
	}
	if (add[rt]) {
		add[rt << 1] += add[rt]; add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += len1 * add[rt];
		sum[rt << 1 | 1] += len2 * add[rt];

		add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	sum[rt] = add[rt] = a1[rt] = d[rt] = same[rt] = val[rt] = 0;
	if (l == r) {
		scanf("%d", sum + rt);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

void change(int L, int R, int v, int l, int r, int rt) {
	if (L <= l && r <= R) {
		add[rt] += v;
		sum[rt] += (r - l + 1) * v;
		return;
	}
	push_down(l, r, rt);
	int mid = (l + r) >> 1;
	if (L <= mid) change(L, R, v, l, mid, rt << 1);
	if (R > mid) change(L, R, v, mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

void update(int L, int R, int v, int l, int r, int rt) {
	if (L <= l && r <= R) {
		int fst = (l - L + 1) * v;
		a1[rt] += fst; d[rt] += v;
		int len = r - l + 1;
		sum[rt] += len * fst + len * (len - 1) * v / 2;
		return;
	}
	push_down(l, r, rt);
	int mid = (l + r) >> 1;
	if (L <= mid) change(L, R, v, l, mid, rt << 1);
	if (R > mid) change(L, R, v, mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

void set(int L, int R, int v, int l, int r, int rt) {
	if (L <= l && r <= R) {
		same[rt] = 1; val[rt] = v;
		sum[rt] = (r - l + 1) * v;
		a1[rt] = d[rt] = add[rt] = 0;
		return;
	}
	push_down(l, r, rt);
	int mid = (l + r) >> 1;
	if (L <= mid) set(L, R, v, l, mid, rt << 1);
	if (R > mid) set(L, R, v, mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		return sum[rt];
	}
	push_down(l, r, rt);
	int ret = 0;
	int mid = (l + r) >> 1;
	if (L <= mid) ret += query(L, R, l, mid, rt << 1);
	if (R > mid) ret += query(L, R, mid + 1, r, rt << 1 | 1);
	push_up(rt);
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
    	SII(n, m);
    	build(1, n, 1);
    	int op, a, b, c;
    	for (int i = 1; i <= m; i++) {
    		SI(op); SII(a, b);
    		if (op == 1) {
    			SI(c);
    			change(a, b, c, 1, n, 1);
    		}
    		else if (op == 2) {
    			SI(c);
    			update(a, b, c, 1, n, 1);
    		}
    		else if (op == 3) {
    			SI(c);
    			set(a, b, c, 1, n, 1);
    		}
    		else if (op == 4) {
    			printf("%d\n", query(a, b, 1, n, 1));
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