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

const int maxn=6000;
int N;
long long a[maxn],t[maxn];
long long  d[maxn];

int main()
{
	while (cin >> N)
	{
		CLR(d);
		for (int i=1;i<=N;i++)
		{
			cin >> a[i];
			t[i]=a[i];
		}
		sort(t+1,t+N+1);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			{
				d[j]+=abs(a[i]-t[j]);
				if (j>1)
					d[j]=min(d[j],d[j-1]);	
			}
		cout << d[N] << endl;
	}
	return 0;
}
