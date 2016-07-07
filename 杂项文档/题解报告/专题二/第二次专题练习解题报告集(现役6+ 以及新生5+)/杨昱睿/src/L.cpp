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
int T,n,w;
int gcd(int a, int b)
{
    return b==0 ? a:gcd(b,a%b);
}
int main()
{

    scanf("%d",&T);
    while (T--)
    {
           scanf("%d",&n);

           int flag=0,x=0,maxn=-INF;
           for (int i=1;i<=n;i++)
           {

                scanf("%d",&w);

                if (x==0) x=w;
                if (w==0)
                {
                    flag=1;
                    continue;
                }
                x=gcd(w,x);
                maxn=max(maxn,w);
           }

           int N;

           if (flag==1) N=maxn/x+1;
           else         N=maxn/x;
           double ans=N-n;
           for (int i=1;i<=N;i++)
                ans+=(1.0*N)/(1.0*i);

           int ans2=(int)ans;
           printf("%d\n",ans2);

    }
    return 0;
}

