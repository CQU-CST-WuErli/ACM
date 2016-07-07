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

const int N = 100010;
int n, k;
int a[N];
int Max[N][20], Min[N][20];

void init() {
	for (int i = 1; i <= n; i++) Max[i][0] = Min[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
			Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int k = log2(r - l + 1);
	int maxx = max(Max[l][k], Max[r - (1 << k) + 1][k]);
	int minx = min(Min[l][k], Min[r - (1 << k) + 1][k]);
	return maxx - minx;
}

int start;
int search(int l, int r) {
	int ret;
	while(l <= r) {
	    int mid = l + r >> 1;
	    if (query(start, mid) < k) ret = mid, l = mid + 1;
	    else r = mid - 1;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;SI(t);
	while(t--) {
	    SII(n, k);
	    for (int i = 1; i <= n; i++) SI(a[i]);
	    init();
	    ll ans = 0;
		for (int i = 1; i <= n; i++) {
			start = i;
			int pos = search(i, n);
			// lookln(pos);
			ans += pos - i + 1;
		}
		cout << ans << endl;
	}
	return 0;
}