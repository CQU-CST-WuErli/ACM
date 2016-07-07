#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e3 + 111;
const int MAXM = 2e3 + 111;

struct Edge {
    int u, v;
}edge[MAXM];
vector<int> G[MAXN];
bool vis[MAXN];

int n, m, ans;

bool dfs(int p, int use) {
    if (p == m) {
        ans = min(ans, use);
        return 1;
    }
    if (use >= ans || use > 10) return 0;
    int u = edge[p].u, v = edge[p].v;
    if (vis[u] || vis[v]) {
        return dfs(p + 1, use);
    }

    int flag = 0;
    vis[u] = 1;
    ++use;
    if (!dfs(p + 1, use)) ++flag;
    vis[u] = 0;
    --use;

    vis[v] = 1;
    ++use;
    if (!dfs(p + 1, use)) ++flag;
    vis[v] = 0;
    --use;

    return flag != 2;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; cin >> t;
    while (t --) {
        cin >> n >> m;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; ++i) {
            cin >> edge[i].u >> edge[i].v;
        }
        ans = INF;
        if (dfs(0, 0)) {
            cout << ans << '\n';
        }
        else cout << "Poor lcy\n";
    }
    return 0;
}
