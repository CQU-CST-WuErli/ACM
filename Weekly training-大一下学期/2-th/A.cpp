///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by Îâ¶ûÁ¢ 			                       //
//  Copyright (c) 2015Äê Îâ¶ûÁ¢. All rights reserved.  //
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
const int maxn=105;
int n; 
int box[maxn][maxn],h[maxn];

int main()
{
	CLR(box);
	/*while (scanf("%d",&n)!=EOF)
	{
		int maxh=0;
		cir(i,1,n)
		{
			int =H;
			scanf("%d",&H);
			h[i]=H;
			maxh=maxh>h?maxh:H;
			cir(j,1,h)
				box[i][j]=1;
		}
		CIR(i,maxh,1)
		{
			int tail=n;
			cir(j,1,n)
			{
				if (box[i][j])
					
			}
		}
	}*/
	while (scanf("%d",&n)!=EOF)
	{
		cir(i,0,n-1)	scanf("%d",&h[i]);
		sort(h,h+n);
		cir(i,0,n-1)    printf("%d ",h[i]);
	}
	return 0;
}
