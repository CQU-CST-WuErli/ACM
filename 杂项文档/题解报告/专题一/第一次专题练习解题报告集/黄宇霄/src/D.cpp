//
//  Created by Running Photon on 2016-05-11
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
const double eps = 1e-9;

struct Matrix {
    int u, r, d, l;
    void read() {
        scanf("%d%d%d%d", &u, &r, &d, &l);
    }
    bool operator== (const Matrix &rhs) const {
        return u == rhs.u && r == rhs.r && d == rhs.d && l == rhs.l;
    }
    void print() {
        printf("%d %d %d %d\n", u, r, d, l);
    }
}p[30], num[30];
int n, top, N;
int vis[30];
bool check(int id, int dep) {
    int flagl = 1;
    int flagu = 1;
    if(dep % n) {
        if(p[id].l != num[dep - 1].r) flagl = 0;
    }
    if(dep - n >= 0) {
        if(p[id].u != num[dep - n].d) flagu = 0;
    }
    return flagl && flagu;
}
bool dfs(int dep) {
    if(dep == top) {
        return true;
    }
    for(int i = 0; i < N; i++) {
        if(!vis[i]) continue;
        if(!check(i, dep)) continue;
        vis[i]--;
        num[dep] = p[i];
        if(dfs(dep+1)) return true;
        vis[i]++;
    }
    return false;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        top = n * n;
        vector <Matrix> vec;
        CLR(vis);
        for(int i = 0; i < top; i++) {
            p[i].read();
//            p[i].print();
            int flag = 1;
            for(int j = 0; j < vec.size(); j++) {
                if(vec[j] == p[i]) {
                    vis[j]++;
                    flag = 0;
                }
            }
            if(flag) vec.push_back(p[i]);
        }
        N = vec.size();
//        for(int i = 0; i < N; i++) {
//            printf("**%d ", vis[i]);
//        }
//        puts("");
        for(int i = 0; i < N; i++) {
            p[i] = vec[i];
            vis[i]++;
//            p[i].print();
        }
        if(dfs(0)) puts("Possible");
        else puts("Impossible");
    }
	return 0;
}
