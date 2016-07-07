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
#define ll long long;
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int ls=s.size();
		int lt=t.size();
		int flag1=0,flag2=ls-1;
		int p1,p2;
		for (int i=0;i<lt;i++)
		{
			p1=i;
			if (t[i]==s[flag1])
				flag1++;
			if (flag1==ls)
				break;
		}
		for (int i=lt-1;i>=0;i--)
		{
			p2=i;
			if (t[i]==s[flag2])
				flag2--;
			if (flag2<0)
				break;
		}
//		cout << ls << " "<< lt << endl; 
//		cout << flag1 << " " << flag2 << endl;
//		cout << p1 << " "<< p2 <<endl;
		int ans=p2-p1;
		if (ans<0) ans=0;
		cout << ans<< endl;
	}
	return 0;
}
// aba   baobababbah
