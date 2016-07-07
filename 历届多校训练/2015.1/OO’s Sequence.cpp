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

int a[100010];
int n;
int l[100010], r[100010];
int pos[100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n) == 1) {
		for (int i = 1; i <= n; i++) SI(a[i]);
		CLR(pos);
		for (int i = 1; i <= n; i++) {
			int tmp = sqrt(a[i]);
			int p = 0;
			for (int j = 1; j <= tmp; j++) {
				if (a[i] % j == 0) {
					if (pos[j]) p = max(p, pos[j]);
					if (pos[a[i] / j]) p = max(p, pos[a[i] / j]);
				}
			}
			l[i] = p;
			pos[a[i]] = i;
		}
		for (int i = 1; i <= n; i++) pos[i] = n + 1;
		for (int i = n; i >= 1; i--) {
			int tmp = sqrt(a[i]);
			int p = n + 1;
			for (int j = 1; j <= tmp; j++) {
				if (a[i] % j == 0) {
					if (pos[j]) p = min(p, pos[j]);
					if (pos[a[i] / j]) p = min(p, pos[a[i] / j]);
				}
			}
			r[i] = p;
			pos[a[i]] = i;
		}
		// for (int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << endl;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += ((i - l[i]) * (r[i] - i)) % MOD;
			ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}