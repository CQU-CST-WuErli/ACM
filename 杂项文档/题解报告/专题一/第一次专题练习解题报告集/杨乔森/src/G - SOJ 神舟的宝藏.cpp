// SOJ 神舟的宝藏.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int n, c;
int m;
const int MAXN = 510;
const int MAX = 20;
char num[MAX];
int number[MAX];
bool visn[MAX];
const int INF = 0x3f3f3f3f;
int dp[MAXN][5010];
int pre[MAXN][5010];//上一位的余数是多少
//int cc[MAXN][5010];//每一层余数为多少时的最小值

int main()
{
	cin >> t;
	while (t--){
		memset(visn, 0, sizeof visn);
		memset(dp, INF, sizeof dp);
		//memset(cc, 0, sizeof cc);
		cin >> n >> c;
		cin >> m;
		for (int i = 0; i < m; ++i){
			cin >> num[i];
			if (num[i] >= '0'&&num[i] <= '9')number[i] = num[i] - '0';
			else number[i] = num[i] - 'A' + 10;
			visn[number[i]] = 1;
		}
		if (n == 0){
			bool ff = false;
			for (int i = 0; i <= 16; ++i){
				if (visn[i]){
					if (i>9)cout << (char)('A' + i - 10) << endl;
					else cout << i << endl;
					ff = true;
					break;
				}
			}
			if (!ff)cout << "BOMB!!" << endl;
			continue;
		}
		bool flag = false;
		dp[0][0] = 0;
		int tn = 1;
		int tq = 0;
		for (int i = 1; i <= 500&&!flag; ++i){
			++tq;
			for (int k = 0; k <= 16; ++k){
				if (!visn[k])continue;
				for (int m = 0; m < n; ++m){//余数
					if (dp[i - 1][m] == INF)continue;
					//k*c+d
					//d%n = m
					//(k*c+d)%n = j
					//(k%n*c%n + m)%c = j
					int j = (tn%n*k % n + m) % n;
					if (j == 0 && dp[i][j] == 0){
						dp[i][j] = k;
						pre[i][j] = m;
					}
					else if (k < dp[i][j]){
						dp[i][j] = k;
						pre[i][j] = m;
					}
					if (k != 0 && j == 0){
						flag = true;
					}
				}
			}
			tn = tn%n*c%n;
		}
		int tt = 0;//当前余数
		if (!flag)cout << "BOMB!!!" << endl;
		else{
			for (int i = tq; i >= 1; --i){
				if (dp[i][tt] > 9)cout << (char)('A' + dp[i][tt] - 10);
				else cout << dp[i][tt];
				tt = pre[i][tt];
			}
			cout << endl;
		}
	}
	return 0;
}

