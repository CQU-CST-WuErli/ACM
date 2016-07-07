// SOJ TaoSama与煎饼.cpp : 定义控制台应用程序的入口点。
//

#include<cstring>
#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int t;
int n, m;
const int MAXN = 355;
const int MAXM = 125;
const int INF = 0x3f3f3f3f;
int a[MAXN];
int tb[MAXN];
int dp[41][41][41][41];//当每一个剩多少的时候dp的最大值
int max4(int a, int b, int c, int d){
	return max(max(a, b), max(c, d));
}
int re(int i, int j, int k, int q){
	if (i < 0 || j < 0 || k < 0 || q < 0)return 0;
	return dp[i][j][k][q];
}
int main()
{
	cin >> t;
	while (t--){
		cin >> n >> m;
		memset(tb, 0, sizeof tb);
		for (int i = 1; i <= n; ++i){
			scanf("%d", a + i);
		}
		for (int i = 1; i <= m; ++i){
			int tbi;
			scanf("%d", &tbi);
			tb[tbi]++;
		}
		memset(dp, 0, sizeof dp);
		dp[0][0][0][0] = a[1];
		for (int i = 0; i <= tb[1]; ++i){
			for (int j = 0; j <= tb[2]; ++j){
				for (int k = 0; k <= tb[3]; ++k){
					for (int q = 0; q <= tb[4]; ++q){
						int pos = i + j * 2 + k * 3 + q * 4 + 1;
						int num = a[pos];
						dp[i][j][k][q] = max(max4(re(i - 1, j, k, q), re(i, j - 1, k, q), re(i, j, k - 1, q), re(i, j, k, q - 1)) + num, dp[i][j][k][q]);
					}
				}
			}
		}
		cout << dp[tb[1]][tb[2]][tb[3]][tb[4]] << endl;
	}
	return 0;
}

