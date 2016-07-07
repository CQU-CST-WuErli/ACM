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

int cnt, n, p[111], mx;

bool dfs(int x, int dep, int up) {
    if (dep > up) return 0;
    if (x == n) return 1;
    if ((x + mx) << (up - dep - 1) < n) return 0;
    int bk = mx;
    for (int i = 0; i <= cnt; ++i) {
        ++cnt;
        p[cnt] = x + p[i];
        mx = max(mx, p[cnt]);
        if (x + p[i] <= 1600 && dfs(x + p[i], dep + 1, up)) return 1;
        mx = bk;
        p[cnt] = x - p[i];
        if (x - p[i] >= 0 && dfs(x - p[i], dep + 1, up)) return 1;
        --cnt;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    //freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int x = n, dep = -1;
        while (x) {
            ++dep;
            x >>= 1;
        }
        for (int ans = dep; ; ++ans) {
            cnt = 0;
            p[0] = 1;
            mx = 1;
            if (dfs(1, 0, ans)) {
                printf("%d\n", ans);
                break;
            }
        }
    }
    return 0;
}
