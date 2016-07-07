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
ll dp[200100],a[200100];
int n,w,T;
int main()
{
    //freopen( "testin_01.txt", "r", stdin);
    //freopen( "testout_01.txt", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d",&T);
    while (T--)
    {
           scanf("%d%d",&n,&w);

           memset(dp,INF,sizeof(dp));
           memset(a,0,sizeof(a));

           dp[0]=0;
           for (int i=1;i<=n;i++)
           {
                scanf("%d",&a[i]);
                dp[i]=w+dp[i-1];
                for (int j=i-1;j>=1 && a[i]-a[j]<=w/2;j--)
                     dp[i]=min(dp[i],dp[j-1]+(a[i]-a[j])*(a[i]-a[j])+w);
           }

           printf("%lld\n",dp[n]);

    }
    return 0;
}
