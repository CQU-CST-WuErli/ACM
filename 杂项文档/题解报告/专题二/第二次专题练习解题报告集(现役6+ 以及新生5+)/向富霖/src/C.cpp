#include <set>
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

int dp[44][44][44][44];
int B[5], A[450], n, m;

int dfs(int a, int b, int c, int d) {
	int &res = dp[a][b][c][d];
	if(res != -1) return res; res = 0;
	int pos = 1 + B[1] - a + 2 * (B[2] - b) + 3 * (B[3] - c) + 4 * (B[4] - d); 
	if(pos > n) return res;
	res = A[pos];
	if(a - 1 >= 0) res = max(res, A[pos] + dfs(a - 1, b, c, d));
	if(b - 1 >= 0) res = max(res, A[pos] + dfs(a, b - 1, c, d));
	if(c - 1 >= 0) res = max(res, A[pos] + dfs(a, b, c - 1, d));
	if(d - 1 >= 0) res = max(res, A[pos] + dfs(a, b, c, d - 1));
	return res;
}

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);	
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%d", A + i);
		memset(B, 0, sizeof B);
		for(int i = 1; i <= m; i++) { 
			int x; scanf("%d", &x);
			B[x]++;
		}
		memset(dp, -1, sizeof dp);
		int ans = dfs(B[1], B[2], B[3], B[4]);
		printf("%d\n", ans);
	}
	return 0;
}
