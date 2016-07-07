//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, m, k;
const int N = 100010;
int pnt[N], nxt[N], head[10010], cnt;

void add_edge(int u, int v) {
    pnt[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
}

int match[10010], used[10010];
vector<pair<int,int> > es;
int tu, tv;

bool find(int x) {
    for (int i = head[x]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if (used[v]) continue;
        if (match[v] == -1 ||  find(match[v])) {
            match[v] = x;
            return true;
        }
    }
    return false;
}

int hungary() {
    int ret = 0;
    OFF(match);
    for (int i = 1; i <= n; i++) {
        CLR(used);
        if (find(i)) ret++;
        // lookln(i);
    }
    return ret;
}

bool DFS(int x) {
	for (int i = head[x]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if (x == tu && v == tv) continue;
        if (used[v]) continue;
        if (match[v] == x) continue;
        if (match[v] == -1 ||  DFS(match[v])) {
            match[v] = x;
            return true;
        }
    }
    return false;
}

int gao() {
	int ret = 0;
    OFF(match);
    for (int i = 1; i <= n; i++) {
        CLR(used);
        if (DFS(i)) ret++;
    }
    return ret;
}

int b[10020];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int kase = 1;
    while(SIII(n, m, k) == 3) {
        OFF(head); cnt = 0; es.clear();
        for (int i = 1; i <= k; i++) {
            int u, v;
            SII(u, v);
            v += n;
            add_edge(u, v);
            es.push_back(make_pair(u, v));
        }
        tu = tv = -1;
        int L = hungary();
        int C = 0;
        memcpy(b, match, sizeof match);
        for (int i = 0; i < es.size(); i++) {
            int u = es[i].first, v = es[i].second;
            if (b[v] == u) {
                tu = u, tv = v;
                // cout << tu << ' ' << tv << endl;
                if (gao() != L) C++;
            }
        }
        cout << "Board " << kase++ << " have " << C << " important blanks for " << L << " chessmen." << endl;
    }
    return 0;
}