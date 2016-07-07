//
//  Created by TaoSama on 2016-06-01
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[15];
typedef long long LL;
LL l, r, f[N]; //到达模a[1]余i所用的最少数字和
bool done[N];

typedef pair<LL, int> P;
void dijkstra() {
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, 0));
    memset(f, 0x3f, sizeof f);
    memset(done, 0, sizeof done);
    f[0] = 0;
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(int i = 2; i <= n; ++i) {
            int v = (u + a[i]) % a[1];
            if(f[v] > f[u] + a[i]) {
                f[v] = f[u] + a[i];
                q.push(P(f[v], v));
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%lld%lld", &n, &l, &r);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);

        dijkstra();

        LL ans = 0;
        for(int i = 0; i < a[1]; ++i) {
            if(r >= f[i]) ans += (r - f[i]) / a[1] + 1;
            if(l - 1 >= f[i]) ans -= (l - 1 - f[i]) / a[1] + 1;
        }
        printf("%lld\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
