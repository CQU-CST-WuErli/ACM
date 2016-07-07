#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 5000 + 10;
vector<int> G[maxn],M[maxn],l;
int dfn[maxn], low[maxn], belong[maxn], dfs_clock, scc_cnt,T,m,n,x,y;
stack<int> S;
int linker[maxn];
bool used[maxn];
bool dfs_2(int u)//从左边开始找增广路径
{

    for(int j=0;j<M[u].size();j++)//这个顶点编号从0开始，若要从1开始需要修改
    {
        int v=M[u][j];
        if(!used[v])
        {
          used[v]=true;
          if(linker[v]==-1||dfs_2(linker[v]))
          {//找增广路，反向
              linker[v]=u;
              return true;
          }
        }
    }
    return false;//这个不要忘了，经常忘记这句
}
int hungary()
{
    int res=0;
    memset(linker,-1,sizeof(linker));

    for(int i=0;i<l.size();i++)
    {
        memset(used,0,sizeof(used));
        if(dfs_2(l[i])) res++;
    }
    return res;
}

void dfs(int u){
     dfn[u] = low[u] = ++dfs_clock;
     S.push(u);
     for(int i=0; i<G[u].size(); ++i)
     {
         int v = G[u][i];
         if(!dfn[v])
         {
            dfs(v);
            low[u] = min(low[u], low[v]);
         }
         else if(!belong[v])
         {
            low[u] = min(low[u], dfn[v]);
         }
     }
     if(low[u] == dfn[u])
     {
         scc_cnt++;
         for (;;)
         {
            int x = S.top(); S.pop();
            belong[x] = scc_cnt;
            if(x == u) break;
         }
     }
     return;
}

void find_scc(int n)
{
     dfs_clock = scc_cnt = 0;
     memset(belong, 0, sizeof(belong));
     memset(dfn, 0, sizeof(dfn));
     memset(low,0,sizeof(low));
     for(int i=1; i<=n; i++)
         if(!dfn[i]) dfs(i);
}


int main()
{
  //freopen( "testin.txt", "r", stdin);
  //freopen( "testout.txt", "w", stdout);


  scanf("%d",&T);
  while (T--)
  {

         scanf("%d%d",&n,&m);
         for (int i=1;i<=n;i++)
         {
              G[i].clear();
              M[i].clear();
         }
         l.clear();

         for (int i=1;i<=m;i++)
         {
              scanf("%d%d",&x,&y);
              G[x].push_back(y);
         }
         find_scc(n);



         for(int i=1; i<=n; ++i)
             for(int j=0; j<G[i].size(); ++j)
             {
                 int v = G[i][j] ;
                 if (belong[i] != belong[v])
                 {

                     if (M[belong[i]].empty())
                         l.push_back(belong[i]);
                     M[belong[i]].push_back(belong[v]);


                 }
              }


        printf("%d\n",scc_cnt-hungary());
  }
}
