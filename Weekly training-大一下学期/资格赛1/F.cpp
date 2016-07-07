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

int t;
char c[11]={'0','p','q','r','u','v','w','x','y','z','0'};
struct s{
	long long a;
	char x;
}p[11];

int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	cin >> t;
	while(t--)
	{
		int flag=0,start=1;
		for (int i=1;i<=10;i++)
		{
			cin >> p[i].a;
			p[i].x=c[i];
		}
		for (int i=1;i<=9;i++)
		{
			if (!p[i].a) continue;
			if (p[i].a<0)
			{
				if(!flag) flag=1;
				if (p[i].a==-1)
					printf("-%c",p[i].x);
				else
					printf("%lld%c",p[i].a,p[i].x);
			}
			else if (p[i].a>0)
			{
				if (!flag) flag=1;
				else printf("+");
				if (p[i].a==1)
					printf("%c",p[i].x);
				else
					printf("%lld%c",p[i].a,p[i].x);
			}
		}
		if (p[10].a<0) printf("%lld\n",p[10].a);
		else if (p[10].a==0)
		{
			if (!flag) printf("0\n");
			else printf("\n");
		}
		else
			{
				if (flag) printf("+%d\n",p[10].a);
				else printf("%d\n",p[10].a);
			}
	}
	return 0;
}

