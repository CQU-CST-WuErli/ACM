#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm> 
using namespace std;
const int maxn = 2e1 + 4;
const int inf = 0x3f3f3f3f;
typedef long long ll;
ll down, up;
ll n, a[maxn], vis[500004], minv;
priority_queue<ll, vector<ll>, greater<ll> > que; 
void dijkstra(){
	memset(vis, -1, sizeof vis);
	vis[0] = 0;
	while(que.size()) que.pop();
	que.push(0);
	while(que.size()){
		ll top = que.top(); que.pop();
		for (int i = 1; i <= n; ++i){
			ll num = top + a[i];
			num %= minv;
			if (~vis[num]) continue;
			vis[num] = top + a[i];
			que.push(top + a[i]);
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> down >> up;
		minv = inf;
		for (i = 1; i <= n; ++i){
			cin >> a[i];
			if (a[i] != 0) minv = min(minv, a[i]);
		}
		if (minv == inf){
			cout << 0 << endl;
			continue;
		}
		sort(a+1, a+1+n);
		dijkstra();
		ll ans = 0;
//		cout << minv << endl;
		for (i = 0; i < minv; ++i){
//			cout << i << ' ' << vis[i] << endl; 
			if (vis[i] == -1 || vis[i] > up) continue;
			if (vis[i] >= down) ans += (up - vis[i]) / minv + 1;
			else{
//				ans += (up - down - 1)
				if (up == down){
					if (up % minv == i) ++ans;
				}
				else{
					ll temp = down + minv;
					if (temp % minv >= i) temp -= (temp % minv - i);
					else temp = down + (i - temp % minv);
					if (down % minv == i) temp = down;
					ans += (up - temp) / minv + 1;
				}
			}
//			cout << i << ' ' << ans << endl;
		}
//		cout << minv << endl;
		cout << ans << endl; 
	}
	return 0;
}
