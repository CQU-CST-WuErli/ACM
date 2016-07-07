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
#define ll long long;
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;
long long n,k;//video    server
long long ll_max(long long a,long long b)
{
	return a>b?a:b;
}
int main()
{
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		priority_queue<long long ,vector<long long>,greater<long long> > pq;
		for (long long i=1;i<=k;i++)
			pq.push(0);
		long long s,cost;
		long long ans;
		for ( long long i=1;i<=n;i++)
		{
			scanf("%lld%lld",&s,&cost);
			ans=pq.top();
			pq.pop();
			ans=ll_max(ans,s)+cost;
			printf("%lld\n",ans);
			pq.push(ans);
		}	
	}
	return 0;
}
 
