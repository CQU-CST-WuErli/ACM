#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<cctype>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<sstream>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N= 500000;
const int maxn = 1e4+10;
const int maxm = 1e5+10;
struct Edge
{
    int to , next;
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];
int Index,top;
int scc;
bool instack[maxn];
int num[maxn];
void addedge(int u ,int v)
{
    edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
}
void Tarjan(int u)
{
   int v;
   Low[u] = DFN[u] = ++Index;
   Stack[top++] = u;
   instack[u] = true;
   for (int i = head[u]; i != -1; i = edge[i].next)
   {
       v = edge[i].to;
       if (!DFN[v])
       {
           Tarjan(v);
           if (Low[u] > Low[v]) Low[u] = Low[v];
       }
       else if (instack[v] && Low[u] > DFN[v]) Low[u] = DFN[v];
    }
       if (Low[u] == DFN[u])
       {
           scc++;
           do
           {
               v = Stack[--top];
               instack[v] = false;
               Belong[v] = scc;
               num[scc]++;
           }while( v != u);
       }
}
void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(instack,false,sizeof(instack));
    memset(num,0,sizeof(num));
    Index = scc = top = 0;
    for (int i = 1; i <= N; i++)
        if(!DFN[i]) Tarjan(i);
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
vector <int> mp[5010];
int ind[5010],answer[5010];
bool vis[5010];
int ans;
void dfs(int u)
{
    vis[u] = true;
    ans += num[u];
    for(int i = 0; i < mp[u].size(); i++)
        if(!vis[mp[u][i]]) dfs(mp[u][i]);
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\lanjiaming\\Desktop\\acm\\in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
    int T,n,m,kase = 0;
    cin>>T;
    while(T--)
    {
         cin>>n>>m;
         init();
         for (int i = 0; i < m; i++)
         {
             int x,y;
             cin>>x>>y;
             addedge(x+1,y+1);
         }
         solve(n);

         for(int i = 0; i <= n; i++) mp[i].clear();
         memset(ind,0,sizeof(ind));
         for(int i = 1; i <= n; i++)
           for (int j = head[i]; j != -1; j = edge[j].next)
            if(Belong[i]!=Belong[edge[j].to])
            {
                ind[Belong[i]]++;
                mp[Belong[edge[j].to]].push_back(Belong[i]);
            }
         int Max = 0;
        for(int i = 1; i <= scc; i++)
           if (ind[i]==0)
            {
                memset(vis,false,sizeof(vis));
                ans = 0;
                dfs(i);
                answer[i] = ans;
                if (ans > Max) Max = ans;
            }
        kase++;
       cout<<"Case "<<kase<<": "<<Max-1<<"\n";
       bool ok = false;
       for(int i = 1; i <= n; i++)
        if (Max == answer[Belong[i]])
        {
            if(!ok)
            {
              cout<<i-1;
              ok = true;
            }
            else cout<<" "<<i-1;
        }
        cout<<"\n";
    }
	return 0;
}
