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

ll n, k;
ll a[101000], b[101000];

bool check(ll x) {
	ll tmp = k;
	for (int i = 1; i <= n; i++) {
		ll tt = x * a[i] - b[i];
		if (tt >= 0) tmp -= tt;
		if (tmp < 0) return false;
	}
	return true;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(cin >> n >> k) {
        for (int i = 1; i <= n; i++)
        	scanf("%I64d", a + i);
        for (int j = 1; j <= n; j++)
        	scanf("%I64d", b + j);
        ll l = 0, r = 2000000002;
        int ans;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            // lookln(mid);
            if (check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << ans << endl;
    }
	return 0;
}