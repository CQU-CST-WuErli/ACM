///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by 吴尔立 			                       //
//  Copyright (c) 2015年 吴尔立. All rights reserved.  //
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
#define maxn 100000005
long long m,n; //n个人，m个队 
long long maxi,mini;

int main()
{
	while (scanf("%ld%ld",&n,&m)!=EOF)
	{
		if (m==1) maxi=n;
		else maxi=n-m+1;
		maxi=(maxi*(maxi-1))/2;
		if(n%m==0)
		{
			long long temp=n/m;
			mini=(temp*(temp-1))/2*m;
		}
		else
		{
			long long temp=n%m;  
        	long long k=n/m;  
        	mini=(k*(k-1))/2*(m-temp)+k*(k+1)/2*temp;
		}
		cout << mini << " "<< maxi <<endl;
	}
}
