///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by Îâ¶ûÁ¢ 			                       //
//  Copyright (c) 2015Äê Îâ¶ûÁ¢. All rights reserved.  //
/////////////////////////////////////////////////////////
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
#define ll long long;
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;

#define maxn 105
#define inf 20

int d[maxn][maxn],m[maxn][maxn];
int n;
void init()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			d[i][j]=inf;	
}

void floyd()
{
	cir (i,1,n) d[i][i]=0;
	cir(k,1,n)
		cir(i,1,n)
			cir(j,1,n)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	int source,maxlen,maxinf=inf;
	cir(i,1,n)
	{
		maxlen=0;
		cir(j,1,n)
		{
			if (i!=j && d[i][j]>maxlen)
				maxlen=d[i][j];
		}
		if (maxinf>maxlen)
		{
			maxinf=maxlen;
			source=i;
		}
	}
	cout << source << " " <<maxinf << endl; 
}

int main()
{
	while (scanf("%d",&n)!=EOF&&n)
	{
		init();
		cir (i,1,n)
		{
			int pair;
			cin >> pair;
			cir(j,1,pair)
			{
				int v,t;
				cin >> v >> t;
				d[i][v]=t;
			} 
		}
		floyd();
	}
	return 0;
}
