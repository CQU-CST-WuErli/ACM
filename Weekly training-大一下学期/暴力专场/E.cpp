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
long long a[200005],d[200005];
long long n,k;
int t;
int main()
{
	cin >>t ;
	while (t--)
	{
		long long maxi=0;
		memset(d,0,sizeof(d));
		scanf("%lld%lld",&n,&k);
		for (long long i=1;i<=n;i++)
		{
			long long x;
			scanf("%lld",&x);
			if (x>k)  maxi=i;
			d[i]=d[i-1]+i-(i-maxi);
		}
		printf("%d\n",d[n]);
	}
	return 0;
}

