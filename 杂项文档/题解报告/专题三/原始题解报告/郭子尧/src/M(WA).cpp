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
const int MAXN = 1e7 + 111;

int n, p;
ll a[20];
ll dp[1000000];
bool vis[MAXN];

ll get(ll r, ll l) {
    if (r < l) return 0;
    ll del = r - l;
    return del / a[p] + 1;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    ll l, r;
    while (t --) {
        cin >> n >> l >> r;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        for (p = 0; p < n; ++p) {
            if (a[p] != 0) break;
        }
        if (p == n) {
            cout << (l == 0) << '\n';
            continue;
        }

        for (int i = 0; i < a[p]; ++i) dp[i] = 1e15;
        dp[0] = 0;

        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (q.size()) {
            int u = q.front(); q.pop();
            vis[u] = 0;
            for (int i = p + 1; i < n; ++i) {
                int v = u + a[i];
                int to = v % a[p];
                if (v < dp[to]) {
                    dp[to] = v;
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < a[p]; ++i) {
            if (dp[i] == 1e15) continue;
            //pr(dp[i])
            //pr(get(r, dp[i]))
            //pr(get(l, dp[i]));
            ans += get(r, dp[i]) - get(l - 1, dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
