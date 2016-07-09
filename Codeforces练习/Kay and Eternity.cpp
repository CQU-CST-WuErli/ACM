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

const int N = 100010;

int n, k;
int cnt[N << 1];
ll ans[N];
int pre[N << 1];
int x[N], y[N];
vector<int> Hash;
struct Query {
	int l, r, y, flag;
	Query(int l, int r, int y, int flag):l(l), r(r), y(y), flag(flag) {}
	Query() {}
	bool operator < (const Query& rhs) const {
		return y < rhs.y;
	}
};
vector<Query> qs;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    SII(n, k);
    for (int i = 1; i <= n; i++)
    	SII(x[i], y[i]);
    CLR(cnt); CLR(ans);
    for (int i = 1; i <= 2 * n; i++)
    	pre[i] = -INF_INT;

    Hash.push_back(-INF_INT);
    for (int i = 1; i <= n; i++) {
    	Hash.push_back(x[i]);
    	Hash.push_back(x[i] + k);
    }
    sort(Hash.begin(), Hash.end());
    Hash.resize(unique(Hash.begin(), Hash.end()) - Hash.begin());
    for (int i = 1; i <= n; i++) {
    	int l = upper_bound(Hash.begin(), Hash.end(), x[i]) - Hash.begin();
    	int r = lower_bound(Hash.begin(), Hash.end(), x[i] + k) - Hash.begin();
    	qs.push_back(Query(l, r, y[i], 1));
    	qs.push_back(Query(l, r, y[i] + k, -1));
    }
    sort(qs.begin(), qs.end());

    for (auto & q : qs) {
    	for (int i = q.l; i <= q.r; i++) {
    		ans[cnt[i]] += 1ll * (Hash[i] - Hash[i - 1]) * (q.y - pre[i]);
    		cnt[i] += q.flag;
    		pre[i] = q.y;
    	}
    }
    for (int i = 1; i <= n; i++)
    	printf("%I64d ", ans[i]);
    puts("");
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