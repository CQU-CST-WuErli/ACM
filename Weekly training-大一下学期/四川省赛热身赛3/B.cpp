//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
ll x,y,k;


int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%I64d%I64d%I64d",&x,&y,&k)==3){
		ll sum;
		ll tot = 0;
		if (k<=max(x,y)){
			printf("0\n");
			continue;
		}
		else{
			if (x<=0 && y<=0){
				printf("-1\n");
				continue;
			}
			else if (x+y<min(x,y)){
				printf("-1\n");
				continue;
			}
			else{
				while (k>max(x,y)){
					if (x>y){
						ll t;
						t=x;x=y;y=t;
					}
					if (x<0 && y>0){
						ll temp=(-x/y)+((-x)%y==0?0:1);;
						x+=temp*y;
						tot+=temp;
					}
					else {
						x+=y;
						tot++;
					}
				}
			}
		}
		printf("%I64d\n",tot);
	}
	return 0;
}


