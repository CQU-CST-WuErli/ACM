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

int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	cin >> n;
	getchar();
	for (int t=1;t<=n;t++)
	{
		string s;
		getline(cin,s);
//		cout << s;
		char ans1,ans2;
		int flag=2;
		if (s[0]==s[7]) ans1='=';
		else if (s[0]>s[7]) ans1='>';
		else ans1='<';
		ans2='=';
		if (s[1]==s[8])
		{
			for (int i=0;i<4;i++)
			{
				if (s[2+i]==s[9+i]) continue;
				else if (s[2+i]>s[9+i])
				{
					ans2='>';
					break;
				}
				else
				{
					ans2='<';
					break;
				}
			}
			printf("Case %d: %c %c\n",t,ans1,ans2);
		} 
		else
		{
			for (int i=0;i<3;i++)
			{
				if (s[2+i]==s[9+i]) continue;
				else if (s[2+i]>s[9+i])
				{
					ans2='>';
					break;
				}
				else
				{
					ans2='<';
					break;
				}
			}
			printf("Case %d: %c %c\n",t,ans1,ans2);
		}
	}
	return 0;
}

