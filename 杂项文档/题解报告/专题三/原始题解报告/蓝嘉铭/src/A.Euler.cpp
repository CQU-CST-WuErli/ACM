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
const int maxm = 2e5;
vector<int> mp[maxn];
int ans;
int ind[maxn],oud[maxn],deg[maxn];
bool vis[maxn];
void dfs(int u)
{
    for(int i = 0;i < mp[u].size(); i++)
        if(!vis[mp[u][i]])
        {
           vis[mp[u][i]] = true;
            ans++;
           dfs(mp[u][i]);
        }
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\lanjiaming\\Desktop\\acm\\in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
    int T,n,m;
    cin>>T;
    while(T--)
    {
       cin>>n>>m;
       memset(deg,0,sizeof(deg));
       memset(ind,0,sizeof(ind));
       memset(oud,0,sizeof(oud));
       memset(vis,false,sizeof(vis));
       for(int i = 0; i <= n; i++) mp[i].clear();
       for(int i = 1; i <= m ; i++)
       {
           int x,y;
           cin>>x>>y;
           mp[x].push_back(y);
           mp[y].push_back(x);
           deg[x]++;deg[y]++;
           ind[y]++;oud[x]++;
       }

       int cnt = 0;
       for(int i = 1; i <= n; i++)
           if(deg[i]&1) cnt++;

        bool ok = true;
       if(!(cnt == 0 || cnt == 2)) {cout<<"No ";ok = false;}
       if (ok)
       {
           ans = 1;
           vis[1] = true;
           dfs(1);
           //cout<<ans<<"..."<<endl;
           if(ans == n) cout<<"Yes ";
           else {cout<<"No ";ok = false;}
       }

       if (!ok) {cout<<"No\n";continue;}
       cnt=0;
       ok = true;
       int a[5];
       for(int i = 1; i <= n; i++)
       {
           if(ind[i] != oud[i])
           {
               a[cnt] = i;
               cnt++;
           }
           if(cnt > 2) {ok = false; break;}
          // if(ind[i] == 0 && oud[i] == 0) {ok = false; break;}
       }
       if(cnt == 2)
       {
         if (ind[a[0]] == oud[a[0]]+1 && ind[a[1]] == oud[a[1]]-1 ||
            ind[a[1]] == oud[a[1]]+1 && ind[a[0]] == oud[a[0]]-1)
              ok = true;
         else ok = false;
       }

       if(ok)   cout<<"Yes\n";
       else cout<<"No\n";
    }
	return 0;
}
