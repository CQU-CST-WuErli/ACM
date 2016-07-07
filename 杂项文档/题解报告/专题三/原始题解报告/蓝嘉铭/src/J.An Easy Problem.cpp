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
const int maxn = 1e3+10;
const int maxm = 1e4+10;
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

vector<int>EV[maxn];
int linker[maxn];
bool used[maxn];
int uN;
bool dfs(int u)
{
    for(int i = 0;i < EV[u].size();i++)
    {
        int v = EV[u][i];
        if(!used[v])
        {
            used[v]=true;
            if(linker[v] == -1 || dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u = 1;u <= uN; u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))  res++;
    }
    return res;
}
bool vis[maxn];
vector<int>mp[maxn];
void bfs(int u)
{
	queue <int> Q;
	vis[u] = true;
	Q.push(u);
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop();
        for (int i = 0; i < mp[x].size(); i++)
        {
            int v =mp[x][i];
			if(!vis[v])
			{
			  vis[v] = true;
			  EV[u].push_back(v);
			  Q.push(v);
			}
		}
	}
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
             addedge(x,y);
         }
         solve(n);

         uN = scc;
         for(int i = 0;i <= scc; i++) {mp[i].clear();EV[i].clear();}
         for(int i = 1; i <= n; i++)
           for (int j = head[i]; j != -1; j = edge[j].next)
            if(Belong[i]!=Belong[edge[j].to]) mp[Belong[i]].push_back(Belong[edge[j].to]);


        for(int i = 1; i <= scc; i++)
        {
            memset(vis, false, sizeof(vis));
            bfs(i);
        }

    /*    for(int i = 1; i <= scc; i++)
        {
            cout<<i<<"  :";
            for(int j = 0; j < EV[i].size();j++)
                cout<<EV[i][j]<<" ";
            cout<<endl;
        }*/
        kase++;
        cout<<"Case "<<kase<<": "<<uN-hungary()<<"\n";
    }
	return 0;
}
