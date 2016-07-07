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

vector<int> g[N], reg[N];
int n, m;

int pre[N], low[N], dfs_clock;
int sccno[N], scc_cnt;
int inS[N];
stack<int> S;
int size[N];

void init() {
    for (int i = 1; i <= n; i++)
        g[i].clear(), reg[i].clear();
    dfs_clock=scc_cnt=0;
    CLR(pre);
    CLR(sccno);
    while (S.size()) S.pop();
    CLR(inS);
    CLR(size);
}

int tarjan(int u) {
    low[u]=pre[u]=++dfs_clock;
    S.push(u);inS[u]=1;
    for (int i = 0; i < g[u].size(); i++) {
        int v= g[u][i];
        if (!pre[v]) {
            low[v]=tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (inS[v])
            low[u]=min(low[u],pre[v]);
    }
    if (low[u]==pre[u]) {
        scc_cnt++;
        for (int v;v!=u;) {
            v=S.top();S.pop();
            inS[v]=0;
            sccno[v]=scc_cnt;
            size[scc_cnt]++;
        }
    }
    return low[u];
}
void find_scc() {
    for (int i = 1; i <= n; i++) if (!pre[i]) {
        tarjan(i);
    }
}

void buildDAG() {
    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (sccno[u] != sccno[v]) {
                reg[sccno[u]].push_back(sccno[v]);
                reg[sccno[v]].push_back(sccno[u]);
            }
        }
    }
}

int vis[N];
int sum = 0;
int flag = 0;

void dfs(int u) {
    vis[u] = 1;
    sum += size[u];
    if (size[u] > 1) flag = 1;
    for (int i = 0; i < reg[u].size(); i++) {
        int v = reg[u][i];
        if (vis[v]) continue;
        dfs(v);
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, m) == 2) {
        init();
        for (int i = 1; i <= m; i++) {
            int u, v;
            SII(u, v);
            g[u].push_back(v);
        }
        find_scc();
        // lookln(scc_cnt);
        CLR(vis);
        buildDAG();
        int ans = 0;
        for (int i = 1; i <= scc_cnt; i++) if (!vis[i]) {
            sum = 0; flag = 0;
            dfs(i);
            ans += flag ? sum : sum - 1;
        }
        cout << ans << endl;
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
            佛祖保佑        永无BUG
*/