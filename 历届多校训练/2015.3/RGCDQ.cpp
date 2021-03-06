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


int f[1000100];
int sum[1000010][8];

void init() {
	CLR(f);
	for (int i = 2; i <= 1000000; i++) if (!f[i]) {
		f[i] = 1;
		for (int j = i + i; j <= 1000000; j += i)
			f[j]++;
	}
	CLR(sum);
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 1; j <= 7; j++)
			sum[i][j] = sum[i - 1][j];
		sum[i][f[i]]++;
	}

}

int query(int l, int r) {
	int a[8];
	for (int i = 1; i <= 7; i++)
		a[i] = sum[r][i] - sum[l - 1][i];
	if (a[7] >= 2) return 7;
	else if (a[6] >= 2) return 6;
	else if (a[5] >= 2) return 5;
	else if (a[4] >= 2) return 4;
	else if (a[3] >= 2 || (a[3] && a[6])) return 3;
	else if (a[2] >= 2 || (a[2] && a[4]) || (a[2] && a[6]) || (a[4] && a[6])) return 2;
	else return 1;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    int n; SI(n);
    for (int i = 1; i <= n; i++) {
    	int l, r; SII(l, r);
    	cout << query(l, r) << endl;
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