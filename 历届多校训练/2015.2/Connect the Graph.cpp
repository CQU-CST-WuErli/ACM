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

int w[4], b[4];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SIII(w[0], w[1], w[2]);
        SIII(b[0], b[1], b[2]);
        if ((w[1] & 1) || (b[1] & 1)) {
        	puts("-1");
        	continue;
        }
        int n = w[0] + w[1] + w[2];
        if(n <= 4) {
             puts("4\n1 2 0\n1 3 0\n2 3 1\n3 4 1"); continue;
        }
        cout << w[2] + w[1] / 2 + b[2] + b[1] / 2 << endl;
        int pos = 1;
        for (int i = 1; i <= w[2] + 1; i++) {
        	printf("%d %d 0\n", pos, pos + 1);
        	pos++;
        }
        pos++; w[1] -= 2;
        for (int i = 1; i <= w[1]; i += 2) {
        	printf("%d %d 0\n", pos, pos + 1);
        	pos += 2;
        }
        vector<int> v;
        for (int i = 1; i <= n; i += 2) v.push_back(i);
        for (int i = 2; i <= n; i += 2) v.push_back(i);
        pos = 0;
        for (int i = 1; i <= b[2] + 1; i++) {
        	printf("%d %d 1\n", v[pos], v[pos + 1]);
        	pos++;
        }
        pos++; b[1] -= 2;
        for (int i = 1; i <= b[1]; i += 2) {
        	printf("%d %d 1\n", v[pos], v[pos + 1]);
        	pos += 2;
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