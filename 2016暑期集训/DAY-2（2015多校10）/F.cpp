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
const int MOD=2015;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Matrix {
	int n;
	int mat[55][55];
	void init(int _n) {
		n = _n;
		memset(mat, 0, sizeof mat);
	}
	void unit(int _n) {
		n = _n;
		memset(mat, 0, sizeof mat);
		for (int i = 1; i <= n; i++)
			mat[i][i] = 1;
	}
	Matrix operator * (const Matrix& rhs) {
		Matrix ret;
		ret.init(n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % MOD) % MOD;
				}
				ret.mat[i][j] %= MOD;
			}
		}
		return ret;
	}
	Matrix operator ^ (int x) {
		Matrix ret; ret.unit(n);
		Matrix ans = *this;
		while (x) {
			if (x & 1) ret = ret * ans;
			ans = ans * ans;
			x >>= 1;
		}
		return ret;
	}
	void print() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << mat[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

int n, m;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
    	Matrix dp; dp.init(n + 1);
    	for (int i = 1; i <= n; i++) {
    		int k; SI(k);
    		while (k--) {
    			int x; SI(x);
    			dp.mat[i][x] = 1;
    		}
    	}
    	for (int i = 1; i <= n + 1; i++)
    		dp.mat[i][n + 1] = 1;
    	// dp.print();
    	Matrix ans; ans.init(n + 1);
    	for (int i = 1; i <= n; i++)
    		ans.mat[1][i] = 1;
    	dp = dp ^ (m - 1);
    	ans = ans * dp;
    	int res = 1;
    	for (int i = 1; i <= n + 1; i++)
    		res = (res + ans.mat[1][i]) % MOD;
    	cout << res << endl;
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