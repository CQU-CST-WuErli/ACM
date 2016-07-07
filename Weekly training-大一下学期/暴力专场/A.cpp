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

int main()
{
	long long ans,n;
	while (cin >> n)
	{
		if (n==1)
			ans=1;
		else if (n==2)
			ans=2;
		else if (n==3)
			ans=6;
		else if (n%2==1)
			ans=n*(n-1)*(n-2);
		else 
		{
			ans=(n-1)*(n-2)*(n-3);
			ans=max(ans,n*(n-1)*(n-3));
		}
		cout << ans << endl; 
	}	
	return 0;
}

