#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 15e4 + 4;
typedef long long ll;
typedef pair<ll, int> P;
deque<P> que;
int cur, m, n, d, t[2], pos;
ll dp[2][maxn], L;
int main(){
	int i, j, k, kase;
	ios::sync_with_stdio(false);
	cin >> kase;
	while(kase--){
		cin >> m >> n >> d; 
		cur = 1;
		cin >> pos >> L >> t[cur];
		for (i = 1; i <= m; ++i) dp[cur][i] = L - abs(pos - i);
		for (i = 2; i <= n; ++i){
			cur ^= 1;
			cin >> pos >> L >> t[cur];
			while(que.size()) que.pop_back();
			for (j = 1; j <= m; ++j){
				while(que.size() && (que.back()).first <= dp[1-cur][j]) que.pop_back();
				que.push_back(P(dp[1-cur][j], j));
				while((que.front()).second + (t[cur] - t[1-cur]) * d < j) que.pop_front();
				dp[cur][j] = que.front().first + L - abs(pos - j);
			}
			while(que.size()) que.pop_back();
			for (j = m; j >= 1; --j){
				while(que.size() && (que.back()).first <= dp[1-cur][j]) que.pop_back();
				que.push_back(P(dp[1-cur][j], j));
				while((que.front()).second - (t[cur] - t[1-cur]) * d > j) que.pop_front();
				dp[cur][j] = max(dp[cur][j], que.front().first + L - abs(pos - j));
			}
		}
		cout << *max_element(dp[cur]+1, dp[cur]+1+m) << endl;
	}
	return 0;
	
}
