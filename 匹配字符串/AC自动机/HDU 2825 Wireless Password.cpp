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
#include <bitset>
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
const int MOD=20090717;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n, m, k;
char s[22];
int dp[30][110][(1 << 10) + 1];
int num[(1 << 10) + 1];

struct ACAutoMaton {
	const static int maxn = 120;
	const static int maxm = 26;
	int cnt, root;
	int nxt[maxn][maxm];
	int have[maxn], fail[maxn];
	int ID_cnt;
	map<char, int> ID;
	int newNode() {
		for (int i = 0; i < 26; i++)
			nxt[cnt][i] = -1;
		have[cnt++] = 0;
		return cnt - 1;
	}
	void init() {
		cnt = ID_cnt = 0;
		root = newNode();
		ID.clear();
	}
	int getID(char x) {
		return x - 'a';
	}
	void insert(char buf[], int pos) {
		int now = root;
		int len = strlen(buf);
		for (int i = 0; i < len; i++) {
			int id = getID(buf[i]);
			if (nxt[now][id] == -1) nxt[now][id] = newNode();
			now = nxt[now][id];
		}
		have[now] |= (1 << pos);
	}
	void build() {
		fail[root] = root;
		queue<int> q;
		for (int i = 0; i < maxm; i++) {
			if (nxt[root][i] == -1)
				nxt[root][i] = root;
			else {
				fail[nxt[root][i]] = root;
				q.push(nxt[root][i]);
			}
		}
		while (q.size()) {
			int u = q.front(); q.pop();
			have[u] |= have[fail[u]];
			for (int i = 0; i < 26; i++) {
				int& v = nxt[u][i];
				if (v == -1) {
					v = nxt[fail[u]][i];
				}
				else {
					fail[v] = nxt[fail[u]][i];
					q.push(v);
				}
			}
		}
	}
	void pre() {
		for (int i = 0; i < (1 << 10); i++) {
			num[i] = 0;
			for (int j = 0; j < 10; j++)
				if ((i >> j) & 1) num[i]++;
		}
	}
	int solve() {
		pre();
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < cnt; j++) {
				for (int k = 0; k < (1 << m); k++)
					dp[i][j][k] = 0;
			}
		}
		dp[0][0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < cnt; j++) {
				for (int k = 0; k < (1 << m); k++) if (dp[i][j][k]) {
					for (int ch = 0; ch < 26; ch++) {
						dp[i + 1][nxt[j][ch]][k | have[nxt[j][ch]]] += dp[i][j][k];
						dp[i + 1][nxt[j][ch]][k | have[nxt[j][ch]]] %= MOD;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < (1 << m); i++) {
			if (num[i] < k) continue;
			for (int j = 0; j < cnt; j++) {
				ans += dp[n][j][i];
				ans %= MOD;
			}
		}
		return ans;
	}
}ac;


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SIII(n, m, k) == 3 && (n || m || k)) {
    	ac.init();
    	for (int i = 1; i <= m; i++) {
    		scanf("%s", s);
    		ac.insert(s, i - 1);
    	}
    	ac.build();
    	printf("%d\n", ac.solve());
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