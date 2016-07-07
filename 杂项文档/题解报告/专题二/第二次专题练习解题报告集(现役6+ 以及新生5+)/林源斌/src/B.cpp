/*


一开始不知道斜率优化
暴力是n方 想试一下剪枝能不能过
想了两个 都是直接WA的
最后尝试交了一个 虽然一定正确 但不一定能剪掉多少的上去 过了 可能数据比较水
后来知道这道题是斜率优化   也基本就是讲斜率优化的例题   对着抄了一发
先用的long long分别求出 分母和分子 不过好像会超long long 改用的double
一开始不用double是感觉 double比大小很麻烦 不过这种题目底下好像直接用 < > 比就行了
 
*/ 
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 4;
ll dp[maxn], x[maxn], n, w;
int main(){
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> w;
		for (i = 1; i <= n; ++i) cin >> x[i];
		sort(x+1, x+1+n);
		dp[0] = 0;
		dp[1] = w;
		for (i = 2; i <= n; ++i){
			dp[i] = w + dp[i-1];
			for (j = i - 1; j >= 1; --j){
				ll temp = dp[j-1] + w + (x[i] - x[j]) * (x[i] - x[j]);
				dp[i] = min(dp[i], temp);
				if (temp - dp[j-1] >= dp[i]) break;
			//	if (temp > (i - j + 1) * w) break;
//				if ((x[j+1] - x[j]) * (x[j+1] + x[j]) >= w) break;
			}
		}
		cout << dp[n] << endl; 
	}
	return 0;
}
