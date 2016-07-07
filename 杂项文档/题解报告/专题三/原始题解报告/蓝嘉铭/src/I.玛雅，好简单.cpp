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
    int to , next,num;
}edge[maxm];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];
int Index,top;
int bridge;
bool instack[maxn];
void addedge(int u ,int v)
{
    edge[tot].to = v; edge[tot].next = head[u];
    edge[tot].num = 1; head[u] = tot++;
}
void Tarjan(int u,int pre)
{
   int v;
   Low[u] = DFN[u] = ++Index;
   Stack[top++] = u;
   instack[u] = true;
   for (int i = head[u]; i != -1; i = edge[i].next)
   {
       v = edge[i].to;
       if(v==pre) continue;
       if (!DFN[v])
       {
           Tarjan(v,u);
           if (Low[u] > Low[v]) Low[u] = Low[v];
           if (Low[v] > DFN[u] && edge[i].num == 1) bridge++;
       }
       else if (Low[u] > DFN[v]) Low[u] = DFN[v];
    }
    --top;
    instack[v] = false;
}
void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(instack,false,sizeof(instack));
    Index = top = 0;
    for (int i = 1; i <= N; i++)
        if(!DFN[i]) Tarjan(i,i);
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
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
         map<int,int> mp;
         mp.clear();
         for (int i = 0; i < m; i++)
         {
            int x,y;
            cin>>x>>y;
            mp[x*maxn+y]++;
            mp[y*maxn+x]++;
            if (mp[x*maxn+y]==1)
            {
                addedge(x,y);
                addedge(y,x);
            }
            else
            {
                for (int k = head[x]; k != -1; k = edge[k].next)
                {
                    int v = edge[k].to;
                    if (v == y)
                    {
                        edge[k].num++;
                        edge[k^1].num++;
                    }
                }
            }

         }
         bridge = 0;
         solve(n);
         kase++;
         cout<<"Case "<<kase<<": ";
         cout<<bridge<<"\n";
    }
	return 0;
}
