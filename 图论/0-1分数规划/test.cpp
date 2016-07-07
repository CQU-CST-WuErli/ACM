#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#define eps 1e-5
using namespace std;
const int  Maxn=105;
const int  Maxm=100005;
const int inf=1<<30;
struct po
{
    int u,v;
} Point[Maxn*10];
struct node
{
    int v,next;
    double w;
} Edge[Maxm];
int n,m,head[Maxn],du[Maxn],deep[Maxn],des,cnt,inx;
bool vis[Maxn];
void addedge(int u,int v,double w)
{
    // cout << u << ' ' << v << ' ' << w << endl;
    Edge[cnt].v=v;
    Edge[cnt].w=w;
    Edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
    Edge[cnt].v=u;
    Edge[cnt].w=0;
    Edge[cnt].next=head[v];
    head[v]=cnt;
    cnt++;
}
void build(double g)
{
    for(int i=0; i<m; i++)
    {
        addedge(Point[i].u,Point[i].v,1);
        addedge(Point[i].v,Point[i].u,1);
    }
    for(int i=1; i<=n; i++)
    {
        addedge(0,i,m);
        addedge(i,des,m*1.0+2*g-du[i]*1.0);
    }
}
bool bfs()
{
    memset(deep,-1,sizeof(deep));
    queue <int > q;
    q.push(0);
    deep[0]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        int p=head[t];
        while(p!=-1)
        {
            int v=Edge[p].v;
            if( deep[v]==-1&&Edge[p].w>0)
            {
                q.push(v);
                deep[v]=deep[t]+1;
            }
            p=Edge[p].next;
        }
    }
    return deep[n+1]!=-1;
}
void does(int u,int v,double w)
{
    int p =head[u];
    while(Edge[p].v!=v)
    {
        p=Edge[p].next;
    }
    Edge[p].w+=w;
}
double dfs(int src,double flow)
{
    if(src==n+1)return flow;
    double sum=0;
    int p=head[src];
    while(p!=-1)
    {
        int v=Edge[p].v;
        if(deep[v]==deep[src]+1&&Edge[p].w>0)
        {
            double tmp=dfs(v,min(flow-sum,Edge[p].w));
            sum+=tmp;
            Edge[p].w-=tmp;
            does(v,src,tmp);
        }
        p=Edge[p].next;
    }
    return sum;
}
double Dinic()
{
    double ans=0;
    while(bfs())
    {
        ans+=dfs(0,inf);
    }
    return ans;
}
void Findvis(int u)
{
    vis[u]=true;
    if(u<=n&&u!=0)inx++;
    for(int i=head[u]; i!=-1; i=Edge[i].next)
    {
        if(!vis[Edge[i].v]&&Edge[i].w>0)
        {
            Findvis(Edge[i].v);
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!m)
        {
            printf("1\n1\n");  //当没有边的时候最大密度子图里面只有一个顶点 ，任意一个可以输出1号点
            continue ;
        }
        memset(du,0,sizeof(du)); //初始化点的度记录数组
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&Point[i].u,&Point[i].v);
            du[Point[i].u]++;  //点X与Y之间有边，所以X与Y的度各加一
            du[Point[i].v]++;
        }
        double high=m;
        double low=0;
        des=n+1;
        while(high-low>1.0/n/n) //二分搜索最大密度
        {
            cnt=0;
            memset(head,-1,sizeof(head));
            double mid=(high+low)/2,t;
            cout << mid << endl;
            build(mid);//根据密度值建图
            t=Dinic(); //求最大流
            t=(m*n*1.0-t)/2;
            if(t > eps)
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
        }
        cnt=0;
        memset(head,-1,sizeof(head));
        memset(vis,false,sizeof(vis));
        // std::cout << low << std::endl;
        cout << "-----------------------------\n";
        build(low);
        Dinic();
        inx=0;
        Findvis(0);
        printf("%d\n",inx);
        for(int i=1; i<=n; i++)
        {
            if(vis[i])
                printf("%d\n",i);
        }
    }
    return 0;
}