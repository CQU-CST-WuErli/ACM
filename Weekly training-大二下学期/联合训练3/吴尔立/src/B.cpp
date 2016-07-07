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

int mp[10][10];
vector<int> g[10];
int deg[10];
int vis[10];

bool toposort() {
	queue<int> q;
	CLR(vis);
	int cnt = 9;
	for (int i = 1; i <= 9; i++) {
		if (deg[i] == 0) {
			q.push(i);
			vis[i] = 1;
			cnt--;
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = 0; i <g[x].size(); i++) {
			int v = g[x][i];
			if (vis[v]) continue;
			if (--deg[v] == 0) {
				q.push(v);
				cnt--;
				vis[v] = 1;
			}
		}
	}
	return cnt == 0;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        for (int i = 1; i <= 4; i++) {
        	for (int j = 1; j <= 4; j++) {
        		SI(mp[i][j]);
        	}
        }
        CLR(deg);
        for (int i = 1; i <= 9; i++) g[i].clear();
        for (int i = 1; i <= 3; i++) {
        	for (int j = 1; j <= 3; j++) {
        		int id = (i - 1) * 3 + j;
        		for (int s = 0; s < 2; s++) {
        			for (int k = 0; k < 2; k++) {
        				if (mp[i + s][j + k] != id) {
        					g[id].push_back(mp[i + s][j + k]);
        					deg[mp[i + s][j + k]]++;
        				}

        			}
        		}
        	}
        }
        // BUG;
        if (toposort()) puts("Lucky dog!");
        else puts("BOOM!");
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