
//  Created by Running Photon on 2016-05-04
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
#define ull unsigned long long
#define CLR(x) memset(x, 0, sizeof x)
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

int vis[maxv];
int top, n, flag;
int num[200];
int res[500];
void dfs(int step, int mod) {
    if(top == step && step) {
//        printf("%d\n", step);
        if(mod || flag) return;
        flag = 1;
        for(int i = 1; i <= step; i++) {
            res[i] = num[i];
//            printf("%d", res[i]);
        }
//        puts("");
        top = step;
        return;
    }
    if(mod) {
        if(vis[mod] < step) return;
        vis[mod] = step;
    }
    if(mod > 0) dfs(step + 1, mod * 10 % n);
    num[step+1] = 1;
    dfs(step+1, (mod * 10 + 1) % n);
    num[step+1] = 0;

}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out1.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        CLR(num);
        flag = 0;
        for(top = 1;;top++) {
            memset(vis, 0x3f, sizeof vis);
            dfs(0, 0);
//            printf("top = %d\n", top);
            if(flag) break;
        }
        for(int i = 1; i <= top; i++) {
            printf("%d", res[i]);
        }
        puts("");
    }
//    puts("400");
//    for(int i = 1; i <= 400; i++)
//        printf("%d\n", i);
	return 0;
}
