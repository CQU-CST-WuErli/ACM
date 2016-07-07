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
#include <ctime>
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

int hate[1001][1010];

int main(int argc, char const *argv[]) {
    freopen("input.txt","w",stdout);
    srand(time(0));
    int t = 30;
    int n, A, B;
    int maxn = 1000;
    cout << t << endl;
    for (int i = 1; i <= t ; i++) {
    	CLR(hate);
		n = rand() % maxn + 1;
		while (n < 3) n = rand() % maxn + 1;
		A = rand() % (n/2) + 1;
		B = rand() % (n/2) + 1;
		cout << n << ' ' << A << ' ' << B << endl;
		int x1, y1, x2, y2;
		x1 = rand() % 1000000;
		y1 = rand() % 1000000;
    	x2 = rand() % 1000000;
    	y2 = rand() % 1000000;
    	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    	for (int j = 1; j <= n; j++) {
    		x1 = rand() % 1000000;
			y1 = rand() % 1000000;
			cout << x1 << ' ' << y1 << endl;
    	}
    	for (int j = 1; j <= A; j++) {
    		int a, b;
    		a = rand() % n + 1;
    		b = rand() % n + 1;
    		while (a == b || hate[a][b] || hate[b][a]) {
    			a = rand() % n + 1;
    			b = rand() % n + 1;
    		}
    		hate[a][b] = hate[b][a] = 1;
    		cout << a << ' ' << b << endl;
    	}
    	for (int j = 1; j <= B;j ++) {
    		int a, b;
    		a = rand() % n + 1;
    		b = rand() % n + 1;
    		while (a == b || hate[a][b] || hate[b][a]) {
    			a = rand() % n + 1;
    			b = rand() % n + 1;
    		}
    		hate[a][b] = hate[b][a] = 1;
    		cout << a << ' ' << b << endl;
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