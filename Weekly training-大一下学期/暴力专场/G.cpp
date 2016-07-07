//  Created by  CQUWEL			                       
//  Copyright (c) 2015Äê Team 3. All rights reserved.  

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>           
#include <algorithm>
#include <cctype>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;

int m[22][22],vis[22][22];
int y;
int ans,temp;
int M,n;
void dfs(int i,int j)
{
	if (m[i][j]==1 && vis[i][j]==0)
	{
		temp++;
		vis[i][j]=1;
		for (int k=i-1;k<=i+1;k++)
			for (int l=j-1;l<=j+1;l++)
			{
				if ((k==i && l==j) || k<=0 || k>=M+1 || l<=0 || l>=n+1)
					continue;
				else 
					dfs(k,l);
			}
	}
	else return;
}

int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	int t;
	cin >> t;
	while (t--)
	{
		ans=0;temp=0;
		cin >> M >> n;
		memset(m,0,sizeof(m));
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=M;i++)
			for (int j=1;j<=n;j++)
			{
				cin >> m[i][j];
				if (m[i][j]==1) vis[i][j]=0;
				else vis[i][j]=1; 
			}
		for (int i=1;i<=M;i++)
			for (int j=1;j<=n;j++)
			{
				temp=0;
				dfs(i,j);
				ans=max(ans,temp);
			}
		cout << ans << endl;
	}
	return 0;
} 
