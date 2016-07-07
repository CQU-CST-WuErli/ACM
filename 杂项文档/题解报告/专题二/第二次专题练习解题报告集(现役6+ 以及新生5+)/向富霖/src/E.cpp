#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int h[100], dp[2][maxn];

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);	
	while(t--) {
		int n; scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d", h + i), sum += h[i];

		memset(dp, 0xc3, sizeof dp);
		sum = 0; dp[0][0] = 0;
		int now = 1;
		for(int i = 1; i <= n; i++) {		
			sum += h[i];
			memcpy(dp[now], dp[now ^ 1], sizeof dp[now]);
			for(int j = 0; j <= sum; j++) {
				if(j + h[i] <= sum) dp[now][j] = max(dp[now ^ 1][j + h[i]] + h[i], dp[now][j]);
				dp[now][j] = max(dp[now ^ 1][abs(h[i] - j)] + h[i], dp[now][j]);
			}
			now = now ^ 1;
		}
		if(!dp[now ^ 1][0]) puts("GG");
		else printf("%d\n", dp[now ^ 1][0] / 2);
	}
	return 0;
}
