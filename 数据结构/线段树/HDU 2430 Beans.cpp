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

const int N = 1000010;

struct P {
    int mod, pos;
    bool operator < (const P& rhs) const {
    	if (mod == rhs.mod) return pos < rhs.pos;
    	return mod < rhs.mod;
    }
}p[N];
ll sum[N];
int n, pp, k;
int pre[N];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
    	SIII(n, pp, k);
        for (int i = 1; i <= n; i++) {
        	SI(sum[i]);
            sum[i] +=  sum[i-1];
            p[i].pos = i;
            p[i].mod = sum[i] % pp;
        }
        sort(p + 1, p + 1 + n);
        deque<P> q;
	    for (int i = 1; i <= n; i++) {
    	    if (!q.size()) pre[p[i].pos] = -1;
	        else pre[p[i].pos] = q.front().pos;
	        while (q.size() &&  p[i].pos < q.back().pos)  q.pop_back();
	        q.push_back(p[i]);
        	while (q.size() && p[i + 1].mod - q.front().mod > k) q.pop_front();
    	}
    	ll ans = - 1;
	    for (int i = 1; i <= n; ++i) {
    	    if (sum[i] % pp <= k) ans = max(ans,sum[i] / pp);
	        if (pre[i] == -1 || pre[i] >= i) continue;
       		ans = max(ans,(sum[i] - sum[pre[i]]) / pp);
    	}
    	printf("Case %d: %lld\n", kase, ans);
    }
}