#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

ll x[maxn], dp[maxn];

inline ll dist(ll x, ll y) {
	return (x - y) * (x - y);
}

int q[maxn], head, tail;

ll up(int j, int k) { return dp[j] + x[j + 1] * x[j + 1] - dp[k] - x[k + 1] * x[k + 1]; }

ll down(int j, int k) { return 2 * x[j + 1] - 2 * x[k + 1]; } 

ll Dp(int i, int j, ll w) { return dp[j] + w + dist(x[i], x[j + 1]); }

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		ll n, w; scanf("%lld %lld", &n, &w);
		dp[0] = 0; head = tail = 0; q[tail++] = 0;
		for(int i = 1; i <= n; i++) 
			scanf("%lld", x + i);
		for(int i = 1; i <= n; i++) {
			while(head + 1 < tail and up(q[head + 1], q[head]) 
				<= x[i] * down(q[head + 1], q[head])) head++;
			dp[i] = Dp(i, q[head], w);
			while(head + 1 < tail and up(i, q[tail - 1]) * down(q[tail - 1], q[tail - 2]) 
				<= up(q[tail - 1], q[tail - 2]) * down(i, q[tail - 1])) tail--;
			q[tail++] = i;
		}
		printf("%lld\n", dp[n]);
	
	}
	return 0;
}
