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
const int MAXN = 5e3 + 111;

int in[MAXN], out[MAXN], par[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        in[i] = out[i] = 0;
    }
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool connect(int n) {
    int f = find(1);
    for (int i = 2; i <= n; ++i) {
        if (find(i) != f) return 0;
    }
    return 1;
}

bool bid(int n) {
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        int sum = in[i] + out[i];
        if (sum % 2) ++num;
    }
    if (num == 0 || num == 2) return 1;
    return 0;
}

bool uni(int n) {
    int num = 0;
    int deg[2] = {0, 0};
    int sta = 0;
    for (int i = 1; i <= n; ++i) {
        if (in[i] != out[i]) {
            deg[sta] = in[i] - out[i];
            sta = 1 - sta;
            ++num;
        }
    }
    if (num != 0 && num != 2) return 0;
    if (num == 0) return 1;
    if (deg[0] * deg[1] == -1) return 1;
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    int t, n, m; cin >> t;
    while (t --) {
        cin >> n >> m;
        init(n);
        int u, v;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            ++out[u], ++in[v];
            u = find(u), v = find(v);
            if (u != v) {
                par[u] = v;
            }
        }

        if (!connect(n)) {
            cout << "No No\n";
        }
        else {
            if (bid(n)) cout << "Yes";
            else cout << "No";
            if (uni(n)) cout << " Yes\n";
            else cout << " No\n";
        }
    }
    return 0;
}
