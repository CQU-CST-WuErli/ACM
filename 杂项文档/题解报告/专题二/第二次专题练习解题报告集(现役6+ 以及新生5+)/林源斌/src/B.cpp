/*


һ��ʼ��֪��б���Ż�
������n�� ����һ�¼�֦�ܲ��ܹ�
�������� ����ֱ��WA��
����Խ���һ�� ��Ȼһ����ȷ ����һ���ܼ������ٵ���ȥ ���� �������ݱȽ�ˮ
����֪���������б���Ż�   Ҳ�������ǽ�б���Ż�������   ���ų���һ��
���õ�long long�ֱ���� ��ĸ�ͷ��� ��������ᳬlong long ���õ�double
һ��ʼ����double�Ǹо� double�ȴ�С���鷳 ����������Ŀ���º���ֱ���� < > �Ⱦ�����
 
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
