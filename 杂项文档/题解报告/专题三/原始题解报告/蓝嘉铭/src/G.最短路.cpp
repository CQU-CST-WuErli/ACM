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
const int N= 1010;
const int maxn = 1e6+10;
const int maxm = 2e6+10;
struct Edge{
  int from,to,dist;
  Edge (int u, int v, int d):from(u),to(v),dist(d){}
};
struct HeapNode{
   int d,u;
   bool operator < (const HeapNode& rhs)const{
      return d>rhs.d;
   }
};
 int n, m;
 vector<Edge> edges;
 vector<int> G[N];
 bool done[N];
 int d[N];
 int p[N];

 void init(int n){
  for (int i = 0; i <= n; i++) G[i].clear();
  edges.clear();
 }

 void AddEdge(int from,int to,int dist){
    edges.push_back(Edge(from,to,dist));
    m = edges.size();
    G[from].push_back(m-1);
 }

void dijkstra(int s)
{
    priority_queue<HeapNode> Q;
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0;
    memset(done,0,sizeof(done));
    Q.push((HeapNode){0,s});
    while (!Q.empty())
    {
        HeapNode x = Q.top();Q.pop();
        int u = x.u;
        if (done[u]) continue;
        done[u] = true;
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge& e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.dist)
            {
                d[e.to] = d[u] + e.dist;
                p[e.to] = G[u][i];
                Q.push((HeapNode){d[e.to] ,e.to});
            }
        }
    }
}
bool ok;
int vis[N],ve[maxn];
void dfs(int x,int End,int sum)
{
    if (x == End && sum == d[End]) {ok = true; return;}
    if (sum > d[End]) return;
    vis[x] = true;
    for (int i = 0; i < G[x].size(); i++)
    {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && !ve[G[x][i]])
        {
            ve[G[x][i]] = true;
            dfs(e.to,End,sum+e.dist);
            if (ok) return;
            ve[G[x][i]] = false;
        }
    }
    vis[x] = false;
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\lanjiaming\\Desktop\\acm\\in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
    int T,mm;
    cin>>T;
    while(T--)
    {
        cin>>n>>mm;
        init(n);
        for(int i = 0; i < mm; i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            AddEdge(x,y,z);
        }
        int Start,End;
        cin>> Start>>End;
        dijkstra(Start);
         //cout<<d[End]<<endl;
        int ans = 0;
        memset(ve,false,sizeof(ve));
        while(1)
        {
            memset(vis,false,sizeof(vis));
            ok = false;
            dfs(Start,End,0);
            if (ok) ans++;
            else break;
        }
        cout<<ans<<"\n";
	}
	return 0;
}
