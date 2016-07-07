//  Created by  CQUWEL			                       
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.  

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
int n,m;
long long c[110];
int p[110],vis[110];

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for (int i=1;i<=m;i++) p[i]=1;
		CLR(vis);
		for (int i=1;i<=n;i++)
			scanf("%lld",&c[i]);
		sort(c+1,c+1+n);
		long long sum=0;
		if (n<=m)
		{
			for (int i=1;i<=n;i++)
				sum+=c[i];
		}
		else
		{
			int count=0,flag=1;
			for (int i=n;i>=1;i--)
			{
				sum+=flag*c[i];
				count++;
				if (count==m)
				{
					count=0;
					flag++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
