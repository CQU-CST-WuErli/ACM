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
#define maxn 100005
long long n,m;
string s;
long long l[maxn],r[maxn];
long long d[maxn];

int main()
{
	getline(cin,s);
	n=s.length();
	scanf("%ld",&m);
	for (long long i=1;i<=m;i++)
	{
		scanf("%ld%ld",&l[i],&r[i]);
	}
	//	for (long long i=0;i<n;i++) cout << s[i] << endl;
	//	cout << m << endl; 
	CLR(d);
	for (long long i=1;i<n;i++)
	{
		if (s[i]==s[i-1]) d[i]=d[i-1]+1;
		else d[i]=d[i-1];
	}
	for (long long i=1;i<=m;i++)
		cout << d[r[i]-1]-d[l[i]-1] << endl;
	return 0;
}

