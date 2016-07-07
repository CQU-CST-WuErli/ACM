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
int n;
void reads(string &s)
{
	string t;
	while (getline(cin,t))
	{
		if (t=="START")  continue;
		else if (t=="END")  break;
		else if (t=="")
			s+="\n";
		else
			s+=t;
	}
}

bool isblank(char c)
{
	return (c==' ' || c=='\n' || c=='\t');
}
int main()
{
	cin >> n;
	getchar();
	while (n--) 
	{
		bool wa=false,pe=false,ac=true;
		int p1=0,p2=0;
		string ans1,ans2;
		reads(ans1);
		reads(ans2);
		int l1=ans1.size();
		int l2=ans2.size();
		while (p1<l1 && p2<l2)
		{
			if (isblank(ans1[p1])|| isblank(ans2[p2]))
			{
				if (ans1[p1]!=ans2[p2]) pe=true;
				while (isblank(ans1[p1])) ++p1;
				while (isblank(ans2[p2])) ++p2;
			}
			else
			{
				if (ans1[p1]!=ans2[p2])
				{
					wa=true;
					break;
				}
				else
				{
					++p1;++p2;
				}
			}
		}
		if (p1==l1 && p2<l2)
		{
			for (int i=p2;i<l2;++i)
			{
				if (!isblank(ans2[i]))
				{
					wa=true;
					break;
				}
			}
			if (!wa) pe=true;
		}
		else if (p1<l1 && p2==l2)
		{
			for (int i=p1;i<l1;++i)
			{
				if (!isblank(ans1[i]))
				{
					wa=true;
					break;
				}
			}
			if (!wa) pe=true;
		}
		if (wa) cout << "Wrong Answer" << endl;
		else if (pe) cout << "Presentation Error"<< endl;
		else if (ac) cout << "Accepted"<< endl;;
	}
	return 0;
}
