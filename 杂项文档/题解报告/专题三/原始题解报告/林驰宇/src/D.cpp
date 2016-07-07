#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<climits>
#define LL long long
using namespace std;
const int M = 2005, INF = 1e9;
struct Edge {
    int v, nxt;
} edge[M*1000];
struct point {
    int x, y;
} A[M], hate[M], like[M];
int V;
vector<int>G[M];
int pre[M],lowlink[M],sccno[M],dfs_clock,scc_cnt;
stack<int>S;
int head[M], cnt;
void add_edge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}
void tarjan(int u){
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    for(int j = head[u]; ~j; j = edge[j].nxt){
        int v=edge[j].v;
        if(!pre[v]){
            tarjan(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v]) lowlink[u]=min(lowlink[u],pre[v]);
    }
    if(lowlink[u]==pre[u]){
        scc_cnt++;
        while(1){
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u) break;
        }
    }
}
int n, a, b;
point s1, s2;
void clr() {
    for(int j = 1; j <= V; j++) G[j].clear();
}
int dis(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
bool check(int mid) {
    memset(head,-1,sizeof(head));cnt=0;
    int j, k;
    for(j = 1; j <= a; j++) {
        int x = hate[j].x, y = hate[j].y;
        add_edge(x, y + n);
        add_edge(x + n, y);
        add_edge(y, x + n);
        add_edge(y + n, x);
    }
    for(j = 1; j <= b; j++) {
        int x = like[j].x, y = like[j].y;
        add_edge(x, y);
        add_edge(y, x);
        add_edge(x + n, y + n);
        add_edge(y + n, x + n);
    }
    for(j = 1; j <= n; j++) {
        for(k = j + 1; k <= n; k++) {
            if(dis(A[j], s1) + dis(A[k], s1) > mid) add_edge(j, k + n), add_edge(k, j + n);
            if(dis(A[j], s2) + dis(A[k], s2) > mid) add_edge(j + n, k), add_edge(k + n, j);
            if(dis(A[j], s1) + dis(s1, s2) + dis(s2, A[k]) > mid) add_edge(j, k), add_edge(k + n, j + n);
            if(dis(A[k], s1) + dis(s1, s2) + dis(s2, A[j]) > mid) add_edge(k, j),add_edge(j + n, k + n);
        }
    }
    //printf("%d\n",cnt);
    memset(pre,0,sizeof(pre));
    memset(lowlink,0,sizeof(lowlink));
    memset(sccno,0,sizeof(sccno));
    while(!S.empty()) S.pop();
    dfs_clock=scc_cnt=0;
    for(int j=1;j<=V;j++){
        if(!pre[j]) tarjan(j);
    }
    for(j = 1; j <= n; j++) {
        if(sccno[j] == sccno[j + n]) return 0;
    }
    return 1;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &a, &b);
        V = 2 * n;
        scanf("%d%d%d%d", &s1.x, &s1.y, &s2.x, &s2.y);
        int j, k;
        for(j = 1; j <= n; j++) scanf("%d%d", &A[j].x, &A[j].y);
        for(j = 1; j <= a; j++) scanf("%d%d", &hate[j].x, &hate[j].y);
        for(j = 1; j <= b; j++) scanf("%d%d", &like[j].x, &like[j].y);
        int l = 0, r = INF, res = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid)) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", res);
    }
    return 0;
}
