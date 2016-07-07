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
const int maxn = 205;
int main()
{
	int w, h;
	string str1[maxn];
	while (cin >> w >> h)
	{
		for (int i = 0; i < h; ++i)
			cin >> str1[i]; 
		int l = h/2;
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j <= 1; ++j)
			{
				for (int k = 0; k < h; ++k)
					for (int l = 1; l <=2;++l)
					cout << str1[k][i];
				cout << endl; 
			}
		}
	}
	return 0;
}

