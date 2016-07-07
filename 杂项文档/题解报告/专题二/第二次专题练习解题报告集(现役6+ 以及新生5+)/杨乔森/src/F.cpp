// SOJ 先锋看烟花.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
int t;
const int INF = 0x3f3f3f3f;
const int MAXN = 15e4 + 10;
const int MAXM = 350;
int d;
int ai[MAXM];
int ti[MAXM];
int dp[2][MAXN][20];//每一个ti时位于某一位置的最小幸福减少
int mm[MAXN];
int ans;
void RMQ(int id)    //预处理->O(nlogn)  
{
	mm[0] = -1;
	for (int i = 1; i <= n; ++i){
		mm[i] = ((i&(i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
		//dp[id][i][0] = b[i];
	}
	for (int j = 1; j <= mm[n]; ++j){
		for (int i = 1; i + (1 << j) - 1 <= n; ++i){
			dp[id][i][j] = min(dp[id][i][j - 1], dp[id][i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int id, int a, int b){
	if (a < 1)a = 1;
	if (b > n)b = n;
	int k = mm[b - a + 1];
	return min(dp[id][a][k], dp[id][b - (1 << k) + 1][k]);
}
int now;
int lst;
int main()
{
	cin >> t;
	while (t--){
		scanf("%d%d%d", &n, &m, &d);
		ans = 0;
		for (int i = 1; i <= m; ++i){
			int tb;
			scanf("%d%d%d", ai + i, &tb, ti + i);
			ans += tb;
		}
		now = 0;
		lst = 1;
		memset(dp[lst], 0, sizeof dp[lst]);
		RMQ(lst);
		ti[0] = 0;//-INF
		for (int i = 1; i <= m; ++i){
			memset(dp[now], INF, sizeof dp[now]);
			int dt = ti[i] - ti[i - 1];
			int dx = dt*d;
			for (int j = 1; j <= n; ++j){
				int lx = j - dx;
				int rx = j + dx;
				int tmp = query(lst, lx, rx);
				dp[now][j][0] = tmp + abs(j - ai[i]);
			}
			RMQ(now);
			swap(now, lst);
		}
		ans -= query(lst, 1, n);
		printf("%d\n", ans);
	}
	return 0;
}

