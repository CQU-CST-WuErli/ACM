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

char a[100010], b[100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t; SI(t);
	while (t--) {
		scanf("%s%s", a, b);
		int lena = strlen(a), lenb = strlen(b);
		if (lena == lenb) {
			int flag = 1;
			for (int i = 0; i < lena; i++) {
				if (a[i] != b[i]) {
					flag = 0;
					break;
				}
			}
			puts(flag ? "Yes" : "No");
		}
		else {
			if (a[0] != b[0]) {
				puts("No");
				continue;
			}
			int i = 0, j = 0;
    		for(j = 1; j < lenb; j++) if (b[j] != b[j - 1]) break;
    		for(; i < j; i++){
    			if(a[i] != b[i])
    				break;
    		}
    		if(i != j) {
    			puts("No");
    			continue;
    		}
    		int left = lena-i;
    		for(; i < lena; i++){
    			for(; j < lenb; j++){
    				if(a[i] == b[j]){
    					left--;
    					break;
    				}
    			}
    		}
    		puts(left ? "No" : "Yes");
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