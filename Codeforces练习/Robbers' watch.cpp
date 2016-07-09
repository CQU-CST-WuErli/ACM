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

ll n, m, ans = 0;
int a[20], b[20], cnt1 = 0, cnt2 = 0, vis[10];
ll fn, fm;
ll p[25];


void DFS2(int po,ll num) {
    if(po > cnt2) {
        if(num < fm) ans++;
        return;
    }
    for(int i = 0; i < 7; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            DFS2(po + 1, num + (ll)i * p[po]);
            vis[i] = 0;
        }
    }
}

void DFS1(int po, ll num) {
    if(po > cnt1) {
        if(num < fn) DFS2(1, 0);
        return;
    }
    for(int i = 0; i < 7; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            DFS1(po + 1, num + (ll)i * p[po]);
            vis[i] = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	// freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	SII(n, m);
	fn = n, fm = m;
	if(n > 1) n--;
    if(m > 1) m--;
    ll w = 1;
    for(int i = 1; i < 25;i++) {
    	p[i] = w;
    	w = w * 7;
    }
    while(n) {
	    a[++cnt1] = n % 7;
    	n/=7;
	}
    while(m) {
	    b[++cnt2]=m%7;
		m/=7;
    }
	CLR(vis);
    ans = 0;
    DFS1(1, 0);
	cout<< ans << endl;
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