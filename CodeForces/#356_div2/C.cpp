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

int isprime[110];
vector<int> prime;

void init() {
	CLR(isprime);
	isprime[2] = 1;
	prime.push_back(2);
	for (int i = 3; i <= 100; i++) {
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		isprime[i] = flag;
		if (flag) prime.push_back(i);
	}
}


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
   	int flag = 0;
   	int cnt = 0;
   	// for (int i = 0; i < 20; i++) cout << prime[i] << endl;
   	// cout << "ss" << endl;
   	for (int i = 0; i < 20; i++) {
   		if (cnt >= 20) break;
   		printf("%d\n", prime[i]);
   		cnt++;
   		fflush(stdout);
   		char s[10];
   		scanf("%s", s);
   		if (s[0] == 'y') {
   			flag++;
   			if (cnt >= 20) break;
   			int tmp = prime[i] * prime[i];
   			if (tmp > 100) continue;
   			printf("%d\n",tmp);
   			cnt++;
   			fflush(stdout);
   			char t[10];
   			scanf("%s", t);
   			if (t[0] == 'y') {
   				flag++; break;
   			}
   		}
   		if (flag >= 2 || cnt >= 20) break;
   	}
   	if (flag <= 1) printf("prime\n");
   	else printf("composite\n");
   	fflush(stdout);

   	// for (int ca = 2; ca <= 100; ca++) {
   	//    	int flag = 0;
   	// 	int cnt = 0;
   	// 	for (int i = 0; i < 20; i++) {
   	// 		cnt++;
   	// 		if (ca % prime[i] == 0 && prime[i] <= ca) {
   	// 			flag++;
   	// 			if (cnt >= 20) break;
   	// 			int tmp = prime[i] * prime[i];
   	// 			if (tmp > 100) break;
   	// 			cnt++;
   	// 			if (tmp <= ca && ca % tmp == 0) {
   	// 				flag++; break;
   	// 			}
   	// 		}
   	// 		if (flag >= 2 || cnt >= 20) break;
   	// 	}
   	// 	if (flag <= 1 && !isprime[ca]) cout << ca << endl;
   	// 	else if (flag > 1 && isprime[ca]) cout << ca << endl;
   	// }
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