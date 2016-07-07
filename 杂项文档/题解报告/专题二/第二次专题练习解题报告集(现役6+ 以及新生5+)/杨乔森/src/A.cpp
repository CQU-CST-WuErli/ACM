// SOJ 雷神之路.cpp : 定义控制台应用程序的入口点。
//

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int t;
ll n, m;
const int MAXM = 550;
const ll MOD = 1e9 + 7;
ll mi[MAXM];
ll dp[MAXM];
//矩阵快速幂
const int MATN = 3;
struct Mat {
	ll mat[MATN][MATN];
};
Mat operator * (Mat a, Mat b) {
	Mat c;
	memset(c.mat, 0, sizeof(c.mat));
	int i, j, k;
	for (k = 0; k < MATN; ++k) {
		for (i = 0; i < MATN; ++i) {
			if (a.mat[i][k] <= 0)  continue;
			for (j = 0; j < MATN; ++j) {
				if (b.mat[k][j] <= 0)    continue; 
				c.mat[i][j] = (c.mat[i][j] % MOD + (a.mat[i][k] % MOD * b.mat[k][j] % MOD)) % MOD;
			}
		}
	}
	return c;
}
Mat operator ^ (Mat a, ll k) {
	Mat c;
	int i, j;
	for (i = 0; i < MATN; ++i)
		for (j = 0; j < MATN; ++j)
			c.mat[i][j] = (i == j);

	for (; k; k >>= 1) {
		if (k & 1) c = c*a;
		a = a*a;
	}
	return c;
}
int main()
{
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= m; ++i){
			cin >> mi[i];
		}
		sort(mi + 1, mi + m + 1);
		Mat e;
		e.mat[0][0] = e.mat[0][1] = e.mat[0][2] = 1;
		e.mat[1][0] = 1;
		e.mat[1][1] = e.mat[1][2] = 0;
		e.mat[2][0] = e.mat[2][2] = 0;
		e.mat[2][1] = 1;
		mi[0] = 0;
		Mat now;
		memset(now.mat, 0, sizeof now.mat);
		now.mat[0][0] = 1;
		now.mat[0][1] = 0;
		now.mat[0][2] = 0;
		for (int i = 1; i <= m; ++i){
			if (mi[i] > n || mi[i] < 0)continue;
			ll dis = mi[i] - mi[i - 1];
			now = now*(e^dis);
			now.mat[0][0] = 0;
		}
		ll dis = n - mi[m];
		now = now*(e^dis);
		cout << now.mat[0][0] << endl;
	}
	return 0;
}

