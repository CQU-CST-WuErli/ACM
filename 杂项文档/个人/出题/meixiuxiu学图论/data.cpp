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
#include <ctime>
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

int n, m;
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
    Edge() {}
};
vector<Edge> es;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    // freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    freopen("input.txt","w",stdout);
#endif
    srand(time(0));
    int t = 40;
    cout << t << endl;
    int maxn = 5e5;
    int maxm = 2e6;
    for (int ca = 1; ca <= t; ca++) {
        es.clear();
    	n = rand() % maxn + 1;
        while (n < 3) n = rand() % maxn + 1;
        m = rand() % maxm + 1;
        while (m < n - 1 || m > n * (n - 1) / 2) m = rand() % maxm + 1;
        if (ca == 2 || ca == 7 || ca == 16 || ca == 39) m = n - 1;
        cout << n << ' ' << m << endl;
        for (int i = 1; i < n; i++) {
            int u = i;
            int v = i + 1;
            int w = rand() % 5000 + 1;
            cout << u << ' ' << v << ' ' << w << endl;
        }
        for (int i = n; i <=m; i++) {
            int u = rand() % n + 1;
            int v = rand() % n + 1;
            while (u == v) v = rand() % n + 1;
            int w = rand() % 5000 + 1;
            cout << u << ' ' << v << ' ' << w << endl;
        }
    }
	return 0;
}
