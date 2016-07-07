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

map<int, int> block[350];
int n, m;
int cor[350];
int aa[100010];
int size[350];
int sz;

void init() {
	sz = (int)sqrt(n);
	OFF(aa);
	for (int i = 0; i < 350; i++) {
		size[i] = min(n, (i + 1) * sz) - i * sz;
		cor[i] = -1;
		block[i].clear();
	}
	for (int i = 0; i < n; i++) {
    	SI(aa[i]);
    	block[i / sz][aa[i]]++;
    }
}

void push_down(int id) {
	if (cor[id] != -1) {
		block[id].clear();
		for (int i = id * sz; i < min((id + 1) * sz, n); i++) {
			aa[i] = cor[id];
			block[id][aa[i]]++;
		}
		cor[id] = -1;
	}
}

void update(int l, int r, int c) {
	int lid = l / sz, rid = r / sz;
	for (int i = lid + 1; i < rid; i++)
		cor[i] = c;
	if (lid != rid) {
		push_down(lid);
		int tmp = (lid + 1) * sz;
		for (int i = l; i < tmp; i++) {
			block[lid][aa[i]]--;
			block[lid][c]++;
			aa[i] = c;
		}
		push_down(rid);
		for (int i = rid * sz; i <= r; i++) {
			block[rid][aa[i]]--;
			block[rid][c]++;
			aa[i] = c;
		}
	}
	else {
		push_down(lid);
		for (int i = l; i <= r; i++) {
			block[lid][aa[i]]--;
			block[lid][c]++;
			aa[i] = c;
		}
	}
}

int query(int l, int r, int c) {
	int lid = l / sz, rid = r / sz;
	int ret = 0;
	for (int i = lid + 1; i < rid; i++) {
		if (cor[i] == c) ret += size[i];
		else if (cor[i] == -1 && block[i].find(c) != block[i].end())
			ret += block[i][c];
	}
	if (lid != rid) {
		push_down(lid);
		int tmp = (lid + 1) * sz;
		for (int i = l; i < tmp; i++)
			ret += (aa[i] == c);
		push_down(rid);
		for (int i = rid * sz; i <= r; i++)
			ret += (aa[i] == c);
	}
	else {
		push_down(lid);
		for (int i = l; i <= r; i++)
			ret += (aa[i] == c);
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, m) == 2) {

    	init();

    	int op, a, b, c;
    	while(m--) {
    	    SI(op);
    	    SIII(a, b, c);
    	    if (op == 1) {
    	    	update(a, b, c);
    	    }
    	    else if (op == 2) {
    	    	printf("%d\n", query(a, b, c));
    	    }
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