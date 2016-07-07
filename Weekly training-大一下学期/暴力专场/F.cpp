//  Created by  CQUWEL			                       
//  Copyright (c) 2015年 Team 3. All rights reserved.  

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
int t;
int m,n;  // apple box
int d[15][15];          //i个箱子，j个苹果 
int main()
{
	cin >> t;
	while (t--)
	{ 
		scanf("%d%d",&m,&n);
		for (int i=0;i<=n;i++)
			for (int j=0;j<=m;j++)
				d[i][j]=1;
		for (int i=2;i<=n;i++)
			for (int j=2;j<=m;j++)
			{
				if (i>j) d[i][j]=d[j][j];
				else if(i<=j) 
					d[i][j]=d[i-1][j]+d[i][j-i];
			}
		cout << d[n][m]<< endl;
	}
	return 0;
}

