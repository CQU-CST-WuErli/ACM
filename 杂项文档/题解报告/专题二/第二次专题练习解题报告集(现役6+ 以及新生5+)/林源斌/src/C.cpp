/*

Ҫ׼ȷ��ʾһ��״̬��Ҫ ������� �Ѿ������λ��  ʣ������ֵ�����
����ȻֻҪ�����ĸ� �Ϳ��Ա�ʾ��������� 
һ��ʼû�п��� case�� ����һ�� 350*40*40*40 �о�Ӧ���ܹ�
���²�̫������
��˵��� 40^4 
�����Ļ� ��������������һ���� ͨ�����е�4�����ݱ�ʾ�� ʣ�µĵ��������
�����ѡ�� �õ����� ��ʾλ�� ������ά������Ӱ�츴�Ӷȵ� 
350*40*40*40��״̬���кܶ� �Ǵ���״̬ ���������˷�ʱ��  
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
