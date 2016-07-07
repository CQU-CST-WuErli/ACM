#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int a[maxn];
double dp[maxn];

int gcd(int a, int b) { 
	return !b ? a : gcd(b, a % b);
}

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int n, t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int base = 0, maxx = -1, ans = 0;	
		bool fg = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			if(!a[i]) fg = 1;
			base = gcd(a[i], base);
			maxx = max(maxx, a[i]);
		}
		if(!fg) {
			ans = maxx / base - n; 
			n = maxx / base;
		}
		else {
			ans = maxx / base - (n - 1);
			n = maxx / base + 1;
		}
		dp[0] = 0;
		for(int i = 1; i <= n; i++)
			dp[i] = dp[i - 1] + 1.0 * n / (n - i + 1);
		ans += floor(dp[n]);
		printf("%d\n", ans);
	}
	return 0;
}
