///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by  Team 3 			                       //
//  Copyright (c) 2015Äê Team 3. All rights reserved.  //
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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
int t;
int a[4];
int main()
{
	cin >> t;
	while (t--)
	{
		for (int i=1;i<=3;i++)
			cin >> a[i];
		sort(a+1,a+4);
//		for (int i=1;i<=3;i++) cout << a[i] << " ";
		int ans=0;
		if (a[1]*5==a[2]*4)
		{
			if (a[2]*6==a[3]*5)
				ans=1;
		}
		else if (a[1]*12==a[2]*10)
		{
			if (a[2]*15==a[3]*12)
				ans=2;
		}
		if (ans==1) cout << "major\n";
		else if (ans==2) cout << "minor\n";
		else cout << "noise\n";
	}
	return 0;
}

