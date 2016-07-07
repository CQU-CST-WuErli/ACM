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

inline int Read() {
    int ret = 0;
    char c; bool sgn = false;
    c = getchar();
    while(c <= ' ') c = getchar();
    if(c == '-') sgn = true, c = getchar();
    for(ret = 0; c >= '0'; c = getchar())
        ret = ret * 10 + (c - '0');
    if(sgn) ret = - ret;
    return ret;
}

const int N = 10010;

int x[N], y[N], z[N], d[N];
int sum[(1000001 + 10010) * 2][2];
int offset = 1000001 + 10010;
int n;
vector<int> g;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
    	SI(n);
    	for (int i = 1; i <= n; i++) {
    		x[i] = Read(); y[i] = Read();
    		z[i] = Read(); d[i] = Read();
    		x[i] += offset; y[i] += offset;
    	}
    	CLR(sum); g.clear();
    	int maxr = 0;
    	for (int i = 1; i <= n; i++) {
    		int id = d[i] == -1 ? 0 : 1;
    		int r = x[i] + z[i];
    		int l = y[i] - z[i];
    		if (l <= r) {
    			sum[l][id] += 1;
    			sum[r + 1][id] -= 1;
    			g.push_back(l);
    			g.push_back(r + 1);
    		}
    	}
    	sort(g.begin(), g.end());
    	g.resize(unique(g.begin(), g.end()) - g.begin());
    	int tl = 0, tr = 0, Max = 0;
    	int ans = 0;
   //  	for (int i = 0; i <= maxr; i++) {
   //  		tl += sum[i][0];
			// ans = max(ans, tl + Max);
			// tr += sum[i][1];
			// Max = max(Max, tr);
   //  	}
    	for (int i = 0; i < g.size(); i++) {
    		tl += sum[g[i]][0];
    		ans = max(ans, tl + Max);
    		tr += sum[g[i]][1];
    		Max = max(Max, tr);
    	}
    	printf("Case #%d:\n%d\n", kase, ans);
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