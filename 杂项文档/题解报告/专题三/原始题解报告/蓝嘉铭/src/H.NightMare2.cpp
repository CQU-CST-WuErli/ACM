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
const int N= 1e4+10;
const int maxn = 1e6+10;
const int maxm = 2e6+10;
struct Edge{
  int from,to,dist,val;
  Edge (int u, int v, int d,int va):from(u),to(v),dist(d),val(va){}
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

 void AddEdge(int from,int to,int dist,int val){
    edges.push_back(Edge(from,to,dist,val));
    m = edges.size();
    G[from].push_back(m-1);
 }

void dijkstra(int s,int mid)
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
            if (e.val < mid) continue;
            if (d[e.to] > d[u] + e.dist)
            {
                d[e.to] = d[u] + e.dist;
                p[e.to] = G[u][i];
                Q.push((HeapNode){d[e.to] ,e.to});
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
    int T,mm,k;
    cin>>T;
    while(T--)
    {
        cin>>n>>mm>>k;
        init(n);
        int Max = 0;
        for(int i = 0; i < mm; i++)
        {
            int u,v,dis,cap;
            cin>>u>>v>>cap>>dis;
            Max = max(Max,cap);
            AddEdge(u,v,dis,cap);
            AddEdge(v,u,dis,cap);
        }
        int l = 0,r = Max,mid;
        int answer;
        while(r >= l)
        {
           mid = (l+r) / 2;
           dijkstra(1,mid);
           //cout<<d[n]<<" "<<mid<<endl;
           if (d[n] <= k)
           {
               l = mid + 1;
               answer = mid;
           }
           else r = mid -1;
        }
        if (mid) cout<<answer<<"\n";
	    else cout<<"Poor RunningPhoton!\n";
	}
	return 0;
}
