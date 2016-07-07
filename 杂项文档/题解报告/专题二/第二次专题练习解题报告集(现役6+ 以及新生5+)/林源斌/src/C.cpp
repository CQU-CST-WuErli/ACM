/*

要准确表示一个状态需要 五个数据 已经到达的位置  剩余的四种道具数
但显然只要其中四个 就可以表示出第五个了 
一开始没有看到 case数 想了一个 350*40*40*40 感觉应该能过
被吐槽太暴力了
据说标答 40^4 
这样的话 两种做法本质上一样的 通过已有的4个数据表示出 剩下的第五个数据
而标答选择 用道具数 表示位置 减掉的维度是最影响复杂度的 
350*40*40*40的状态当中很多 是错误状态 算它们是浪费时间  
*/
#include <iostream>
#include <cstring>
using namespace std;
int dp[5][42][42][42], n, m, num[5], d[354], x;


int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		memset(num, 0, sizeof num);
		for (i = 1; i <= n; ++i) cin >> d[i];
		for (i = 1; i <= m; ++i){
			cin >> x;
			num[x]++; 
		}
		memset(dp, -1, sizeof dp);
		dp[1][num[1]][num[2]][num[3]] = d[1];
		for (int pos = 1; pos < n; ++pos){
			for (i = num[1]; i >= 0; --i)
				for (j = num[2]; j >= 0; --j)
					for (k = num[3]; k >= 0; --k){
//						if (pos == 6 && i == 0 && j == 0 && k) cout << dp[1][0][0][1] << "  get\n";
						if (dp[pos%5][i][j][k] == -1) continue;
						int res4 = num[4] - (pos - 1 - (num[1] - i) - 2 * (num[2] - j) - 3 * (num[3] - k)) / 4;
//						cout << pos << ' ' << i << ' ' << j << ' ' << k << ' ' << res4 << "   earn: " << dp[pos%5][i][j][k] << endl; 
						if (i) dp[(pos+1)%5][i-1][j][k] = max(dp[(pos+1)%5][i-1][j][k],  dp[pos%5][i][j][k] + d[pos+1]);
						if (j) dp[(pos+2)%5][i][j-1][k] = max(dp[(pos+2)%5][i][j-1][k],  dp[pos%5][i][j][k] + d[pos+2]);
						if (k) dp[(pos+3)%5][i][j][k-1] = max(dp[(pos+3)%5][i][j][k-1],  dp[pos%5][i][j][k] + d[pos+3]);
						if (res4) dp[(pos+4)%5][i][j][k] = max(dp[(pos+4)%5][i][j][k],  dp[pos%5][i][j][k] + d[pos+4]);
					}
			memset(dp[pos%5], -1, sizeof dp[pos%5]);
		}
		cout << dp[n%5][0][0][0] << endl; 
	}
	return 0;
}
