//
//  Created by Running Photon on 2016-05-05
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
const int MOD = 1e4 + 7;
const int maxn = 6e3 + 10;
const int maxv = 18 + 10;
const double eps = 1e-9;

int ban[maxn];
int fail[maxn];
int nxt[maxn][maxv];
struct acA {
    int root;
    int cnt;
    int newNode() {
        for(int i = 0; i < 26; i++) {
            nxt[cnt][i] = -1;
        }
        ban[cnt] = 0;
        cnt++;
        return cnt - 1;
    }
    void init() {
        cnt = 0;
        root = newNode();
    }
    void insert(char x[]) {
        int now = root;
        int len = strlen(x);
        for(int i = 0; i < len; i++) {
            int id = x[i] - 'A';
            if(nxt[now][id] == -1)
                nxt[now][id] = newNode();
            now = nxt[now][id];
        }
        ban[now] = 1;
    }
    void build() {
        queue <int> que;
        fail[root] = root;
        for(int i = 0; i < 26; i++) {
            if(nxt[root][i] == -1) {
                nxt[root][i] = root;
            }
            else {
                fail[nxt[root][i]] = root;
                que.push(nxt[root][i]);
            }
        }
        while(que.size()) {
            int now = que.front();
            que.pop();
            for(int i = 0; i < 26; i++) {
                int &np = nxt[now][i];
                if(np == -1) {
                    np = nxt[fail[now]][i];
                }
                else {
                    fail[np] = nxt[fail[now]][i];
                    que.push(np);
                    ban[np] |= ban[fail[np]];
                }
            }
        }
    }
};
int dp[105][maxn];
int get(int k) {
    int res = 1;
    while(k--) {
        res = res * 26 % MOD;
    }
    return res;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        acA ac;
        ac.init();
        for(int i = 0; i < n; i++) {
            char tmp[105];
            scanf("%s", tmp);
            ac.insert(tmp);
        }
        ac.build();
        CLR(dp);
        dp[0][0] = 1;
//        cout << ac.cnt << endl;
        for(int i = 0; i < m; i++) {
            for(int pos = 0; pos < ac.cnt; pos++) {
//                printf("%d  %d\n", i, pos);
                if(!dp[i][pos] || ban[pos]) continue;
                for(int j = 0; j < 26; j++) {
                    int np = nxt[pos][j];
                    if(ban[np]) continue;
                    dp[i+1][np] = (dp[i+1][np] + dp[i][pos]) % MOD;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < ac.cnt; i++) {
            if(ban[i]) continue;
            ans = (ans + dp[m][i]) % MOD;
        }
        ans = (get(m) - ans + MOD) % MOD;
        printf("%d\n", ans);
    }

	return 0;
}
