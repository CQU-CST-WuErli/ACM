// SOJ 来签个到吧.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll t;
ll n;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 10;
ll tmax;
ll a[MAXN];
ll gg;
ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a%b);
}
ll ans;
ll gailv;
ll getgailv(ll n){
	double res = 0;
	for (int i = 1; i <= n; ++i){
		res += (1.0*n) / (1.0*i);
	}
	return (ll)res;
}
int main()
{
	cin >> t;
	while (t--){
		cin >> n;
		tmax = -INF;
		bool flag = true;
		gg = 0;
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
			if (gg == 0)gg = a[1];
			if (a[i] != 0) gg = gcd(gg, a[i]);
			else flag = false;
			tmax = max(tmax, a[i]);
		}
		ll tot;
		if (gg == 0)
			tot = 1;
		else if (flag)
			tot = tmax / gg;
		else
			tot = tmax / gg + 1;
		ans = tot - n;
		gailv = getgailv(tot);
		ans += gailv;
		cout << ans << endl;
	}
	return 0;
}

