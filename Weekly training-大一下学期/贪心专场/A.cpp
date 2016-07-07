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
long long maxe[5];

multiset<int>::iterator iter;
int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF)
	{
		bool ans=true;
		int sum=0;
		cin >> maxe[1] >> maxe[2]>>maxe[3]>>maxe[4];
		multiset <int> s;
		for (int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			s.insert(x);
			sum+=x;
		}
		for (int i=1;i<=4;i++)
		{
			while (maxe[i])
			{
				if (s.size()==0)
				{
					ans=false;break;
				}
				iter=s.lower_bound(maxe[i]);
				if (iter==s.end())
				{
					iter--;
					maxe[i]-=(*iter);
				}
				else
					maxe[i]=0;
				sum-=(*iter);
				s.erase(iter);
			}
			if (!ans) break;	
		}
		if (ans) cout << "YES" <<" "<< sum << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

