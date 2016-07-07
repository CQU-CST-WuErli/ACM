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
int n, m;
int head[505], ehead[505], p[505];
int deg[505], in[505], out[505];
bool leap[505];
vector <int> g[505];

struct Node {
    int u, v, nxt;
}node[300000], enode[300000];

void add_edge(int u, int v, int tot) {
    node[tot].u = u; node[tot].v = v;
    node[tot].nxt = head[u];
    head[u] = tot;
}

void exadd_edge(int u, int v, int tot) {
    enode[tot].u = u; enode[tot].v = v;
    enode[tot].nxt = ehead[u];
    ehead[u] = tot;
}

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

bool check1() {
    memset(leap, false, sizeof(leap));
    queue<int>p;
    p.push(1); leap[1] = true;
    while(p.size()) {
        int u = p.front(); p.pop();
        for(int i = head[u]; i != -1; i = node[i].nxt) {
            int v = node[i].v;
            if(leap[v]) continue;
            p.push(v);
            leap[v] = true;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!leap[i]) return false;
    }
    return true;
}

bool check2() {
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int v = g[i][j];
            int fx = find(i);
            int fy = find(v);
            if(fx == fy) continue;
            p[fy] = fx;
        }
    }
    int root = find(1);
    //cout<<root<<endl;
    for(int i = 2; i <= n; i++) {
        int temp = find(i);
        //cout<<i<<" "<<temp<<endl;
        if(temp != root) return false;
    }
    return true;
}

void work1() {
    if(!check1()) {
        printf("No "); return ;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] % 2) ans++;
    }
    if(ans == 0 || ans == 2) printf("Yes ");
    else printf("No ");
}

void work2() {
    if(!check2()) {
        printf("No\n"); return ;
    }
    int ans1 = 0, ans2 = 0;
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        if(in[i] == out[i]) continue;
        else if(abs(in[i] - out[i]) > 1) ok = false;
        else if(in[i] - out[i] == 1) ans1++;
        else if(out[i] - in[i] == 1) ans2++;
    }
    if(ok) {
        if(ans1 == 1 && ans2 == 1) printf("Yes\n");
        else if(ans1 == 0 && ans2 == 0) printf("Yes\n");
        else printf("No\n");
    }
    else printf("No\n");

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
        for(int i = 1; i <= n; i++) g[i].clear();
        memset(head, -1, sizeof(head));
        memset(ehead, -1, sizeof(ehead));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(deg, 0, sizeof(deg));
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++; deg[v]++;
            out[u]++; in[v]++;
            add_edge(u, v, i * 2 - 1);
            add_edge(v, u, i * 2);
            g[v].push_back(u);
        }
        work1();
        work2();
    }
    return 0;
}
