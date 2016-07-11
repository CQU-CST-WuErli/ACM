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

int n, k;
char mp[555][555];
int vis[555][555];
int size[555 * 555];
int tid[555 * 555];
int cnt;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int sum;

void dfs(int x, int y) {
	vis[x][y] = cnt;
	sum++;
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0], ty = y + dir[i][1];
		if (tx < 1 || ty < 1 || tx > n || ty > n || mp[tx][ty] == 'X' || vis[tx][ty]) continue;
		dfs(tx, ty);
	}
}

void add(int x, int y, int ti, int& ans) {
    if (x < 1 || x > n || y < 1 || y > n || mp[x][y] == 'X') return;
    if (tid[vis[x][y]] != ti) {
        ans += size[vis[x][y]];
        tid[vis[x][y]] = ti;
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, k) ==2) {
        for (int i = 1; i <= n; i++)
        	scanf("%s", mp[i] + 1);
        CLR(vis);
        CLR(size);
        CLR(tid);
        int ti = 1;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
        	for (int j = 1; j <= n; j++) if (mp[i][j] == '.' && !vis[i][j]) {
        		cnt++;
        		sum = 0;
        		dfs(i, j);
        		size[cnt] = sum;
        	}
        }
        int ans = 0;
        for (int y = 1; y + k - 1<= n; y++) {
            for (int x = 1; x <= k; x++) {
                for (int i = 0; i < k; i++) {
                    size[vis[x][y + i]]--;
                }
            }
            for (int x = 1; x + k - 1<= n; x++) {
                int tmp = k * k;
                for (int i = x; i < x + k; i++) {
                    add(i, y - 1, ti, tmp);
                    add(i, y + k, ti, tmp);
                }
                for (int i = y; i < y + k; i++) {
                    add(x - 1, i, ti, tmp);
                    add(x + k, i, ti, tmp);
                }
                ti++;
                ans = max(tmp, ans);
                if (x + k <= n) {
                    for (int i = y; i < y + k; i++) {
                        size[vis[x][i]]++;
                        size[vis[x + k][i]]--;
                    }
                }
            }
            for (int i = n - k + 1; i <= n; i++) {
                for (int j = y; j < y + k; j++) {
                    size[vis[i][j]]++;
                }
            }
        }
        cout << ans << endl;
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