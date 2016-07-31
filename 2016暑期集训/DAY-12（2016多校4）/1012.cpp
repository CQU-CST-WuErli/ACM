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

int n;
int sum[100010];
int a[100010];
int ans[100010];

int lowbit(int x) {
	return x & (-x);
}

void add(int pos) {
	while (pos <= n) {
		sum[pos]++;
		pos += lowbit(pos);
	}
}

int query(int pos) {
	int ret = 0;
	while (pos) {
		ret += sum[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    int kase = 1;
    while (t--) {
    	SI(n);
    	for (int i = 1; i <= n; i++)
    		SI(a[i]);
    	CLR(sum);
    	for (int i = n; i >= 1; i--) {
    		int tmp = query(a[i] - 1) - query(0);
    		ans[a[i]] = i + tmp;
    		add(a[i]);
    	}
    	// for (int i = 1; i <= n; i++)
    	// 	cout << ans[i] << ' ';
    	// cout << endl;
    	for (int i = 1; i <= n; i++) {
    		int tmp = min(i, a[i]);
    		ans[a[i]] = abs(ans[a[i]] - tmp);
    	}
    	printf("Case #%d: ", kase++);
    	for (int i = 1; i <= n; i++)
    		printf("%d%c", ans[i], " \n"[i == n]);
    }
	return 0;
}