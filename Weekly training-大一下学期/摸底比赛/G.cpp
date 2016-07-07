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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
int t;
double cost[25];
int main()
{
	int h,m,s;
	cin >> t;
	for (int i=0;i<12;i++)
		cost[i]=cost[12+i]=i*30/(11.0/120.0);
	while (t--)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		double now=m*60.0+s;
		if (now>=cost[h])
			printf("%.6lf\n",3600-now+cost[h+1]);
		else 
			printf("%.6lf\n",cost[h]-now); 
	}
	return 0;
}
