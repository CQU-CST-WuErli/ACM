//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
int a,b,c,d;
 

int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (cin >> a >> b >> c >> d){
		double p1=1.0*a/b;
		double p2=1.0*c/d;
		double ans=p1/(1-(1-p1)*(1-p2));
		printf("%.12lf\n",ans); 
	}
	return 0;
}


