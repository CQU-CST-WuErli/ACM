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
int m[550][550],a,b,color[550],T,n,m0;
int main()
{
   // freopen( "testin.txt", "r", stdin);
   // freopen( "testout.txt", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d",&T);
    while (T--)
    {
        memset(m,0,sizeof(m));
        memset(color,0,sizeof(color));

        scanf("%d%d",&n,&m0);
        for (int i=1;i<=n;i++)
             m[i][i]=1;
        for (int i=1;i<=m0;i++)
        {
             scanf("%d%d",&a,&b);
             m[a][b]=m[b][a]=1;
        }

        int jud=0;
        for (int i=1;i<=n;i++)
             for (int j=1;j<=n;j++)
                  if (!m[i][j])
                  {
                      if (color[i]==0 && color[j]==0)       {color[i]=1;color[j]=2;}
                      if (color[i]==0 && color[j]!=0)        color[i]=3-color[j];
                      if (color[i]!=0 && color[j]==0)        color[j]=3-color[i];
                  }
        for (int i=1;i<=n;i++)
             for (int j=1;j<=n;j++)
             {
                  if (!m[i][j] && color[i]==color[j]) jud=1;
                  if (m[i][j] && color[i]==3-color[j]) jud=1;
             }

        if (jud==1) printf("No\n");
        else        printf("Yes\n");
    }
    return 0;
}
