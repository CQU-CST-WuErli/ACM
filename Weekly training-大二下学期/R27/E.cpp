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

int n, m;
ll x, y, z;
int id;

int a[500050];
int b[500050];
int num[500050];
int sum[500050];

int lowbit(int x) {
	return x & -x;
}

void add(int pos, int v) {
	while(pos < id) {
	    sum[pos] += v;
	    sum[pos] %= MOD;
	    pos += lowbit(pos);
	}
}

int query(int pos) {
	int ret = 0;
	while(pos) {
		ret += sum[pos];
		ret %= MOD;
		pos -= lowbit(pos);
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
    	SII(n, m);
    	scanf("%I64d%I64d%I64d", &x, &y, &z);
    	for (int i = 0; i < m; i++) SI(a[i]);
    	for (int i = 0; i < n; i++) {
    		b[i + 1] = a[i % m];
    		num[i + 1] = b[i + 1];
    		a[i % m] = (x * a[i % m] + y * (i + 1)) % z;
    	}
    	id = 1; map<int, int> mp;
    	sort(b + 1, b + 1 + n);
    	for (int i = 1; i <= n; i++) {
    		if (!mp.count(b[i])) mp[b[i]] = id++;
    	}
    	CLR(sum);
    	add(1, 1);
    	int ans = 0;
    	for (int i = 1; i <= n; i++) {
    		int tmp;
    		ans += tmp = query(mp[num[i]]);
    		ans %= MOD;
    		add(mp[num[i]] + 1, tmp);
    	}
    	cout << "Case #" << kase << ": " << ans << endl;
    }
	return 0;
}