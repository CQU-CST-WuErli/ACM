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

vector<int> G[10];
int mp[10][10];
int vis[10];

bool dfs(int u) {
    vis[u] = -1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (vis[v] == -1) return 0;
        if (!vis[v] && !dfs(v)) return 0;
    }
    vis[u] = 1;
    return 1;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    string s;
    int t;
    ios_base::sync_with_stdio(0);
    cin >> t;
    while (t --) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= 9; ++i) G[i].clear();

        for (int i = 1; i <= 9; ++i) {
            int t = i - 1;
            for (int j = t / 3; j <= t / 3 + 1; ++j) {
                for (int k = t % 3; k <= t % 3 + 1; ++k) {
                    if (mp[j][k] != i) {
                        G[mp[j][k]].push_back(i);
                    }
                }
            }
        }

        memset(vis, 0, sizeof vis);
        bool flag = 0;
        for (int i = 1; i <= 9; ++i) {
            if (!vis[i] && !dfs(i)) {
                flag = 1;
                break;
            }
        }
        if (flag) cout << "BOOM!\n";
        else cout << "Lucky dog!\n";
    }
    return 0;
}
