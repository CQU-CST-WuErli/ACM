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
#include <cassert>
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
int a[1010];
char ans[500010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T; SI(T);
    while (T--) {
    	SII(n, m);
    	for (int i = 1; i <= n; i++)
    		SI(a[i]);
		vector<pair<int, int> > low, up;
    	for (int i = 1; i <= n; i++) {
    		int one = 0, zero = 0;
    		for (int j = i; j <= n; j++) {
    			if (j & 1) zero += a[j];
    			else one += a[j];
    			if ((i & 1) && (j & 1)) low.push_back(make_pair(zero, one));
    			else if (!(i & 1) && !(j & 1)) up.push_back(make_pair(zero, one));
    		}
    	}
    	sort(low.begin(), low.end());
    	sort(up.begin(), up.end());
    	int cnt = 0;
    	for (int i = 0, j; i < (int)low.size(); i = j) {
    		for (j = i; j < low.size() && low[i].first == low[j].first; j++);
    		while (cnt && low[cnt - 1].second >= low[i].second) cnt--;
    		low[cnt++] = low[i];
    	}
    	low.resize(cnt);
    	cnt = 0;
    	for (int i = 0, j; i < (int)up.size(); i = j) {
    		for (j = i; j < up.size() && up[i].first == up[j].first; j++);
    		if (!cnt || up[cnt - 1].second < up[j - 1].second) {
    			up[cnt++] = up[j - 1];
    		}
    	}
    	up.resize(cnt);

    	for (int i = 1; i <= m; i++) {
    		int a, b; SII(a, b);
    		auto ub = upper_bound(up.begin(), up.end(), make_pair(a, INF_INT));
    		ub--;
    		auto lb = upper_bound(low.begin(), low.end(), make_pair(a, -INF_INT));
    		if (lb != low.end() && ub->second >= b && lb->second <= b)
    			ans[i] = '1';
    		else ans[i] = '0';
    	}
    	ans[m + 1] = '\0';
    	puts(ans + 1);
    }
	return 0;
}