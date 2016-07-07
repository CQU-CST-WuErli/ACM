#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 40010;

struct Edge
{
    int to;
    int next;
    int w;
}edge[2*MAXN];
int tot;
int head[MAXN];

void add(int s, int u)
{
    edge[tot].to = u;
    edge[tot].next = head[s];
    head[s] = tot++;

    edge[tot].to = s;
    edge[tot].next = head[u];
    head[u] = tot++;
}

int n,m,a,b,T;
int dfn[MAXN],low[MAXN],sta[MAXN], col[MAXN];
int tt, sum, scc, top;

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tt;
    sta[++top] = u;
    int cnt=0;
    for(int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if(!dfn[v]) {
            sum++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (fa == v) {
            if (cnt) low[u] = min(low[u],dfn[v]);//重边
            cnt++;
    //没有重边的时候可以改成continue;
        } else low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        int x;
        scc++;
        do {
            x = sta[top--];
            col[x] = scc;
        } while(x != u);
    }
}

int main()
{


    scanf("%d",&T);
    for (int p=1;p<=T;p++)
    {
        scanf("%d%d",&n,&m);
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(col, 0, sizeof(col));
        memset(head, 0, sizeof(head));
        tot = sum = 1;
        tt = scc = top = 0;

        while (m--) {
            scanf("%d %d", &a, &b);
            add(a, b);
        }
        for (int i=1;i<=n;i++)
             if (!dfn[i])
             {
                 tarjan(i,i);
             }

        int num=0;

            for (int i = 1; i <= n; ++i) {
                for (int j = head[i]; j; j = edge[j].next) {
                    int v = edge[j].to;
                    if (col[i] != col[v]) num++;
                }
            }
        printf("Case %d: %d\n",p,num/2);

    }
    return 0;
}
