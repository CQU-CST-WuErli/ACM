/*
���������ƶ� (�1e18)�� ÿ�ο�����ǰ 1/2/3�� �����ڸ����� n (n <= 500)�������(�е���) �ǲ���������ȥ��
���յ�ķ�����

�������С��ֱ�ӿ�����dp��ȥ������ �����ݱȽϴ� ֻ�ܲ��þ��������
��ÿһ�����׵����յ�
����յ�T T-1 T-2 ���ǲ�֪��������Ŀ�� ֱ�ӿ����ݹ�ȥ�ͺ�
���T-2 ��֪�� �ǿ��Բ�ʹ�ÿ����� ��ʹ�ñ����Ƶ�T
��һ�� map<ll, ll> ��¼һ������ĵ�ķ����� 

*/
 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const long long MOD = 1e9 + 7;
const int maxn = 5e2 + 4;
typedef long long ll;

struct Mat{
	ll m[3][3];
	Mat(ll _a[3][3]){
		memcpy(m, _a, sizeof m);
	}
	Mat(){
	}
	Mat operator * (const Mat &A) const{
		Mat res;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j){
				res.m[i][j] = 0;
				for (int p = 0; p < 3; ++p){
					res.m[i][j] += m[i][p] * A.m[p][j];
					res.m[i][j] %= MOD;
				}
			}
		return res;
	}
};
ll base[3][3] = {0, 0, 1, 1, 0, 1, 0, 1, 1};
ll s[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
Mat Base(base);
ll n, x[maxn], m, pre[3], lst;
map<ll, ll> dp;
Mat powMat(ll p){
	Mat a = Base, res(s);
	while(p){
		if (p & 1){
			res = res * a;
		}
		a = a * a;
		p >>= 1;
	}
	return res;
}
void npre(ll num, ll bef){
	ll t[3];
	if (dp.find(num - 2) != dp.end()){
		if (num - 2 == bef){
			t[0] = dp[num-2];
			t[1] = (dp[num-2] + dp[num-3] + dp[num-4]) % MOD;
			dp[num - 1] = t[1];
			lst = (dp[num-1] + dp[num-2] + dp[num-3]) % MOD;
			dp[num] = t[2] = 0;
			memcpy(pre, t, sizeof t);
			return;
		}
//		cout << num << "   anquan\n";
		pre[0] = dp[num-2];
		pre[1] = dp[num-1];
		lst = (dp[num-1] + dp[num-2] + dp[num-3]) % MOD;
		dp[num] = pre[2] = 0;
		return;
	}
	else{
		Mat ans = powMat(num-2-bef);
		t[0] = ((ans.m[0][2] * pre[0]) % MOD + (ans.m[1][2] * pre[1]) % MOD + (ans.m[2][2] * pre[2]) % MOD) % MOD;
		ans = ans * Base;
		t[1] = ((ans.m[0][2] * pre[0]) % MOD + (ans.m[1][2] * pre[1]) % MOD + (ans.m[2][2] * pre[2]) % MOD) % MOD;
		ans = ans * Base;
		lst = ((ans.m[0][2] * pre[0]) % MOD + (ans.m[1][2] * pre[1]) % MOD + (ans.m[2][2] * pre[2]) % MOD) % MOD;
		dp[num] = t[2] = 0;
		dp[num-1] = t[1];
		dp[num-2] = t[0];
		memcpy(pre, t, sizeof t);
		return;
	}
}
int main(){
	int i, j, k, kase;
	ios::sync_with_stdio(false);
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		int index = 1;
		for (i = 1; i <= m; ++i) cin >> x[i];
		sort(x+1, x+1+m);
		pre[0] = 1;
		if (index > m || x[index] != 1) pre[1] = 1;
		else{
			pre[1] = 0;
			index++;
		}
		if (index > m || x[index] != 2) pre[2] = pre[1] + pre[0];
		else{
			pre[2] = 0;
			index++;
		}
		dp.clear();
		dp[0] = pre[0]; dp[1] = pre[1]; dp[2] = pre[2];
		x[index - 1] = 2;
		while(index <= m){
//			cout << x[index-1] << ' ' << x[index] << "    newpre is called\n";
			npre(x[index], x[index-1]);
			index++;
		}
		if (x[m] == n) cout << 0 << endl;
		else{
			npre(n, x[m]);
			cout << lst << endl;
		}
//		for (i = 0; i < n; ++i) cout << dp[i] << ' '; cout << lst << endl;
	}
	return 0;
}
/*
30 4
1 4 20 11
*/
