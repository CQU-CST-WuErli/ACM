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

char s[1010][55];
char t[2000020];
int n;
int sum[1010];

struct ACAutoMaton {
	const static int maxn = 1e5;
	const static int maxm = 30;
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
		if (x < 'A' || x > 'Z') return -1;
		return x - 'A';
	}
	void insert(char buf[], int pos) {
		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; i++) {
			int id = getID(buf[i]);
			if (nxt[now][id] == -1) nxt[now][id] = newNode();
			now = nxt[now][id];
		}
		have[now] = pos;
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
			for (int i = 0; i < maxm; i++) {
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
	void find(char buf[]) {
		int now = root;
		int len = strlen(buf);
		for (int i = 0; i < len; i++) {
			int id = getID(buf[i]);
			if (id == -1) {
				now = root;
				continue;
			}
			now = nxt[now][id];
			int tmp = now;
			while (tmp != root) {
				if (have[tmp])
					sum[have[tmp]]++;
				tmp = fail[tmp];
			}
		}
	}
}ac;


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	ac.init();
    	for (int i = 1; i <= n; i++) {
    		scanf("%s", s[i]);
    		ac.insert(s[i], i);
    	}
    	ac.build();
    	scanf("%s", t);
    	CLR(sum);
    	ac.find(t);
    	for (int i = 1; i <= n; i++) {
    		if (sum[i])
    			printf("%s: %d\n", s[i], sum[i]);
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