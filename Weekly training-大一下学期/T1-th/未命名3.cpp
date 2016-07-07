#include<iostream>
using namespace std;
int dp[20][20],sum[20],a[20];
int main()
{
	int i,k,l,n,j,m,flag;
	cin>>l;
	for(i=0;i<20;i++)
	for(j=0;j<20;j++)
	if(i!=j)
		dp[i][j]=0;
		else dp[i][j]=1;
	for(i=0;i<l;i++) cin>>a[i];
	for(k=0;k<l;k++)
	{
		for(i=0;i<20;i++)
		for(j=0;j<20;j++)
		if(i!=j)
			dp[i][j]=0;
		else dp[i][j]=1;
		dp[0][2]=2;
				for(j=2;j<=a[k];j++){
				
				for(i=j;i>=1;i--)
				{
					if(i<=j-2)
					flag=1;
					else
					flag=0;
					dp[i][j]=2*dp[i][j-1]*(i<=j-1)+2*dp[i+1][j-1]*flag+2*dp[i-1][j-1];
				}
				dp[0][j]=6*dp[1][j-1];
			}
		sum[k]=6*dp[1][a[k]-1];
		
	}
	for(i=0;i<l;i++)
	cout<<sum[i]<<endl;
	return 0;
}
