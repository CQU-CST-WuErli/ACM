//  Created by  CQUWEL			                       
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.  

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

int m,n,k;
int tube[110];
int vis[110];
int main()
{
	cin >> m;
	while (m--)
	{
		cin >> n >> k;
		CLR(vis);
//		int sum=0;
//		int tot=(1+n)*n/2;
		bool ans=true;
		for (int i=1;i<=n;i++)
		{
			cin >> tube[i];
			if (tube[i]>n)
				ans=false;
			vis[tube[i]]++;
		}
		for (int i=1;i<=n;i++)
		{
			if (vis[i]==0)
			{
				for (int j=1;j<i;j++)
				{
					if (vis[j]>1)
					{
						if ((i-j)%k==0)
						{
							vis[j]--;
							vis[i]++;
							break;
						}
					}
				}
			}
		}
		for (int i=1;i<=n;i++)
			if (!vis[i]) {
				ans=false;
				break;
			}
		if (ans) cout << "Jerry\n";
		else cout << "Tom\n"; 
	}
	return 0;
}

