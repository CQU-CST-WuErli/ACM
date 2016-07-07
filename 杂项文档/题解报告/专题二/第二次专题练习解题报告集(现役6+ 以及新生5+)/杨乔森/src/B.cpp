// SOJ Snowdrop修长廊.cpp : 定义控制台应用程序的入口点。
//

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int t;
int W;
int n;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5 + 10;
ll x[MAXN];
ll dp[MAXN];//前i个点全部覆盖的花费
int main()
{
	cin >> t;
	while (t--){
		scanf("%d%d", &n, &W);
		for (int i = 1; i <= n; ++i){
			scanf("%lld", x + i);
		}
		x[0] = 0;
		memset(dp, INF, sizeof dp);
		dp[0] = 0;
		dp[1] = W;
		int st = 1;
		for (int i = 2; i <= n; ++i){
			dp[i] = W + dp[i - 1];
			bool flag = true;
			for (int j = st; j < i; ++j){
				if (dp[j - 1] + W + (x[i] - x[j])*(x[i] - x[j]) < dp[i]){
					dp[i] = dp[j - 1] + W + (x[i] - x[j])*(x[i] - x[j]);
					flag = false;
				}
			}
			if (flag)st = i;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}

