// SOJ Goozy的积木.cpp : 定义控制台应用程序的入口点。
//

#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 55;
const int MAXH = 5e5 + 10;
int t;
int n;
int a[MAXN];
int dp[2][MAXH << 2];//用了前i个,差值为h时最高的塔有多高
int tm;
int now;
int lst;
int main()
{
	cin >> t;
	while (t--){
		cin >> n;
		memset(dp, -1, sizeof dp);
		tm = 0;
		now = 0;
		lst = 1;
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
			tm += a[i];
		}
		dp[now][0] = 0;
		swap(now, lst);
		for (int i = 1; i <= n; ++i){
			for (int j = 0; j <= tm; ++j){
				if (j - a[i] >= 0){
					if (dp[lst][j - a[i]] != -1)
						dp[now][j] = max(dp[now][j], dp[lst][j - a[i]] + a[i]);//在高的塔上增加
				}
				else
					if (dp[lst][a[i] - j] != -1)
						dp[now][j] = max(dp[now][j], dp[lst][a[i] - j] + j);//原来的塔较低//加完后变高塔
				if (dp[lst][j + a[i]] != -1)
					dp[now][j] = max(dp[now][j], dp[lst][j + a[i]]);//在低的塔上增加
				if (dp[lst][j] != -1)
					dp[now][j] = max(dp[now][j], dp[lst][j]);//不增加
			}
			swap(now, lst);
		}
		int ans = max(dp[lst][0], dp[now][0]);
		if (ans == 0)cout << "GG" << endl;
		else cout << ans << endl;
	}
	return 0;
}

