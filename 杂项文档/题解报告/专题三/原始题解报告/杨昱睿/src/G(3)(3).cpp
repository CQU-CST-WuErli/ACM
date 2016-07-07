#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 1010
#define MAXM 100000+10
#define INF 0x3f3f3f3f
using namespace std;
struct Edge
{
    int from, to, cap, flow, next;
};
Edge edge[MAXM];
int head[MAXN], edgenum, cur[MAXN];
int dist[MAXN];
bool vis[MAXN],mark[MAXN];
int cap[MAXN][MAXN], flow[MAXN][MAXN];
vector<int> V[MAXN];
int N,m,a,b,d,T;
struct DD
{
    int from, to, val, next;
};
DD Dist[MAXM];
int H[MAXN], top;
bool flag;//判断是否存在最短路
int sx, ex;//起点终点
void initDD()
{
    top = 0;
    memset(H, -1, sizeof(H));
}
void addDD(int u, int v, int w)
{
    DD E = {u, v, w, H[u]};
    Dist[top] = E;
    H[u] = top++;
}
void getDD()
{
    scanf("%d%d",&N,&m);
    for (int i=1;i<=m;i++)
    {
         scanf("%d%d%d",&a,&b,&d);
         addDD(a,b,d);
    }
}
void SPFA()//预处理最短路
{
    queue<int> Q;
    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[sx] = 0;
    vis[sx] = true;
    Q.push(sx);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for(int i = H[u]; i != -1; i = Dist[i].next)
        {
            DD E = Dist[i];
            if(dist[E.to] > dist[u] + E.val)
            {
                dist[E.to] = dist[u] + E.val;
                if(!vis[E.to])
                {
                    vis[E.to] = true;
                    Q.push(E.to);
                }
            }
        }
    }
    if(dist[ex] == INF)//到不了终点
        flag = false;
}
void initEdge()
{
    for (int i=1;i<=N;i++)
         V[i].clear();
    memset(cap,-INF,sizeof(cap));
    edgenum = 0;
    memset(head, -1, sizeof(head));
}
void getEdge()
{
    memset(mark, false, sizeof(mark));
    for(int i = 1; i <= N; i++)
    {
        for(int j = H[i]; j != -1; j = Dist[j].next)
        {
            DD E = Dist[j];
            if(dist[E.to] == dist[i] + E.val)
            {
               V[i].push_back(E.to);
               cap[i][E.to]=1;//最短路的边加进 新图
            }
        }
    }
}
int EdmondsKarp(int s, int t) {
    int p[MAXN], a[MAXN];
    queue<int> q;
    memset(flow, 0, sizeof(flow));
    int f = 0;
    while(true) {
        memset(a, 0, sizeof(a));
        a[s] = INF;
        q.push(s);
        while(!q.empty()) { //BFS 找增广路
            int u = q.front(); q.pop();
            for(int i=0; i<V[u].size(); i++)
            {

                int v=V[u][i];
                if(!a[v] && cap[u][v]>flow[u][v]){
                //找到新节点v
                p[v] = u; q.push(v);
                a[v] = min(a[u], cap[u][v]-flow[u][v]);
                }
            }
        }
        if(a[t] == 0) break;    //找不到，则当前流已经是最大流
        for(int u=t; u != s; u = p[u]) {    //从汇点往回走
            flow[p[u]][u] += a[t];  //更新正向流量
            flow[u][p[u]] -= a[t];  //更新反向流量
        }
        f += a[t];  //更新从 s 流出的流量
    }
    return f;
}

int main()
{
    //freopen( "testin.txt", "r", stdin);
    //freopen( "testout.txt", "w", stdout);
    scanf("%d",&T);
    while(T--)
    {
        initDD();
        getDD();
        scanf("%d%d", &sx, &ex);
        flag = true;
        SPFA();

        if(!flag)//不存在最短路
        {
            printf("0\n");
            continue;
        }
        initEdge();
        getEdge();
        printf("%d\n", EdmondsKarp(sx, ex));
    }
    return 0;
}

