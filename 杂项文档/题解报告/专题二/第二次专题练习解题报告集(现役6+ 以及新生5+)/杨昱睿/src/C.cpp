#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int dp[41][41][41][41];
int sum[5],a[500];
int x,n,m,T;
int main()
{
    //freopen( "testin_01.txt", "r", stdin);
    //freopen( "testout_01.txt", "w", stdout);
    scanf("%d",&T);
    while (T--)
    {
           memset(sum,0,sizeof(sum));
           memset(a,0,sizeof(a));
           memset(dp,0,sizeof(dp));

           scanf("%d%d",&n,&m);
           for (int i=0;i<n;i++)
                scanf("%d",&a[i]);
           for (int i=1;i<=m;i++)
           {
                scanf("%d",&x);
                sum[x]+=1;
           }

           dp[0][0][0][0]=a[0];
           for (int i=0;i<=sum[1];i++)
                for (int j=0;j<=sum[2];j++)
                     for (int k=0;k<=sum[3];k++)
                          for (int p=0;p<=sum[4];p++)
                          {
                               int t=i+j*2+k*3+p*4;
                               if (i>0) dp[i][j][k][p]=dp[i-1][j][k][p]+a[t];
                               if (j>0) dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j-1][k][p]+a[t]);
                               if (k>0) dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j][k-1][p]+a[t]);
                               if (p>0) dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j][k][p-1]+a[t]);
                          }
            printf("%d\n",dp[sum[1]][sum[2]][sum[3]][sum[4]]);

    }

    return 0;
}
