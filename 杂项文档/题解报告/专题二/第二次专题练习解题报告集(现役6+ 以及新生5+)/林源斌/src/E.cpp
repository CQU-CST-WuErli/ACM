/*
lcy��ү������⵱���⽲��
����Ⱪ���Ļ�ʱ���ǹ��� �ռ䲻��
��Ҫ����������� dp����Ϊint�� �ܴ�Ķ����ͱ�bool �����  Ȼ���ټӸ������� 
 
*/
 
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 5e5 + 4;
int dp[2][maxn], n, h[104];
int main(){
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		
		cin >> n;
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;
		int sum = 0;
		for (i = 1; i <= n; ++i){
			cin >> h[i];
			sum += h[i];
		}
		sum = min(sum, 500000);
		for (i = 1; i <= n; ++i){
			for (j = 0; j < h[i]; ++j) {
				if (dp[(i-1)&1][h[i] - j] != -1) dp[i&1][j] = max(dp[(i-1)&1][j], dp[(i-1)&1][h[i] - j] + h[i] - j);
				else dp[i&1][j] = dp[(i-1)&1][j];
				if (h[i] + j <= sum && dp[(i-1)&1][h[i]+j] != -1) dp[i&1][j] = max(dp[i&1][j], dp[(i-1)&1][h[i]+j] + h[i]);
//				cout << dp[i&1][j] << ' ';
			}
			for (; j <= sum; ++j){
				dp[i&1][j] = max(dp[(i-1)&1][j], dp[(i-1)&1][j-h[i]]);
				if (h[i] + j <= sum && dp[(i-1)&1][h[i]+j] != -1) dp[i&1][j] = max(dp[i&1][j], dp[(i-1)&1][h[i]+j] + h[i]);
//				cout << dp[i&1][j] << ' ';
			}
//			cout << endl;
		}
		if (dp[n&1][0] == 0) cout << "GG\n";
		else cout << dp[n&1][0] << endl;
	}
	return 0;
}
