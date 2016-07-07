//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.

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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;

long long a,b;

int main()
{
	while (~scanf("%I64d%I64d",&a,&b)){
		long long ans=0;
		for (long long i=1;;i++){
			ll temp=i*i;
			ll r=b/temp;
			if (r<i) break;
			ll l=a/temp+(a%temp==0?0:1);
			l=max(l,i);
//			if (temp*r<a || temp*l>b) continue;
			ans+=r-l+1;
		} 
		printf("%I64d\n",ans); 
	}
	return 0;
}


