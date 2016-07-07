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

const int N = 100010;
int n;
int a[N];
pair<int,int> pos[N << 2];
ll dp[100010];

void pushup(int rt) {
	pos[rt] = max(pos[rt << 1], pos[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
	if (l == r) {
		pos[rt].first = a[l];
		pos[rt].second = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

pair<int,int> query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		return pos[rt];
	}
	int mid = (l + r) >> 1;
	pair<int,int> ret(-1, -1);
	if (L <= mid) ret = max(ret, query(L, R, l, mid, rt << 1));
	if (R > mid) ret = max(ret, query(L, R, mid + 1, r, rt << 1 | 1));
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n) == 1) {
        for (int i = 1; i < n; i++) SI(a[i]);
        a[n] = n;
        build(1, n, 1);
    	dp[n] = 0;
    	for (int i = n - 1; i > 0; i--) {
    		pair<int,int> tmp = query(i + 1, a[i], 1, n, 1);
    		dp[i] = dp[tmp.second] + n - i - a[i] + tmp.second;
    	}
    	ll sum = 0;
    	for (int i = 1; i <= n; i++)
    		sum += dp[i];
    	cout << sum << endl;
    }
	return 0;
}