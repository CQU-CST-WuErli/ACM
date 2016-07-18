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
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Matrix {
	int n;
	unsigned long long mat[40][40];
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
	const static int maxn = 40;
	const static int maxm = 30;
	int cnt, root;
	int nxt[maxn][maxm];
	int have[maxn], fail[maxn];
	int ID_cnt;
	map<char, int> ID;
	int newNode() {
		for (int i = 0; i < maxm; i++)
			nxt[cnt][i] = -1;
		have[cnt] = 0;
		cnt++;
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
	void insert(char buf[]) {
		int now = root;
		int len = strlen(buf);
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
	Matrix buildMatrix() {
		Matrix ret; ret.init(cnt + 1);
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < 26; j++) {
				if (have[nxt[i][j]] == 0) {
					int u = i + 1, v = nxt[i][j] + 1;
					ret.mat[u][v]++;
				}
			}
		}
		for (int i = 1; i <= cnt + 1; i++)
			ret.mat[i][cnt + 1] = 1;
		return ret;
	}
}ac;
int n;
ll l;
char s[10];

unsigned long long ksm(unsigned long long a, unsigned long long x) {
	if (x == 0) return 1;
	unsigned long long ret = ksm(a, x / 2);
	ret =ret * ret;
	if (x & 1) ret = ret * a;
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (cin >> n >> l) {
    	ac.init();
    	for (int i = 1; i <= n; i++) {
    		scanf("%s", s);
    		ac.insert(s);
    	}
    	ac.build();
    	Matrix ans = ac.buildMatrix();
    	// ans.print();
    	ans = ans ^ l;
    	unsigned long long tmp = 0;
    	for (int i = 1; i <= ans.n; i++)
    		tmp += ans.mat[1][i];
    	// cout << tmp << endl;
    	Matrix all; all.init(2);
    	all.mat[1][1] = 26;
    	all.mat[1][2] = all.mat[2][2] = 1;
    	all = all ^ l;
    	unsigned long long sum = all.mat[1][1] + all.mat[1][2];
    	// cout << sum << endl;
    	cout << sum - tmp << endl;
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