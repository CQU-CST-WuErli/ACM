// SOJ 任务.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int t;
int n;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e3 + 10;
const int MAXK = 3100;
int ta[MAXN];
int tb[MAXN];
int dp[MAXN][2][MAXK];//A高多少,他们之间的差值
int dpm[MAXN][2];//上个dp两种情况的最小值
int main()
{
	cin >> t;
	while (t--){
		cin >> n;
		memset(dp, INF, sizeof dp);
		dp[0][0][0] = 0;
		dp[0][1][0] = 0;
		for (int i = 1; i <= n; ++i){
			cin >> ta[i] >> tb[i];
			for (int tk = 0; tk <= 3000; ++tk){
				//强行加a
				dp[i][0][ta[i]] = min(
					dp[i][0][ta[i]],
					dp[i - 1][0][tk] + ta[i]
					);
				//强行加b
				dp[i][1][tb[i]] = min(
					dp[i][1][tb[i]],
					dp[i - 1][1][tk] + tb[i]
					);
				//加到a
				if (ta[i] >= tk){
					dp[i][0][ta[i] - tk] = min(dp[i - 1][1][tk] + ta[i] - tk, dp[i][0][ta[i] - tk]);
				}
				else{
					dp[i][1][tk - ta[i]] = min(dp[i - 1][1][tk], dp[i][1][tk - ta[i]]);
				}
				//加到b
				if (tb[i] >= tk){
					dp[i][1][tb[i] - tk] = min(dp[i - 1][0][tk] + tb[i] - tk, dp[i][1][tb[i] - tk]);
				}
				else{
					dp[i][0][tk - tb[i]] = min(dp[i - 1][0][tk], dp[i][0][tk - tb[i]]);
				}
			}
		}
		int ans = INF;
		for (int i = 0; i <= 3000; ++i){
			ans = min(ans, min(dp[n][1][i], dp[n][0][i]));
		}
		cout << ans << endl;
	}
	return 0;
}

