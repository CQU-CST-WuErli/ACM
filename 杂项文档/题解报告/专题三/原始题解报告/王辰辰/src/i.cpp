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
const int maxn = 1005;

int dfs_clock, ans;
int pre[10010], head[10010], low[10010];
bool vis[40010];
struct Node {
    int u, v, nxt;
}node[40010];

void add_edge(int u, int v, int tot) {
    node[tot].u = u; node[tot].v = v;
    node[tot].nxt = head[u];
    head[u] = tot;
}

int dfs(int u) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i = head[u]; i != -1; i = node[i].nxt) {
        if(vis[i] || vis[i ^ 1]) continue;
        vis[i] = vis[i ^ 1] = true;
        int v = node[i].v;
        //cout<<u<<" "<<v<<" "<<i<<endl;
        if(!pre[v]) {
            child++;
            int lowv = dfs(v);
            lowu = min(lowu, lowv);
            if(lowv > pre[u]) {
                //cout<<u<<" "<<v<<endl;
                ans++;
            }
        }
        else if(pre[v] < pre[u])
            lowu = min(lowu, pre[v]);
    }
    //if(u == 1 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}


int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    int t; scanf("%d", &t);
    int kase = 1;
    while(t--) {
        int n, m; scanf("%d%d", &n, &m);
        memset(head, -1, sizeof(head));
        for(int i = 0; i < m; i++) {
            int u, v; scanf("%d%d", &u, &v);
            add_edge(u, v, i * 2);
            add_edge(v, u, i * 2 + 1);
        }
        ans = 0; dfs_clock = 0;
        memset(pre, 0, sizeof(pre));
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++) {
            if(pre[i]) continue;
            dfs(i);
        }
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}
