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
int n,T;
int dp[2][500010];
int a[51];
int main()
{
    //freopen( "testin_01.txt", "r", stdin);
    //freopen( "testout_01.txt", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d",&T);
    while (T--)
    {
           memset(dp,0,sizeof(dp));
           scanf("%d",&n);
           int h=0;
           for (int i=1;i<=n;i++)
           {
                scanf("%d",&a[i]);
                h+=a[i];
           }
           for (int i=1;i<=n;i++)
           {
                dp[i%2][a[i]]=a[i];
                for (int j=0;j<=h;j++)
                {
                     dp[i%2][j]=max(dp[i%2][j],dp[(i-1)%2][j]);
                     if (j+a[i]<=h && dp[(i-1)%2][j+a[i]]!=0) dp[i%2][j]=max(dp[i%2][j],dp[(i-1)%2][j+a[i]]+a[i]);
                     if (dp[(i-1)%2][abs(j-a[i])]!=0) dp[i%2][j]=max(dp[i%2][j],dp[(i-1)%2][abs(j-a[i])]+a[i]);
                }
           }
           if (dp[n%2][0]==0) printf("GG\n");
           else               printf("%d\n",dp[n%2][0]/2);

    }
    return 0;
}
