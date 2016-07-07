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
const int maxn=10;
int T;
int a[5][5],m[maxn][maxn],indegree[maxn];

bool topsort()
{

	for(int i=1; i<=9; i++)
	{
		for(int j=1; j<=9; j++)
		{
			if(indegree[j]==0)
			{
				indegree[j]--;
                for(int k=1; k<=9; k++)
					if(m[j][k])
                       indegree[k]--;
				break;
			}
		}
	}

	for (int i=1;i<=9;i++)
         if (indegree[i]>0) return 0;
    return 1;
}
int main()
{
    //freopen( "testin.txt", "r", stdin);
    //freopen( "testout.txt", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d",&T);
    while (T--)
    {
           memset(m,0,sizeof(m));
           memset(indegree,0,sizeof(indegree));

           for (int i=0;i<4;i++)
                for (int j=0;j<4;j++)
                     scanf("%d",&a[i][j]);

           for (int i=1;i<=9;i++)
                for (int j=(i-1)/3;j<=(i-1)/3+1;j++)
                     for (int k=(i-1)%3;k<=(i-1)%3+1;k++)
                     {
                          if (a[j][k]!=i)
                          {
                              if (!m[a[j][k]][i]) indegree[i]++;
                              m[a[j][k]][i]=1;
                          }
                     }
            if (topsort()) printf("Lucky dog!\n");
            else                 printf("BOOM!\n");
    }
    return 0;
}
