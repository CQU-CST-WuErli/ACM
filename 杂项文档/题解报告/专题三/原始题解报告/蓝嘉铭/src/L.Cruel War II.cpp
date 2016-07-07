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
int ans,n,m;
struct NOde{
    int u,v;
}edge[maxm];
bool vis[maxn];
void work(int u,int num)
{
    if (num >= ans) return;
    if (u >= m) {ans = num;return;}
    if (vis[edge[u].u] || vis[edge[u].v])
         work(u+1,num);
    if (!vis[edge[u].u] && !vis[edge[u].v])
    {
        vis[edge[u].u] = true;
        work(u+1,num+1);
        vis[edge[u].v] = true;
        vis[edge[u].u] = false;
        work(u+1,num+1);
        vis[edge[u].v] = false;
    }
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\lanjiaming\\Desktop\\acm\\in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
         cin>>n>>m;
        uN = n;
         for(int i = 0;i <= uN; i++) EV[i].clear();
         for (int i = 0; i < m; i++)
         {
             int x,y;
             cin>>x>>y;
             edge[i].u = x;edge[i].v = y;
             EV[x].push_back(y);
            EV[y].push_back(x);
         }
         ans = hungary()/2;
         if (ans > 10) {cout<<"Poor lcy\n";continue;}
         ans = 11;
         memset(vis,false,sizeof(vis));
         work(0,0);
         if (ans <=10) cout<<ans<<"\n";
         else cout<<"Poor lcy\n";
    }
	return 0;
}
