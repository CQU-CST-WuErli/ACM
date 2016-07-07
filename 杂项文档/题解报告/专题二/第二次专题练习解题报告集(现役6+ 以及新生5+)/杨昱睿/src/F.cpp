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
int dp[150001];
int a[301],b[310],t[301];
int n,m,T,d;
int maxv[700000];
int query(int o,int l,int r,int ql,int qr)
{
    int m=(l+r)/2,ans=-INF;
    if (ql<=l && r<=qr) return maxv[o];
    if (ql<=m) ans=max(ans,query(o*2,l,m,ql,qr));
    if (m<qr) ans=max(ans,query(o*2+1,m+1,r,ql,qr));
    return ans;
}
int build(int o,int l,int r)
{
     if (l==r)
     {
        maxv[o]=dp[l];
        return maxv[o];
     }
     int m=(l+r)/2;
     maxv[o]=max(build(o*2,l,m),build(o*2+1,m+1,r));
     return maxv[o];
}
int main()
{
    //freopen( "testin_01.txt", "r", stdin);
    //freopen( "testout_01.txt", "w", stdout);
    //ios::sync_with_stdio(false);

    scanf("%d",&T);
    while (T--)
    {

           memset(t,0,sizeof(t));
           memset(dp,0,sizeof(dp));
           scanf("%d%d%d",&n,&m,&d);
           build(1,1,n);

           for (int i=1;i<=m;i++)
           {

                scanf("%d%d%d",&a[i],&b[i],&t[i]);
                int h=d*(t[i]-t[i-1]);
                for (int j=1;j<=n;j++)
                     dp[j]=query(1,1,n,max(j-h,1),min(j+h,n))+b[i]-abs(a[i]-j);
                build(1,1,n);
           }

           int maxn=query(1,1,n,1,n);

           printf("%d\n",maxn);
    }
    return 0;
}

