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

const int N = 1010;
const double lg2 = log(2);
const double lg3 = log(3);
int n;
char a[N][N];

double logs[N][N];
double L[N][N], R[N][N], U[N][N], D[N][N];
double LU[N][N], RU[N][N], LD[N][N], RD[N][N];

int preL[N][N], preR[N][N], preU[N][N], preD[N][N];
int preLU[N][N], preRU[N][N], preLD[N][N], preRD[N][N];

void gao() {
	CLR(L);
	CLR(preL);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (a[i][j] != '0') {
			if (j == 1 || a[i][j - 1] == '0') {
				L[i][j] = logs[i][j];
				preL[i][j] = 1;
			}
			else {
				L[i][j] = L[i][j - 1] + logs[i][j];
				preL[i][j] = preL[i][j - 1] + 1;
			}
		}
	}
	CLR(R);
	CLR(preR);
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) if (a[i][j] != '0') {
			if (j == n || a[i][j + 1] == '0') {
				R[i][j] = logs[i][j];
				preR[i][j] = 1;
			}
			else {
				R[i][j] = R[i][j + 1] + logs[i][j];
				preR[i][j] = preR[i][j + 1] + 1;
			}
		}
	}
	CLR(U);
	CLR(preU);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (a[i][j] != '0') {
			if (i == 1 || a[i - 1][j] == '0')  {
				U[i][j] = logs[i][j];
				preU[i][j] = 1;
			}
			else {
				U[i][j] = U[i - 1][j] + logs[i][j];
				preU[i][j] = preU[i - 1][j] + 1;
			}
		}
	}
	CLR(D);
	CLR(preD);
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= n; j++) if (a[i][j] != '0') {
			if (i == n || a[i + 1][j] == '0') {
				D[i][j] = logs[i][j];
				preD[i][j] = 1;
			}
			else {
				D[i][j] = D[i + 1][j] + logs[i][j];
				preD[i][j] = preD[i + 1][j] + 1;
			}
		}
	}
	CLR(LU);
	CLR(preLU);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (a[i][j] != '0') {
			if (i == 1 || j == 1 || a[i - 1][j - 1] == '0') {
				LU[i][j] = logs[i][j];
				preLU[i][j] = 1;
			}
			else {
				LU[i][j] = LU[i - 1][j - 1] + logs[i][j];
				preLU[i][j] = preLU[i - 1][j - 1] + 1;
			}
		}
	}
	CLR(RU);
	CLR(preRU);
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) if (a[i][j] != '0') {
			if (i == 1 || j == n || a[i - 1][j + 1] == '0') {
				RU[i][j] = logs[i][j];
				preRU[i][j] = 1;
			}
			else {
				RU[i][j] = RU[i - 1][j + 1] + logs[i][j];
				preRU[i][j] = preRU[i - 1][j + 1] + 1;
			}
		}
	}
	CLR(LD);
	CLR(preLD);
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= n; j++) if (a[i][j] != '0') {
			if (i == n || j == 1 || a[i + 1][j - 1] == '0') {
				LD[i][j] = logs[i][j];
				preLD[i][j] = 1;
			}
			else {
				LD[i][j] = LD[i + 1][j - 1] + logs[i][j];
				preLD[i][j] = preLD[i + 1][j - 1] + 1;
			}
		}
	}
	CLR(RD);
	CLR(preRD);
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) if (a[i][j] != '0') {
			if (i == n || j == n || a[i + 1][j + 1] == '0') {
				RD[i][j] = logs[i][j];
				preRD[i][j] = 1;
			}
			else {
				RD[i][j] = RD[i + 1][j + 1] + logs[i][j];
				preRD[i][j] = preRD[i + 1][j + 1] + 1;
			}
		}
	}
}

template <typename T>
void print(T a[][N]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	CLR(logs);
    	for (int i = 1; i <= n; i++)
    		scanf("%s", a[i] + 1);
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			if (a[i][j] == '0') logs[i][j] = -1;
    			else if (a[i][j] == '1') logs[i][j] = 0;
    			else if (a[i][j] == '2') logs[i][j] = lg2;
    			else if (a[i][j] == '3') logs[i][j] = lg3;
    		}
    	}
    	gao();
    	// print(RD);
    	double ans = -1;
    	pair<int, int> pos;
    	int flag = 0;
    	int Len;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) if (a[i][j] != '0') {
    			double tmp = 0;
    			int len = min(min(preL[i][j], preR[i][j]), min(preU[i][j], preD[i][j]));
    			tmp += L[i][j] - L[i][j - len];
    			tmp += R[i][j] - R[i][j + len];
    			tmp += U[i][j] - U[i - len][j];
    			tmp += D[i][j] - D[i + len][j];
    			tmp -= 3 * logs[i][j];
    			if (tmp > ans) {
    				ans = tmp;
    				pos = make_pair(i, j);
    				// cout << i << ' ' << j << ' ' << len << ' ' << tmp << endl;
    				flag = 1;
    				Len = len;
    			}
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) if (a[i][j] != '0') {
    			double tmp = 0;
    			int len = min(min(preLD[i][j], preRD[i][j]), min(preLU[i][j], preRU[i][j]));
    			tmp += LU[i][j] - LU[i - len][j - len];
    			tmp += RU[i][j] - RU[i - len][j + len];
    			tmp += LD[i][j] - LD[i + len][j - len];
    			tmp += RD[i][j] - RD[i + len][j + len];
    			tmp -= 3 * logs[i][j];
    			if (tmp > ans) {
    				ans = tmp;
    				// cout << i << ' ' << j << ' ' << len << ' ' << tmp << endl;
    				pos = make_pair(i, j);
    				flag = 2;
    				Len = len;
    			}
    		}
    	}
    	// cout << pos.first << ' ' << pos.second << endl;
    	// cout << flag << endl;
    	// cout << Len << endl;
    	if (ans == -1) {
    		cout << 0 << endl;
    		continue;
    	}
    	int x = pos.first, y = pos.second;
    	ll tmp = 1;
    	if (flag == 1) {
    		for (int i = 1; i < Len; i++) {
    			tmp = tmp * (a[x][y - i] - '0') % MOD;
    			tmp = tmp * (a[x][y + i] - '0') % MOD;
    			tmp = tmp * (a[x - i][y] - '0') % MOD;
    			tmp = tmp * (a[x + i][y] - '0') % MOD;
    		}
    		tmp = tmp * (a[x][y] - '0') % MOD;
    	}
    	else {
    		for (int i = 1; i < Len; i++) {
    			tmp = tmp * (a[x - i][y - i] - '0') % MOD;
    			tmp = tmp * (a[x - i][y + i] - '0') % MOD;
    			tmp = tmp * (a[x + i][y - i] - '0') % MOD;
    			tmp = tmp * (a[x + i][y + i] - '0') % MOD;
    		}
    		tmp = tmp * (a[x][y] - '0') % MOD;
    	}
    	cout << tmp << endl;
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