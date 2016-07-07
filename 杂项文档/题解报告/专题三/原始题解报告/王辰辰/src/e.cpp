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

int n, m, scc_cnt;
int head[5005], exhead[5005];
int sccno[5005], girl[5005];
bool vis[5005], leap[5005], used[5005];
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
    vis[u] = true;
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
    for(int i = 1; i <= n; i++) dfs1(i);
    for(int i = S.size() - 1; i >= 0; i--) {
        if(!sccno[S[i]]) {
            scc_cnt++;
            dfs2(S[i]);
        }
    }
}

bool dfs(int st) {
    for(int i = 0; i < G[st].size(); i++) {
        int v = G[st][i];
        if(used[v]) continue;
        used[v] = true;
        //if(st == 2) cout<<v<<" "<<girl[v]<<endl;
        //cout<<st<<" "<<v<<" "<<girl[v]<<endl;
        if(girl[v] == -1 || dfs(girl[v])) {
            girl[v] = st; return true;
        }
    }
    return false;
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
        memset(head, -1, sizeof(head));
        memset(exhead, -1, sizeof(exhead));
        for(int i = 1; i <= m; i++) {
            int u, v; scanf("%d%d", &u, &v);
            add_edge(u, v, i);
            exadd_edge(v, u, i);
        }
        find_scc(n);
        for(int i = 1; i <= scc_cnt; i++) G[i].clear();
        for(int u = 1; u <= n; u++) {
            for(int i = head[u]; i != -1; i = node[i].next) {
                int v = node[i].v;
                if(sccno[u] == sccno[v]) continue;
                G[sccno[u]].push_back(sccno[v]);
            }
        }
        /*for(int i = 1; i <= n; i++) {
            cout<<sccno[i]<<endl;
            for(int j = 0; j < G[sccno[i]].size(); j++)
                cout<<G[sccno[i]][j]<<" ";
            cout<<endl<<endl;
        }*/
        memset(girl, -1, sizeof(girl));
        int ans = 0;
        for(int i = 1; i <= scc_cnt; i++) {
            memset(used, false, sizeof(used));
            if(dfs(i)) ans++;
        }
        printf("%d\n", scc_cnt - ans);
    }
    return 0;
}
