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
long long a[10];
char c[11]={'0','p','q','r','u','v','w','x','y','z','0'};
int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	cin >> t;
	while (t--)
	{
		int flag=1,start;
		for (int i=0;i<10;i++)
			cin >> a[i];
		for (int i=0;i<10;i++)
		{
			if (a[i]==0)
				flag++;
			else
			{
				start=i;
				break;
			}
		}
		for (int i=start;i<10;i++)
		{
			if (i==start)	
			{
				cout << a[i] << c[flag++];
				continue;
			}
			if (a[i]==0)
			{
				flag++;
				continue;
			}
			else
			{
				if (a[i]>0)
				{
					if (i==0)
					{	cout << a[i] ;
						 if (flag<=9)
						 	cout << c[flag++];
					}
					else
					{ 
						cout << '+' << a[i] ;
						if (flag<=9)
							cout << c[flag++];
					}
				}
				else
				{
					cout << a[i] ;
					if (flag<=9)
						cout << c[flag++];
				}
			}
		}
		cout << endl;
	}
	return 0;
}

