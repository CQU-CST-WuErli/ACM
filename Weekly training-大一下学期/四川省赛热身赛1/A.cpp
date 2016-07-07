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


int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	int x,y;
	for (int i=1;i<=5;i++)
		for (int j=1;j<=5;j++){
			int a;
			cin >> a;
			if (a==1) {
				x=i;y=j;
			}
		} 
	int ans=abs(x-3)+abs(y-3);
	cout << ans << endl; 
	return 0;
}


