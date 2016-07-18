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

const int N = 100010;
int n;
int sum[N];
int pnt[N << 1], nxt[N << 1], head[N], w[N << 1];
int cnt;

void add_edge(int u, int v, int cost) {
	pnt[cnt] = v; w[cnt] = cost; nxt[cnt] = head[u]; head[u] = cnt++;
}

void dfs(int fa, int u, int cnt) {
	sum[u] = cnt;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = pnt[i];
		if (v == fa) continue;
		dfs(u, v, cnt ^ w[i]);
	}
}

ll mp[5000060];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SI(n);
    	OFF(head); cnt = 0;
    	for (int i = 1; i < n; i++) {
    		int u, v, c;
    		SIII(u, v, c);
    		add_edge(u, v, c);
    		add_edge(v, u, c);
    	}
    	dfs(-1, 1, 0);
    	int q; SI(q);
    	while (q--) {
    		int s; SI(s);
			CLR(mp);
			ll ans = 0;
    		for(int i=1; i<=n; i++)
    		{
    			ans += mp[sum[i]^s];
    			mp[sum[i]]++;
    		}
    		if(s==0) ans+=n;
    		printf("%lld\n", ans);
    	}
    }
	return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			佛祖保佑		永无BUG
*/