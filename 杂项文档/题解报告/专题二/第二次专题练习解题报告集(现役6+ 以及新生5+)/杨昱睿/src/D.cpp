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
#define M 1e9+7
using namespace std;
int n,T;
int dp[2][1000000][2];
int a[2500],b[2500];
int main()
{
    //freopen("testin.txt","r",stdin);
    //freopen("testout.txt","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
           scanf("%d",&n);

           int sum1=0,sum2=0;
           for (int i=1;i<=n;i++)
           {
                scanf("%d%d",&a[i],&b[i]);
                if (a[i]<=b[i]) sum1+=a[i];
                else            sum2+=b[i];
           }
           int maxsum=max(sum1,sum2);
           memset(dp,INF,sizeof(dp));
           dp[1][a[1]][0]=a[1];
           dp[1][b[1]][1]=b[1];


           for (int i=2;i<=n;i++)
           {

                for (int j=0;j<=a[i];j++)
                     dp[i%2][j][0]=min(dp[(i-1)%2][a[i]-j][1]+a[i],dp[(i-1)%2][j+b[i]][0]+b[i]);

                for (int j=a[i]+1;j<=maxsum;j++)
                     dp[i%2][j][0]=min(dp[(i-1)%2][j-a[i]][0]+a[i],dp[(i-1)%2][j+b[i]][0]+b[i]);

                for (int j=0;j<=b[i];j++)
                     dp[i%2][j][1]=min(dp[(i-1)%2][j+a[i]][1]+a[i],dp[(i-1)%2][b[i]-j][0]+b[i]);

                for (int j=b[i]+1;j<=maxsum;j++)
                     dp[i%2][j][1]=min(dp[(i-1)%2][j+a[i]][1]+a[i],dp[(i-1)%2][j-b[i]][1]+b[i]);
             }
             int minn=INF;
             for (int i=0;i<=maxsum;i++)
                  for (int k=0;k<=1;k++)
                       minn=min(minn,(dp[n%2][i][k]+i)/2);
             printf("%d\n",minn);

    }
    return 0;
}
