#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
const int MOD=1e9+7;
int T,m;
ll n;
ll d[3];
ll y[600];
struct Matrix
{
    ll mat[3][3];
};
Matrix mul(Matrix a,Matrix b)
{
    Matrix ret;
    for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
        {
            ret.mat[i][j]=0;
            for(int k=0;k<=2;k++)
            {
                ret.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                ret.mat[i][j]%=MOD;
            }
        }
    return ret;
}
Matrix pow_M(Matrix a,ll n)
{
    Matrix ret;
    memset(ret.mat,0,sizeof(ret.mat));
    ret.mat[1][2]=ret.mat[0][1]=ret.mat[2][0]=ret.mat[2][1]=ret.mat[2][2]=1;
    Matrix temp=a;
    while(n)
    {
        if(n&1)ret=mul(ret,temp);
        temp=mul(temp,temp);
        n>>=1;
    }
    return ret;
}
int main()
{
    //freopen( "testin_01.txt", "r", stdin);
    //freopen( "testout_01.txt", "w", stdout);
    scanf("%d",&T);
    Matrix a;
    memset(a.mat,0,sizeof(a.mat));
    a.mat[1][2]=a.mat[0][1]=a.mat[2][0]=a.mat[2][1]=a.mat[2][2]=1;
    while (T--)
    {
           d[0]=0;d[1]=0;d[2]=1;
           scanf("%lld%d",&n,&m);
           for (int i=0;i<m;i++)
                scanf("%lld",&y[i]);
           sort(y,y+m);

           if (y[0]==0 || y[m-1]==n)
           {
               printf("0\n");
               continue;
           }

           ll p=0;
           for (int i=0;i<m;i++)
           {
                ll x=y[i];

                if (x-p==1)
                {
                    d[0]=d[1];
                    d[1]=d[2];
                    d[2]=0;
                }
                else if (x-p==2)
                {
                    d[1]=((d[0]+d[1])%MOD+d[2])%MOD;
                    d[0]=d[2];
                    d[2]=0;
                }
                else
                {
                    Matrix tmp=pow_M(a,x-p-3);
                    ll a0=((tmp.mat[2][0]*d[0]+tmp.mat[2][1]*d[1])%MOD+tmp.mat[2][2]*d[2])%MOD;
                    tmp=mul(tmp,a);
                    ll a1=((tmp.mat[2][0]*d[0]+tmp.mat[2][1]*d[1])%MOD+tmp.mat[2][2]*d[2])%MOD;
                    d[0]=a0;d[1]=a1;d[2]=0;
                }
                p=x;
           }

           Matrix tmp=pow_M(a,n-p-1);
           ll ans=((tmp.mat[2][0]*d[0]+tmp.mat[2][1]*d[1])%MOD+tmp.mat[2][2]*d[2])%MOD;
           printf("%lld\n",ans);
    }

    return 0;
}

