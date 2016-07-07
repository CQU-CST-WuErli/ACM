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

const int N = 100;
int n, m;
int u[N], v[N];
int deg[N];
int on[N], off[N];
int ans;

bool judge() {
	for (int i = 1; i <= n; i++)
		if (on[i] != off[i]) return false;
	return true;
}

void dfs(int cnt) {
	if (cnt == m + 1) {
		if (judge()) ans++;
		return;
	}
	int x = u[cnt], y = v[cnt];
	if (on[x] < deg[x] / 2 && on[y] < deg[y] / 2) {
		on[x]++; on[y]++;
		dfs(cnt + 1);
		on[x]--; on[y]--;
	}
	if (off[x] < deg[x] / 2 && off[y] < deg[y] / 2) {
		off[x]++; off[y]++;
		dfs(cnt + 1);
		off[x]--; off[y]--;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
    	CLR(deg), CLR(on); CLR(off);
    	for (int i = 1; i <= m; i++) {
    		SII(u[i], v[i]);
    		deg[u[i]]++; deg[v[i]]++;
    	}
    	int flag = 0;
    	for (int i = 1; i <= n; i++) {
    		if (deg[i] % 2) {
    			flag = 1;
    			break;
    		}
    	}
    	if (flag) {
    		cout << 0 << endl;
    		continue;
    	}
    	else {
    		ans = 0;
    		dfs(1);
    		cout << ans << endl;
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