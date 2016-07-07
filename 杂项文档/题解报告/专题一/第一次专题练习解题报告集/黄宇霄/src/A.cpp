//
//  Created by Running Photon on 2016-05-02
//  Copyright (c) 2015 Running Photon. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x,begin())
#define ll long long
#define CLR(x) memset(x, 0, sizeof x)
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 10;
const int maxv = 1e3 + 10;
const int maxw = 31;
const double eps = 1e-9;

int digit[33];
int nxt[maxn * 12][2];
int vis[maxn * 12];
void print() {
    for(int i = 0; i < maxw; i++) {
        printf("%d", digit[i]);
    }
    puts("");
}
struct Trie {
    int cnt, root;
    int newNode() {
        nxt[cnt][0] = nxt[cnt][1] = -1;
        return cnt++;
    }
    void init() {
        cnt = 0;
        memset(vis, 0, sizeof vis);
        root = newNode();
    }
    void insert(int num[]) {
        int now = root;
        for(int i = 0; i < maxw; i++) {
            int v = num[i];
            if(nxt[now][v] == -1) nxt[now][v] = newNode();
            now = nxt[now][v];
            vis[now]++;
//            printf("%d ", vis[now]);
        }
//        puts("");
    }
    int get(int num[]) {
        int res = 0;
        int now = root;
        for(int i = 0; i < maxw; i++) {
            int v = !num[i];
            if(nxt[now][v] == -1 || !vis[nxt[now][v]]) {
                res <<= 1;
                now = nxt[now][!v];
            }
            else {
                res = res * 2 + 1;
                now = nxt[now][v];
            }
        }
        return res;
    }
    void chenge(ll num[], int flag) {
        int now = root;
        for(int i = 0; i < maxw; i++) {
            int v = num[i];
            vis[nxt[now][v]] += flag;
            now = nxt[now][v];
//            printf("%d ", vis[now]);
        }
//        puts("");
        return;
    }
};
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T; scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        Trie ac;
        ac.init();
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            int top = 0;
            for(int j = 0; j < 31; j++) {
                digit[j] = (x >> (30 - j)) & 1;
            }
//            print();
            ac.insert(digit);
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            int top = 0;
            for(int j = 0; j < 31; j++) {
                digit[j] = (x >> (30 - j)) & 1;
            }
//            print();
            res = max(res, ac.get(digit));
        }
        printf("%d\n", res);
    }

	return 0;
}
