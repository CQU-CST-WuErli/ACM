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
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int t, n, m, scc_cnt;
int head[5005], exhead[5005];
int sccno[5005], num[5005], dp[5005];
bool vis[5005], leap[5005][5005];
vector<int> S;
vector<int> G[5005];

struct Node
{
    int u, v, next;
}node[30050], exnode[30050];

void add_edge(int u, int v, int tot) {
    node[tot].u = u; node[tot].v = v;
    node[tot].next = head[u];
    head[u] = tot;
}

void exadd_edge(int u, int v, int tot) {
    exnode[tot].u = u; exnode[tot].v = v;
    exnode[tot].next = exhead[u];
    exhead[u] = tot;
}

void dfs1(int u) {
    if(vis[u]) return ;
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = node[i].next) {
        int v = node[i].v;
        dfs1(v);
    }
    S.push_back(u);
}

void dfs2(int u) {
    if(sccno[u]) return ;
    sccno[u] = scc_cnt;
    for(int i = exhead[u]; i != -1; i = exnode[i].next) {
        int v = exnode[i].v;
        dfs2(v);
    }
}

void find_scc(int n) {
    scc_cnt = 0;
    S.clear();
    memset(sccno, 0, sizeof(sccno));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++) dfs1(i);
    for(int i = S.size() - 1; i >= 0; i--) {
        if(!sccno[S[i]]) {
            scc_cnt++;
            dfs2(S[i]);
        }
    }
}

void work(int st, int x) {
    bool f[5005];
    memset(f, false, sizeof(f));
    f[st] = true;
    queue<int> p;
    p.push(st);
    while(p.size()) {
        int u = p.front(); p.pop();
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(f[v]) continue;
            f[v] = true;
            p.push(v);
        }
    }
    for(int i = 1; i <= scc_cnt; i++) {
        if(i == st) continue;
        if(f[i]) dp[i] += x;
    }
}

void solve() {
    memset(leap, false, sizeof(leap));
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= scc_cnt; i++) G[i].clear();
    for(int i = 0; i < n; i++) num[sccno[i]]++;
    for(int u = 0; u < n; u++) {
        for(int i = head[u]; i != -1; i = node[i].next) {
            int v = node[i].v;
            if(sccno[u] == sccno[v]) continue;
            if(leap[sccno[u]][sccno[v]]) continue;
            leap[sccno[u]][sccno[v]] = true;
            G[sccno[u]].push_back(sccno[v]);
        }
    }
    for(int i = 1; i <= scc_cnt; i++) dp[i] = num[i] - 1;
    for(int i = 1; i <= scc_cnt; i++) work(i, num[i]);
}

int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	scanf("%d",&t);
	int kase = 1;
	while(t--) {
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof(head));
        memset(exhead, -1, sizeof(exhead));
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v, i);
            exadd_edge(v, u, i);
        }
        find_scc(n);

        solve();

        int ans = -inf;
        for(int i = 0; i < n; i++) ans = max(ans, dp[sccno[i]]);
        vector<int> rans;
        for(int i = 0; i < n; i++) {
            if(dp[sccno[i]] == ans)
                rans.push_back(i);
        }
        printf("Case %d: %d\n", kase++, ans);
        for(int i = 0; i < rans.size(); i++) {
            printf("%d", rans[i]);
            if(i == rans.size() - 1)
                printf("\n");
            else
                printf(" ");
        }
    }
	return 0;
}
