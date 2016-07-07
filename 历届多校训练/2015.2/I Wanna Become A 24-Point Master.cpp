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

int n;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	// cout << n << endl;
    	if (n <= 3) cout << -1 << endl;
    	else if (n <= 9) {
    		switch (n) {
    			case 4: {
    				puts("1 * 2");
    				puts("5 + 3");
    				puts("6 + 4");
    				break;
    			}
    			case 5: {
    				puts("1 * 2");
    				puts("6 * 3");
    				puts("7 - 4");
    				puts("8 / 5");
    				break;
    			}
    			case 6: {
    				puts("1 + 2");
    				puts("7 + 3");
    				puts("8 + 4");
    				puts("9 + 5");
    				puts("10 - 6");
    				break;
    			}
    			case 7: {
    				puts("1 + 2");
    				puts("8 + 3");
    				puts("9 / 4");
    				puts("5 / 6");
    				puts("11 + 7");
    				puts("12 * 10");
    				break;
    			}
    			case 8: {
    				puts("1 * 2");
    				puts("3 + 4");
    				puts("10 / 5");
    				puts("9 / 11");
    				puts("12 - 6");
    				puts("13 + 7");
    				puts("14 - 8");
    				break;
    			}
    			case 9: {
    				puts("1 + 2");
    				puts("10 + 3");
    				puts("11 / 4");
    				puts("5 / 6");
    				puts("7 - 13");
    				puts("12 * 14");
    				puts("15 + 8");
    				puts("16 - 9");
    				break;
    			}
    		}
    	}
    	else if (n <= 15) {
    		int last = n;
    		int now = 0;
    		now++; cout << now << " + " << now + 1 << endl; now++; last++;
    		now++; cout << last << " + " << now << endl; last++;
    		now++; cout << last << " / " << now << endl; last++;
    		int tmp = last;
    		// 3
    		now++; cout << now << " + " << now + 1 << endl; now++; last++;
    		for (int i = 1; i <= n - 8 - 2; i++) {
    			now++; cout << last << " + " << now << endl; last++;
    		}
    		now++; cout << last << " / " << now << endl; last++;
    		now++; cout << now << " - " << last << endl; last++;
    		cout << tmp << " * " << last << endl; last++;
    		now++; cout << last << " + " << now << endl; last++;
    		now++; cout << last << " - " << now << endl; last++;
    	}
    	else {
    		int a[6];
    		int now = 0, last = n;
    		for (int i = 1; i <= 3; i++) {
    			now++; cout << now << " + " << now + 1 << endl; now++; last++;
    			now++; cout << last << " / " << now << endl; last++;
    			a[i] = last;
    		}
    		//2
    		now++; cout << now << " + " << now + 1 << endl; now++; last++;
    		now++; cout << now << " + " << last << endl; last++;
    		now++; cout << last << " / " << now << endl; last++;
    		a[4] = last;
    		// 3
    		cout << a[1] << " * " << a[2] << endl; last++;
    		cout << last << " * " << a[3] << endl; last++;
    		cout << last << " * " << a[4] << endl; last++;
    		a[5] = last;
    		// 24
    		now++; cout << now << " - " << now + 1 << endl; now++; last++;
    		// 0
    		for (int i = 1; i <= n - 15; i++) {
    			now++; cout << now << " * " << last << endl; last++;
    		}
    		cout << a[5] << " + " << last << endl;
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