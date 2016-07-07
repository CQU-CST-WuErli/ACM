#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define lowbit(x) (x & (-x))
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int MAXN = 1110;//点数的最大值
const int MAXM = 540010;//边数的最大值的两倍
const int INF = 0x3f3f3f3f;

struct P {
    int to, w;
    P(int a, int b): to(a), w(b){};
};
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol, src, des;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
vector<P> G[MAXN];
bool in[MAXN];
ll dis[MAXN];

void init(int n)
{
    tol = 0;
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
        in[i] = 0;
        G[i].clear();
    }
    memset(head,-1,sizeof(head));
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];
    edge[tol].flow = 0;head[u] = tol++;
    edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];
    edge[tol].flow = 0;head[v]=tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start,int end,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
            {
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1;i = edge[i].next)
        {
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag)
        {
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i != -1;i = edge[i].next)
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u] = Min+1;
        gap[dep[u]]++;
        if(u != start) u = edge[pre[u]^1].to;
    }
    return ans;
}


void spfa(int s) {
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    in[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i].to, w = G[u][i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m, u, v, w; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(P(v, w));
        }
        scanf("%d%d", &src, &des);
        spfa(src);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < G[i].size(); ++j) {
                int v = G[i][j].to, w = G[i][j].w;
                if (dis[i] + w == dis[v]) {
                    addedge(i, v, 1);
                }
            }
        }
        printf("%d\n", sap(src, des, n + 1));
    }
    return 0;
}

