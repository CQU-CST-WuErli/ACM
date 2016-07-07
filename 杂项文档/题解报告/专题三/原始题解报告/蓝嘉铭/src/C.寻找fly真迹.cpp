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
const int maxn = 1000;
const int maxm = 2e6+10;
bool mp[maxn][maxn],vis[maxn];
int ind[maxn];
int f[maxn],Hash[maxn];
int Find(int x)
{
	 if (f[x]!=x) return f[x]=Find(f[x]);
	 return f[x];
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
        memset(mp,false,sizeof(mp));
        memset(vis,true,sizeof(vis));
        memset(ind,0,sizeof(ind));
         cin>>n>>m;
         while(m--)
         {
             int u,v;
             cin>>u>>v;
             if (!mp[u][v])
             {
                 ind[u]++;ind[v]++;
             }
             mp[u][v] = true;
             mp[v][u] = true;
         }
     bool ok = false;
     for(int i = 1; i <= n; i++)
         if (ind[i] == n-1) vis[i] = false;
     for(int i = 1;i <= n;i++)
     {
      for(int j = 1;j <= n;j++)
      {
          if(!mp[i][j] && i != j && vis[i] && vis[j])
          {
              for(int k = 1;k <= n;k++)
              {
                  if(mp[i][k] && mp[k][j] && i != k && j != k && vis[k])
                  {
                      ok = true;
                      break;
                  }
              }
              if (ok) break;
          }
      }
      if (ok) break;
     }


    for (int i = 1 ; i <= n ; i++)  f[i]=i;
       	memset(Hash,0,sizeof(Hash));

       	for (int x = 1; x < n ; x++)
        {
          for(int y = x+1; y <= n; y++)
          {
           if (!mp[x][y])
   		   {
       	      if (Find(x)== Find(y)) { ok = true;break;}

			  if (Hash[x]==0)   Hash[x] = y;
			  else
              {
				int t1=Find(Hash[x]);
				int t2=Find(y);
				if (t1!=t2)  f[t1]=t2;
			  }

			  if (Hash[y]==0)   Hash[y] = x;
			  else
              {
				int t1=Find(Hash[y]);
				int t2=Find(x);
				if (t1!=t2)  f[t1]=t2;
			  }
	   	    }

          }
          if (ok) break;
        }


       if (!ok) cout<<"Yes\n";
       else cout<<"No\n";
    }
	return 0;
}
