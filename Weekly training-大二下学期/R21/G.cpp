//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define rep(flag,start,end) for(int flag = start; flag <= end; flag++)
#define Rep(flag,start,end) for(int flag = start; flag >= end; flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
ll a[33];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n) == 1) {
		ll sum = 0;
	    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	    int s = n / 2;
	    int t = n - s;
	    vector<ll> v[17];
	    ll ans = INF_LL;
	    for (int sta = 0; sta < (1 << s); sta++) {
	    	ll tmp = 0;
	    	for (int i = 0; i < s; i++) if (sta >> i & 1)
	    		tmp += a[i];
	    	int id = __builtin_popcount(sta);
	    	v[id].push_back(tmp);
	    }
	    for (int i = 0; i <= s; i++)
	    	sort(v[i].begin(), v[i].end());
	    for (int sta = 0; sta < (1 << t); sta++) {
	    	int id = __builtin_popcount(sta);
	    	id = s - id;
	    	if (id < 0) continue;
	    	ll tmp = 0;
	    	for (int i = 0; i < t; i++) if (sta >> i & 1)
	    		tmp += a[i + s];
	    	vector<ll>::iterator it = lower_bound(v[id].begin(), v[id].end(), sum / 2LL - tmp);
	    	if (it == v[id].end()) it--;
	    	ans = min(ans, abs((tmp + (*it)) * 2LL - sum));
	    }
	    cout << ans << endl;
	}
	return 0;
}