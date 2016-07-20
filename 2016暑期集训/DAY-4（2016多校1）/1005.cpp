//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
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

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int n, m;
bool hate[10][10];
int ying[10];
int link[10][10];
int match[10];
int used[10];
int tid;
int lid;
int ans;

bool find(int x) {
    for (int i = 1; i <= n; i++) if (link[x][i] == lid && used[i] != tid) {
        used[i] = tid;
        if (!match[i] || find(match[i])) {
            match[i] = x;
            return true;
        }
    }
    return false;
}

int hungary() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x = ying[j];
            if (!hate[i][x]) {
                int tmp = j + 1;
                if (tmp > n) tmp = 1;
                if (!hate[i][ying[tmp]])
                    link[i][j] = lid;
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << link[i][j] << ' ';
    //     puts("");
    // }
    CLR(match);
    CLR(used);
    int ret = 0;
    tid = 0;
    for (int i = 1; i <= n; i++) {
        tid++;
        if (find(i)) ret++;
    }
    return ret;
}


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n, m) == 2) {
        if (n == 0 || m == 0) {
            cout << 0 << endl;
            continue;
        }
        CLR(hate);
        int u, v;
        for (int i = 1; i <= m; i++) {
        	SII(u, v);
            hate[u][v] = true;
        }
        for (int i = 1; i <= n; i++)
            ying[i] = i;
        ans = INF_INT;
        CLR(link);
        lid = 0;
        int test = 0;
        // do {
        //     lid++;
        //     test++;
        //     ans = min(ans, n - hungary());
        //     if (ans == 0) break;
        //     if (test > 2500) break;
        // }while (next_permutation(ying + 2, ying + 1 + n));
        for (int i = 1; i <= 175; i++) {
            random_shuffle(ying + 1, ying + 1 + n);
            lid++;
            ans = min(ans, n - hungary());
            if (ans == 0) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}