#include <iostream>
#include <algorithm>
#include <ostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 4;
ll n, w, a[maxn], dp[maxn], q[maxn], head, tail;
inline ll getDP(int i, int j){
//	cout << i << ' ' << j << "   haha ??   \n";
	return dp[j] + w + (a[i] - a[j+1]) * (a[i] - a[j+1]); 
}
//inline ll getUP(int j, int k){
////	return dp[j] + a[j+1] * a[j+1] - (dp[k] + a[k+1] * a[k+1]);
//	return ;
//}
//inline ll getDown(int j, int k){
//	return 2 * (a[j+1] - a[k+1]);
//}
double Slope(int j, int k){
	double ans = 0;
	ans += (1.0 * a[j+1] - a[k+1]) * (1.0 * a[j+1] + a[k+1]) + dp[j] - dp[k];
	return ans /= 2 * (a[j+1] - a[k+1]);
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> w;
		for (i = 1; i <= n; ++i) cin >> a[i];
		dp[0] = a[0] = 0;
		sort(a+1, a+1+n);
		a[n+1] = 1e9;
		head = tail = 0;
		q[tail++] = 0;
		for (i = 1; i <= n; ++i){
			while(head < tail - 1 && Slope(q[head+1], q[head]) <= 1.0 * a[i]) head++;
			dp[i] = getDP(i, q[head]);
			while(head < tail - 1 && Slope(q[tail-1], q[tail-2]) >= Slope(i, q[tail-1])) tail--;
			q[tail++] = i;
//			cout << q[head] << ' ' << dp[i] << ' ' << head << ' ' << tail << endl; 
		}
//		cout << endl;
		cout << dp[n] << endl;
	}
	return 0;
}
