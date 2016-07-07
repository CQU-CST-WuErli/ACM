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

using namespace std;
const int maxn=5e5+10;
const int maxm=2e6+10;
int fa[maxn];
int n,m,T;
struct M
{
     int a,b,c;
} e[maxm];

int cmp(M a,M b)
{
    return a.c<b.c;
}
int findroot(int a)
{
	int tmp=a;
	while(fa[tmp]!=tmp)
		 tmp=fa[tmp];
   	return tmp;
   	fa[a]=tmp;
}
int main()
{
    //freopen( "testin.txt", "r", stdin);
    //freopen( "testout.txt", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d",&T);
    while (T--)
    {
           scanf("%d%d",&n,&m);
           for (int i=1;i<=n;i++)
                fa[i]=i;

           for (int i=0;i<m;i++)
                scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
           sort(e,e+m,cmp);

           int num=0,p=0,jud=0;
           while (num<n && p<m)
           {
                  if (findroot(e[p].a)!=findroot(e[p].b))
                  {
                      num++;
                      fa[fa[e[p].b]]=fa[e[p].a];
                  }
                  else
                  {
                      printf("%d\n",e[p].c);
                      jud=1;
                      break;
                  }
                  p++;
           }
           if (jud==0) printf("No solution!\n");

    }
    return 0;
}

