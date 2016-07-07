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
const int M = 2005;
struct SCC {
    int V;
    vector<int>G[M];
    vector<int>rG[M];
    vector<int>vs;
    bool used[M];
    int cmp[M];
    void init() {
        for(int j = 0; j < V; j++) {
            G[j].clear();
            rG[j].clear();
        }
    }
    void add_edge(int from, int to) {
        G[from].push_back(to);
        rG[to].push_back(from);
    }
    void dfs(int v) {
        used[v] = true;
        for(int j = 0; j < G[v].size(); j++) {
            if(!used[G[v][j]]) dfs(G[v][j]);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for(int j = 0; j < rG[v].size(); j++) {
            if(!used[rG[v][j]]) rdfs(rG[v][j], k);
        }
    }
    int scc() {
        memset(used, 0, sizeof(used));
        vs.clear();
        for(int v = 0; v < V; v++) {
            if(!used[v]) dfs(v);
        }
        memset(used, 0, sizeof(used));
        int k = 0;
        for(int j = vs.size() - 1; j >= 0; j--) {
            if(!used[vs[j]]) rdfs(vs[j], k++);
        }
        return k;
    }
} s;
struct bipartite {
    int V;
    vector<int>G[2 * M];
    int match[2 * M];
    bool used[2 * M];
    void init() {
        for(int j = 0; j < V; j++) G[j].clear();
    }
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool dfs(int v) {
        used[v] = true;
        for(int j = 0; j < G[v].size(); j++) {
            int u = G[v][j], w = match[u];
            if(w < 0 || !used[w] && dfs(w)) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    int bipartite_matching() {
        int res = 0;
        memset(match, -1, sizeof(match));
        for(int v = 0; v < V; v++) {
            if(match[v] < 0) {
                memset(used, 0, sizeof(used));
                if(dfs(v)) res++;
            }
        }
        return res;
    }
} bi;
bool mark[M];
void dfs(int x,int y,int scc_cnt){
    if(mark[y]) return;
    mark[y]=1;
    if(s.cmp[y]!=x) bi.add_edge(x,s.cmp[y]+scc_cnt);
    for(int j=0;j<s.G[y].size();j++){
        int to=s.G[y][j];
        dfs(x,to,scc_cnt);
    }
}
int main() {
    int T,cas=1;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        s.V = n;
        s.init();
        for(int j = 1; j <= m; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            s.add_edge(a-1, b-1);
        }
        int scc_cnt = s.scc();
        bi.V = 2 * scc_cnt;
        bi.init();
        for(int j = 0; j < n; j++) {
            memset(mark,0,sizeof(mark));
            dfs(s.cmp[j],j,scc_cnt);
        }
        printf("Case %d: %d\n",cas++, scc_cnt - bi.bipartite_matching());
    }
    return 0;
}
