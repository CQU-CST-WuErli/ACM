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

const int N = 200000 + 100;

int n;
int a[N], b[N];

struct SparseTable {
	int Max[20][N], Min[20][N];
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			Max[0][i] = a[i];
			Min[0][i] = b[i];
		}
		for (int i = 1; (1 << i) <= n; i++) {
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
				Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	int RMQ(int l, int r) {
		int k = 31 - __builtin_clz(r - l + 1);
		return max(Max[k][l], Max[k][r - (1 << k) + 1]) - min(Min[k][l], Min[k][r - (1 << k) + 1]);
	}
}st;

int getMin(int l) {
	int ans = -1;
	int L = l, R = n;
	while (L <= R) {
		int mid = L + R >> 1;
		if (st.RMQ(l, mid) >= 0) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	if (ans == -1) return -1;
	if (st.RMQ(l, ans) == 0) return ans;
	else return -1;
}

int getMax(int l) {
	int ans = -1;
	int L = l, R = n;
	while (L <= R) {
		int mid = L + R >> 1;
		if (st.RMQ(l, mid) <= 0) ans = mid, L = mid + 1;
		else R = mid - 1;
	}
	if (ans == -1) return -1;
	if (st.RMQ(l, ans) == 0) return ans;
	else return -1;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n) == 1) {
        for (int i = 1; i <= n; i++) SI(a[i]);
        for (int i = 1; i <= n; i++) SI(b[i]);
        st.init(n);
    	ll ans = 0;
    	for (int l = 1; l <= n; l++) {
    		int Rmin = getMin(l);
    		if (Rmin == -1) continue;
    		int Rmax = getMax(l);
    		if (Rmax == -1) continue;
    		ans += Rmax - Rmin + 1;
    	}
    	cout << ans << endl;
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