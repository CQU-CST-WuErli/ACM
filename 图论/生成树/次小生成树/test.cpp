#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
const int M = 220;
const int INF = 1000000000;
int n, m, T, ans1, ans2, ise[N], f[N];
struct edge {
    int u, v, cost;
}e[M];

bool cmp( edge a, edge b ) {
    return a.cost < b.cost;
}
int find ( int x ) {
    return f[x] == x ? x: f[x] = find(f[x]);
}
int Kru() {
    int ans = 0, num = 0, id = 0;
    for ( int i = 1; i <= n; ++i ) f[i] = i;
    for ( int i = 0; i < m; ++i ) {
        int x = e[i].u;
        int y = e[i].v;
        int a = find(x);
        int b = find(y);
        if ( a != b ) ise[id++] = i, f[a] = b, ans += e[i].cost;
    }
    for ( int i = 1; i <= n; ++i ) if ( i == find(i) ) num++;
    if ( num > 1 ) return INF;
    else return ans;
}
int Kru_1( int del ) {
    int ans = 0, num = 0;
    for ( int i = 1; i <= n; ++i ) f[i] = i;
    for ( int i = 0; i < m; ++i ) {
        if ( i == del ) continue;
        int x = e[i].u;
        int y = e[i].v;
        int a = find(x);
        int b = find(y);
        if ( a != b ) f[a] = b, ans += e[i].cost;
    }
    for ( int i = 1; i <= n; ++i ) if ( i == find(i) ) num++;
    if ( num > 1 ) return INF;
    else return ans;
}
int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int idx = 1;
    scanf("%d", &T);
    while ( T-- ) {
        scanf("%d%d", &n, &m);
        for ( int i = 0; i < m; ++i )
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].cost);
        sort( e, e+m, cmp );
        ans1 = Kru(), ans2 = INF;
        printf("ans1=%d\n", ans1);
        printf("Case #%d : ", idx++);
        if ( ans1 == INF ) {
            printf("No way\n");
            continue;
        }
        for ( int i = 0; i < n-1; ++i ) {
            int x = ise[i];
            ans2 = min( ans2, Kru_1(x) );
        }
        if ( ans2 == INF ) printf("No second way\n");
        else printf("%d\n", ans2);
    }
}