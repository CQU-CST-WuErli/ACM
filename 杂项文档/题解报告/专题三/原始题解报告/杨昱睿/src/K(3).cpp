#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<limits>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<map>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll long long
#define M 1000000007
using namespace std;
const int maxn = 5000 + 10;
vector<int> G[maxn],g[maxn],scc[maxn];
int dfn[maxn], low[maxn], belong[maxn],q[maxn],siz[maxn],in[maxn],jud[maxn],dfs_clock, scc_cnt,ans,T,m,n,a,b;
stack<int> S;
void dfs(int u){
  dfn[u] = low[u] = ++dfs_clock;
  S.push(u);
  for(int i=0; i<G[u].size(); ++i){
    int v = G[u][i];
    if(!dfn[v]){
      dfs(v);
      low[u] = min(low[u], low[v]);
    }else if(!belong[v]){
      low[u] = min(low[u], dfn[v]);
    }
  }
  if(low[u] == dfn[u]){
    scc_cnt++;
    for(;;){
      int x = S.top(); S.pop();
      belong[x] = scc_cnt;
      scc[scc_cnt].push_back(x);
      if(x == u) break;

    }
  }
}
void find_scc(int n){
  dfs_clock = scc_cnt = 0;
  memset(belong, 0, sizeof(belong));
  memset(dfn, 0, sizeof(dfn));
  for(int i=0; i<n; ++i)
    if(!dfn[i]) dfs(i);
}
void ddfs(int u)
{
    ans+=scc[u].size();
    jud[u]=1;
    for (int i=0;i<g[u].size();i++)
         if (!jud[g[u][i]])
             ddfs(g[u][i]);
    return;
}

int main()
{
    //freopen( "testin.txt", "r", stdin);
    //freopen( "testout.txt", "w", stdout);
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
           scanf("%d%d",&n,&m);
           for (int i=0;i<=n+10;i++)
           {
                g[i].clear();
                G[i].clear();
                scc[i].clear();
           }
           for (int i=0;i<m;i++)
           {
                scanf("%d%d",&a,&b);
                G[a].push_back(b);
           }
           find_scc(n);
           memset(in,0,sizeof(in));
           for(int i=0; i<n; ++i)
               for(int j=0; j<G[i].size(); ++j)
               {
                   int v = G[i][j] ;
                   if (belong[i]!=belong[v])
                   {
                       g[belong[v]].push_back(belong[i]);
                       in[belong[i]]++;
                   }
               }

           int maxnn=-INF;
           memset(siz,0,sizeof(siz));
           for (int i=1;i<=scc_cnt;i++)
           {
                if (in[i]==0)
                {
                    memset(jud,0,sizeof(jud));
                    ans=-1;
                    ddfs(i);
                    siz[i]=ans;
                    maxnn=max(siz[i],maxnn);
                }
           }
           printf("Case %d: %d\n",cas,maxnn);
           int cnt=0;
           for (int i=1;i<=scc_cnt;i++)
           {
                if (siz[i]==maxnn)
                    for (int j=0;j<scc[i].size();j++)
                         q[cnt++]=scc[i][j];
           }
           sort(q,q+cnt);
           printf("%d",q[0]);
           for (int i=1;i<cnt;i++)
                printf(" %d",q[i]);
           printf("\n");
    }
    return 0;
}

