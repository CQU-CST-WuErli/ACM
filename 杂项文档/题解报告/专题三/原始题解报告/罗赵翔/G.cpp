#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <sstream>
#include <stack>
using namespace std;

#define cls(x) memset(x,0,sizeof x)
#define inf(x) memset(x,0x3f,sizeof x)
#define neg(x) memset(x,-1,sizeof x)
#define ninf(x) memset(x,0xc0,sizeof x)
#define st0(x) memset(x,false,sizeof x)
#define st1(x) memset(x,true,sizeof x)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define bug cout<<"here"<<endl;
//#define debug

const int maxn=1050;
int n,m;
int beg,fin;
int T;
struct road
{
    int from,to,cost,cap;
    road():from(0),to(0),cost(0),cap(0){}
    road(int f,int t,int c,int cc):from(f),to(t),cost(c),cap(cc){}
    bool operator < (const road &rhs) const{
        return cost<rhs.cost;
    }
}p,q;
vector<road> G[maxn],edges;
vector<int> adG[maxn];

void init(int x)
{
    edges.clear();
    for(int i=0;i<=x;++i)
    {
        G[i].clear();
        adG[i].clear();
    }
}

bool visit[maxn];
int dist[maxn];
void Dijkstra()
{
    st0(visit);
    inf(dist);
    dist[beg]=0;
    priority_queue<road> DIJ;
    DIJ.push(road(beg,0,0,0));
    while(!DIJ.empty())
    {
        p=DIJ.top();
        DIJ.pop();
        if(visit[p.from])
            continue;
        visit[p.from]=1;
        for(int i=0;i<G[p.from].size();++i)
        {
            road &e=G[p.from][i];
            if(!visit[e.to]&&dist[e.to]>dist[e.from]+e.cost)
            {
                dist[e.to]=dist[e.from]+e.cost;
                DIJ.push(road(e.to,0,dist[e.to],0));
            }
        }
    }
    return;
}

void addedge(int a,int b,int c)
{
    edges.push_back(road(a,b,0,c));
    edges.push_back(road(a,b,0,0));
    adG[a].push_back(edges.size()-2);
    adG[b].push_back(edges.size()-1);
    return;
}

void buildnet()
{
    for(int i=1;i<=n;++i)
        for(int j=0;j<G[i].size();++j)
            if(dist[G[i][j].to]==dist[G[i][j].from]+G[i][j].cost)
                addedge(G[i][j].from,G[i][j].to,1);
    return;
}

int Edmonds_Karp()
{
    int pre[maxn];
    int aug[maxn];
    int flow=0;
    for(;;)
    {
        cls(aug);
        aug[beg]=INF;
        queue<int> BFS;
        BFS.push(beg);
        while(!BFS.empty())
        {
            int x=BFS.front();
            BFS.pop();
            for(int i=0;i<adG[x].size();++i)
            {
                road &e=edges[adG[x][i]];
                if(aug[e.to]==0&&e.cap>e.cost)
                {
                    BFS.push(e.to);
                    aug[e.to]=min(aug[e.from],e.cap-e.cost);
                    pre[e.to]=adG[x][i];
                }
            }
            if(aug[fin])
                break;
        }
        if(aug[fin]==0)
            break;
        for(int u=fin;u!=beg;u=edges[pre[u]].from)
        {
            edges[pre[u]].cost+=aug[fin];
            edges[pre[u]^1].cost-=aug[fin];
        }
        flow+=aug[fin];
    }
    return flow;
}

int main()
{
    #ifdef debug
        freopen("E:\\Documents\\code\\input.txt","r",stdin);
        freopen("E:\\Documents\\code\\output.txt","w",stdout);
    #endif
    scanf("%d",&T);
    int a,b,c;
    while(T--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back(road(a,b,c,0));
            //G[b].push_back(road(b,a,c,0));
        }
        scanf("%d %d",&beg,&fin);
        if(beg==fin)
        {
            printf("0\n");
            continue;
        }
        Dijkstra();
        buildnet();
        printf("%d\n",Edmonds_Karp());
    }
    return 0;
}
