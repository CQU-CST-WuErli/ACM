//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <bitset>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n, m;
char mp[1100][1100];
vector<pair<int, int> > vc;

ll all(ll x) {
	return x * (x + 1) / 2;
}

ll gao(int i, int j) {
	ll ret = 0;
	ll l = j - 1, r = m - j;
	ret += n * (all(l) + all(r));
	ll u = i - 1, d = n - i;
	ret += m * (all(u) + all(d));
	return ret;
}

ll cal(int n, int m) {
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ret += gao(i, j);
		}
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	vc.clear();
    	SII(n, m);
    	for (int i = 1; i <= n; i++) {
    		scanf("%s", mp[i] + 1);
    		for (int j = 1; j <= m; j++) {
    			// cout << mp[i][j] << ' ';
    			if (mp[i][j] == 'G') vc.push_back(make_pair(i, j));
    		}
    		// cout << endl;
    	}
    	ll sum = cal(n, m);
    	// lookln(sum);
    	for (auto& it : vc) {
    		int x = it.first, y = it.second;
    		sum -= 2.0 * gao(x, y);
    	}
    	if (vc.size() > 1) {
    		for (int i = 0;i < vc.size(); i++) {
    			for (int j = i + 1; j < vc.size(); j++) {
    				int dis = vc[i].first - vc[j].first + vc[i].second - vc[j].second;
    				sum += 2.0 * dis;
    			}
    		}
    	}
    	// lookln(sum);
    	ll ret = 0;
    	for (auto& it : vc) {
    		int x = it.first, y = it.second;
    		ll tmp = 0;
    		int st = 2, ed = x;
    		for (int i = x + 1; i <= n; i++) {
    			tmp += (st + ed) * (x - 1) / 2;
    			st++; ed++;
    		}
    		ret += tmp * 2;
    		tmp = 0, st = 2, ed = y;
    		for (int i = y + 1; i <= m; i++) {
    			tmp += (st + ed) * (y - 1) / 2;
    			st++; ed++;
    		}
    		ret += tmp * 2.0;
    		sum += ((ll)(x- 1) * (ll)(n - x) + (ll)(y - 1) * (ll)(m - y)) * 2.0;
    	}
    	sum -= ret;
    	// lookln(sum);
    	ll num = (double)(n * m - vc.size());
    	double ans = (double)sum / (double)(num * num);
    	printf("%.4f\n", ans);
    }
	return 0;
}