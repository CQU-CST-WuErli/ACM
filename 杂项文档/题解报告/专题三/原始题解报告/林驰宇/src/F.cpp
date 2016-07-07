#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
const int M = 2e6 + 5, INF = 1e9;
struct node {
    int a, b, c;
    bool operator < (const node& x) const{
        return c < x.c;
    }
};
node edge[M];
int fa[M];
int get(int x) {
    if(x == fa[x]) return x;
    else return fa[x] = get(fa[x]);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int j = 1; j <= n; j++) fa[j] = j;
        for(int j = 1; j <= m; j++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edge[j] = (node) {a, b, c};
        }
        sort(edge + 1, edge + 1 + m);
        int ans = INF;
        for(int j = 1; j <= m; j++) {
            int a = get(edge[j].a), b = get(edge[j].b);
            if(a != b) fa[a] = b;
            else ans = min(ans, edge[j].c);
        }
        if(ans == INF) printf("No solution!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
