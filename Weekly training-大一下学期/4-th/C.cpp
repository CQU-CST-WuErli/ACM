///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by  Team 3 			                       //
//  Copyright (c) 2015Äê Team 3. All rights reserved.  //
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
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 210
typedef struct Point
{
	double x,y;
};
Point p[maxn];
double d[maxn][maxn];
double dis(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int n;
void floyd()
{
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			{
				d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
			}
}
int main()
{
	int cases=1;
	while (scanf("%d",&n)!=EOF && n!=0)
	{
		CLR(d);
		for (int i=1;i<=n;++i)
			cin >> p[i].x >> p[i].y;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			{
				d[i][j]=dis(p[i],p[j]);
			} 
		floyd();
		printf("Scenario #%d\n",cases++);
		printf("Frog Distance = %.3f\n\n",d[1][2]);
	}
	return 0;
}

