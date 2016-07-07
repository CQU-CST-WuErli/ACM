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
const int MAXN = 5e2 + 111;

int mark[MAXN];
vector<int> G[MAXN];
bool mp[MAXN][MAXN];

void dfs(int u, int flag) {
    mark[u] = flag;
    for (int j = 0; j < G[u].size(); ++j) {
        if (mark[G[u][j]] == -1) {
            dfs(G[u][j], flag);
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int n, m, u, v, t; cin >> t;
    while (t --) {
        cin >> n >> m;
        memset(mp, 0, sizeof mp);
        for (int i = 1; i <= n; ++i) G[i].clear(), mark[i] = -1;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            mp[u][v] = mp[v][u] = 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            if (mark[i] == -1) {
                if (G[i].size() == n - 1) {
                    mark[i] = 1;
                }
            }
        }
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (mark[i] == -1) {
                dfs(i, flag);
                flag = 2 - flag;
            }
        }
        bool ok = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (mp[i][j] && abs(mark[i] - mark[j]) > 1) {
                    ok = 0;
                    break;
                }
                else if (!mp[i][j] && abs(mark[i] - mark[j]) < 2) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
