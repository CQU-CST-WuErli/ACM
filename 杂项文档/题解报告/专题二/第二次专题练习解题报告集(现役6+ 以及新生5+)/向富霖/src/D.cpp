#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int dp[2005][3005][2];
int a[2005], b[2005];

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		memset(dp, 0x3f, sizeof dp);
		int n; scanf("%d", &n);
		dp[0][0][0] = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d %d", a + i, b + i);

		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= 3000; j++) {
				if(dp[i - 1][j][0] != inf) {
					dp[i][a[i]][0] = min(dp[i][a[i]][0], dp[i - 1][j][0] + a[i]);
					if(j >= b[i]) dp[i][j - b[i]][0] = min(dp[i][j - b[i]][0], dp[i - 1][j][0]);
					else dp[i][b[i] - j][1] = min(dp[i][b[i] - j][1], dp[i - 1][j][0] + b[i] - j);
				}
				if(dp[i - 1][j][1] != inf) {
					dp[i][b[i]][1] = min(dp[i][b[i]][1], dp[i - 1][j][1] + b[i]);
					if(j >= a[i]) dp[i][j - a[i]][j != a[i]] = min(dp[i][j - a[i]][j != a[i]], dp[i - 1][j][1]);
					else dp[i][a[i] - j][0] = min(dp[i][a[i] - j][0], dp[i - 1][j][1] + a[i] - j);
				}
			}
		}
		int ans = inf;
		for(int i = 0; i <= 3000; i++)
			ans = min(ans, min(dp[n][i][1], dp[n][i][0]));
		printf("%d\n", ans);
	}
	return 0;
}
