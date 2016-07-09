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

const int N = 1000010;

int n;
int sum[N * 5];
int add[N * 5];

void push_up(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int l, int r, int rt) {
	if (add[rt] != 0) {
		int m = r - l + 1;
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += (m - (m >> 1)) * add[rt];
		sum[rt << 1 | 1] += (m >> 1) * add[rt];
		add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	CLR(sum); CLR(add);
}

void change(int o, int v,int l, int r, int rt) {
	if (l == r) {
		sum[rt] += v;
		// add[rt] += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (o <= mid) change(o, v, l, mid, rt << 1);
	else change(o, v, mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		return sum[rt];
	}
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid) ret += query(L, R, l, mid, rt << 1);
	if (R > mid) ret += query(L, R, mid + 1, r, rt << 1 | 1);
	push_up(rt);
	return ret;
}

void update(int L, int R, int v, int l, int r, int rt) {
	if (L <= l && r <= R) {
		sum[rt] += (r - l + 1) * v;
		add[rt] += v;
		return;
	}
	push_down(l, r, rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(L, R, v, l, mid, rt << 1);
	if (R > mid) update(L, R, v, mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

int ask(int o, int l, int r, int rt) {
	if (l == r) {
		return sum[rt];
	}
	push_down(l, r, rt);
	int mid = (l + r) >> 1;
	if (o <= mid) return ask(o, l, mid, rt << 1);
	else return ask(o, mid + 1, r, rt << 1 | 1);
	push_up(rt);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SI(n);
    	string s;
    	cin >> s;
    	cin >> s;
    	int q; SI(q);
    	build(1, n, 1);
    	while (q--) {
    		int op;
    		SI(op);
    		int a, b;
    		if (op == 0) {
    			SII(a, b);
    			change(a, b, 1, n, 1);
    		}
    		else if (op == 1) {
    			SII(a, b);
    			printf("%d\n", query(a, b, 1, n, 1));
    		}
    	}
    	cin >> s;
    	cin >> s;
    	build(1, n, 1);
    	SI(q);
    	while (q--) {
    		int op;
    		SI(op);
    		int a, b, c;
    		if (op == 0) {
    			SIII(a, b, c);
    			update(a, b, c, 1, n, 1);
    		}
    		else if (op == 1) {
    			SI(a);
    			printf("%d\n", ask(a, 1, n, 1));
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