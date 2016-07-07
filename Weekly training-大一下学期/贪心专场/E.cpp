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
int n;
long long k;
long long att[1010],def[1010];
bool vis[1010];
int main()
{
	while (scanf("%d%lld",&n,&k)!=EOF)
	{
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=n;i++)
			cin >> att[i];
		for (int i=1;i<=n;i++)
			cin >> def[i];
		sort(att+1,att+1+n);
		sort(def+1,def+1+n);
		bool ans=true;
		for (int i=1;i<=n;i++)
		{
			bool flag=false;
			for (int j=1;j<=n;j++)
			{
				if (!vis[j] && att[i]+def[j]>=k)
				{
					flag=true;
					vis[j]=true;
					break;
				}
			}
			if (flag) continue;
			else 
			{
				ans=false;
				break;
			}
		}
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
