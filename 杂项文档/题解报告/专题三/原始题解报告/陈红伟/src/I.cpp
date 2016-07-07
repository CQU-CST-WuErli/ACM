#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,cnt,ans;
int head[50010],tot,dfs[50010],low[50010],bridge[50010];
struct node
{
    int to,nxt,tag,qu;
}edge[200010];
void add(int x,int y,int c)
{
    int i;
    for(i=head[x];i!=-1;i=edge[i].nxt)
    {
        if(edge[i].to==y)
        break;
    }
    if(i!=-1)
    {
        edge[i].tag=1;
        return;
    }
    edge[cnt].to=y;
    edge[cnt].nxt=head[x];
    edge[cnt].tag=0;
    edge[cnt].qu=c;
    head[x]=cnt++;
    return;
}
void tarjan(int x,int fa)
{
    dfs[x]=low[x]=++tot;
    for(int j=head[x];j!=-1;j=edge[j].nxt)
    {
        int y=edge[j].to;
        if(!dfs[y])
        {
            tarjan(y,x);
            low[x]=min(low[x],low[y]);
            if(low[y]>dfs[x]&&!edge[j].tag)
            {
                bridge[++ans]=edge[j].qu;
            }
        }
        else
        if(y!=fa)
        low[x]=min(low[x],dfs[y]);
    }
    return;
}
int main()
{
    // freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        cnt=0,tot=0,ans=0;
        memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y,i);
            add(y,x,i);
        }
        memset(dfs,0,sizeof(dfs));
        memset(low,0,sizeof(low));
        for(int i=1;i<=n;i++)
           if(!dfs[i])
            tarjan(i,-1);
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}