#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int n, dp[1005], cnt, maxd;

bool dfs(int x, int dep){
	if(dep >= maxd) return x == n;
	int ma = *max_element(dp, dp + cnt);
	if(ma << maxd - dep < n) return false;
	for(int i = cnt - 1; i >= 0; i--){
		dp[cnt++] = x + dp[i];
		if(dfs(x + dp[i], dep + 1)) return true;
		cnt--;
		dp[cnt++] = x - dp[i];
		if(dfs(x - dp[i], dep + 1)) return true;
		cnt--;
	}
	return false;
} 

int main(){
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		for(maxd = 31 - __builtin_clz(n); ; maxd++) {
			cnt = 1; dp[0] = 1;
			if(dfs(1, 0)) break;	
		}
		cout << maxd << endl;
	}
	return 0;
}