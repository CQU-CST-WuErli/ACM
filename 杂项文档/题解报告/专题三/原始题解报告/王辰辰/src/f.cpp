#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 2000005;

int n, m;
int p[500100];
struct Node {
    int u, v, w;
}node[maxn];

bool cmp(Node a, Node b) {
    return a.w < b.w;
}

void init() {
    for(int i = 1; i <= n; i++) p[i] = i;
}

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int kruscal() {
    init();
    for(int i = 1; i <= m; i++) {
        int fx = find(node[i].u);
        int fy = find(node[i].v);
        if(fx == fy) return node[i].w;
        p[fx] = fy;
    }
    return inf;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &node[i].u, &node[i].v, &node[i].w);
        }
        sort(node + 1, node + 1 + m, cmp);
        int ans = kruscal();
        if(ans == inf) printf("No solution!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
