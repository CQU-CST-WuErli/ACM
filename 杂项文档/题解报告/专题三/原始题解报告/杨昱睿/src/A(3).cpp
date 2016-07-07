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
int T,n,m,a,b;
int v[2000],v1[2000],v2[2000],fa[2000];
int findroot(int a)
{
    int tmp=a;
    while (fa[tmp]!=tmp)
           tmp=fa[tmp];
    fa[a]=tmp;
    return tmp;

}
int main()
{
    //freopen( "testin.txt", "r", stdin);
    //freopen( "testout.txt", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d",&T);
    while (T--)
    {
           memset(v,0,sizeof(v));
           memset(v1,0,sizeof(v1));
           memset(v2,0,sizeof(v2));

           scanf("%d%d",&n,&m);
           for (int i=1;i<=n;i++)
                fa[i]=i;
           for (int i=1;i<=m;i++)
           {
                scanf("%d%d",&a,&b);
                v[a]++;
                v[b]++;
                v2[a]++;
                v1[b]++;
                if (findroot(a)!=findroot(b))
                    fa[fa[a]]=fa[b];
           }
           int p=findroot(1),jud=0;
           for (int i=1;i<=n;i++)
                if (findroot(i)!=p)
                {
                    jud=1;
                    break;
                }

           if (jud==1)
           {
               printf("No No\n");
               continue;
           }

           int sum1=0;
           for (int i=1;i<=n;i++)
                if (v[i]%2==1) sum1++;
           if (sum1==0 || sum1==2) printf("Yes ");
           else                    printf("No ");

           int sum2=0,sum3=0,jud2=0;
           for (int i=1;i<=n;i++)
           {
                if (v1[i]!=v2[i])
                {
                    if (v1[i]-v2[i]==1)
                    {
                        sum2++;
                    }
                    else if (v2[i]-v1[i]==1)
                    {
                        sum3++;
                    }
                    else
                    {
                        jud2=1;
                        break;
                    }
                }
           }
           if (jud2==1) printf("No\n");
           else
           {
               if((sum2==1 && sum3==1) || (sum2==0 && sum3==0)) printf("Yes\n");
               else                                             printf("No\n");
           }
    }

    return 0;
}
