#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
const int maxn = 3e1 + 4;
int n, num[maxn];
bool vis[maxn];
int dp[maxn];
int check(int pos, int res){
	memset(dp, 0, sizeof dp);
	for (int i = pos; i >= 1; --i){
		if (vis[i]) continue;
		for (int j = res; j >= num[i]; --j) dp[j] = max(dp[j], dp[j-num[i]] + num[i]);
		if (dp[res] == res) return i;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n;
		for (i = 1; i <= n; ++i) cin >> num[i];
		sort(num+1, num+1+n);
		memset(vis, false, sizeof vis);
		bool flag = true;
		for (i = 1; i <= n && flag; ++i){
			int res = num[i] - 1;
			for (j = i - 1; j > 0; --j) if (num[j] < num[i] - 1) break; 
			while(res != 0){
				int ans = check(j, res);
				if (ans == -1){
					flag = false;
					break;
				}
				vis[ans] = true;
				res -= num[ans];
//				cout << ans << ' '; 
			}
//			cout << i << ' ' << flag << endl; 
		}
		for (i = 1; i < n; ++i) if (!vis[i]){
			flag = false;
			break;
		}
//		cout << i << endl;
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
