// SOJ Goozy�Ļ�ľ.cpp : �������̨Ӧ�ó������ڵ㡣
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
int dp[2][MAXH << 2];//����ǰi��,��ֵΪhʱ��ߵ����ж��
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
						dp[now][j] = max(dp[now][j], dp[lst][j - a[i]] + a[i]);//�ڸߵ���������
				}
				else
					if (dp[lst][a[i] - j] != -1)
						dp[now][j] = max(dp[now][j], dp[lst][a[i] - j] + j);//ԭ�������ϵ�//���������
				if (dp[lst][j + a[i]] != -1)
					dp[now][j] = max(dp[now][j], dp[lst][j + a[i]]);//�ڵ͵���������
				if (dp[lst][j] != -1)
					dp[now][j] = max(dp[now][j], dp[lst][j]);//������
			}
			swap(now, lst);
		}
		int ans = max(dp[lst][0], dp[now][0]);
		if (ans == 0)cout << "GG" << endl;
		else cout << ans << endl;
	}
	return 0;
}

