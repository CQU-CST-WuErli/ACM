
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
const int MOD=100000;
typedef long long  ll;
using namespace std;

int m;
ll n;
char s[11];

struct Matrix {
	int n;
	ll mat[110][110];
	void init(int _n) {
		n = _n;
		memset(mat, 0, sizeof(mat));
	}
	void unit(int _n) {
		n = _n;
		memset(mat, 0, sizeof mat);
		for (int i = 1; i <= n; i++)
			mat[i][i] = 1;
	}
	Matrix operator * (const Matrix& rhs) {
		Matrix ret;
		ret.init(n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					ret.mat[i][j] += mat[i][k] * rhs.mat[k][j];
				}
				ret.mat[i][j] %= MOD;
			}
		}
		return ret;
	}
	Matrix operator ^ (ll x) {
		Matrix ret; ret.unit(n);
		Matrix ans = *this;
		while (x) {
			if (x & 1) ret = ret * ans;
			ans = ans * ans;
			x >>= 1;
		}
		return ret;
	}
	void print() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << mat[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

struct ACAutoMaton {
	const static int maxn = 1e4;
	const static int maxm = 10;
	int have[maxn], fail[maxn];
	int nxt[maxn][maxm];
	int cnt, root;
	int ID_cnt;
	map<char, int> ID;
	int newNode() {
		for (int i = 0; i < maxm; i++)
			nxt[cnt][i] = -1;
		have[cnt++] = 0;
		return cnt - 1;
	}
	void init() {
		cnt = ID_cnt = 0;
		ID.clear();
		root = newNode();
	}
	int getID(char x) {
		if (x == 'A') return 1;
		else if (x == 'T') return 2;
		else if (x == 'G') return 3;
		else if (x == 'C') return 4;
	}
	void insert(char buf[], int pos) {
		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; i++) {
			int id = getID(buf[i]);
			if (nxt[now][id] == -1) nxt[now][id] = newNode();
			now = nxt[now][id];
		}
		have[now] = 1;
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
			if (have[fail[u]]) have[u] = 1; // Attention !!!
			for (int i = 0; i < maxm; i++) {
				int& v = nxt[u][i];
				if (have[u] == 1) have[v] = 1;
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
	Matrix buildMatrix() {
		Matrix ret;
		ret.init(cnt);
		for (int i = 0; i < cnt; i++) {
			for (int j = 1; j <= 4; j++) {
				if (have[nxt[i][j]] == 0) {
					int u = i + 1, v = nxt[i][j] + 1;
					ret.mat[u][v]++;
				}
			}
		}
		return ret;
	}
}ac;



int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (cin >> m >> n) {
    	ac.init();
    	for (int i = 1; i <= m; i++) {
    		scanf("%s", s);
    		ac.insert(s, 1);
    	}
    	ac.build();
    	// lookln(ac.cnt);
    	Matrix ans = ac.buildMatrix();
    	// ans.print();
    	ans = ans ^ (n);
    	// ans.print();
    	ll res = 0;
    	for (int i = 1; i <= ans.n; i++)
    		res = (res + ans.mat[1][i]) % MOD;
    	cout << res % MOD << endl;
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