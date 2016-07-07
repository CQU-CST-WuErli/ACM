#include<cstdio>
#include<cstring>
int a[100500],b[100500],dp[100100],v[110],c[110];
int n,V,l,r,T;
void insert(int x,int y)
{
	while(l<=r&&b[r]<=y)r--;
	a[++r]=x;b[r]=y;
}
int main()
{
    //freopen( "testin_01.txt", "r", stdin);
    //freopen( "testout_01.txt", "w", stdout);

	scanf("%d",&T);
	while (T--)
    {
        scanf("%d%d",&n,&V);
	    int i,j,d;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			scanf("%d",&v[i]);
		for (i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
			if(V/v[i]<c[i])
				c[i]=V/v[i];
        }
        for (i=0;i<n;i++)
            for(d=0;d<v[i];d++)
			{
				l=1;
				r=0;
				for(j=0;j<=(V-d)/v[i];j++)
				{
					insert(j,dp[j*v[i]+d]-j*v[i]);
					if(a[l]<j-c[i])l++;
					dp[j*v[i]+d]=b[l]+j*v[i];
				}
			}

		if (dp[V]==V) printf("yes\n");
		else          printf("no\n");

   }
	return 0;
}

