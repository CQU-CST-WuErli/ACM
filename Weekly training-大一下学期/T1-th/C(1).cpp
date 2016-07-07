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
void dels(string &s)
{
	char temp[6000];
	int l=s.size();
	int flag=0;
	for (int i=0;i<l;++i)
		if (s[i]!=' '&&s[i]!='\n'&&s[i]!='\t')
			temp[flag++]=s[i];
	s.clear();
	for (int i=0;i<flag;++i)
		s+=temp[i];
}

int cmp(string &s,string &t)
{
	int ls,lt;
	ls=s.size();
	lt=t.size();
	if (s==t) return 1;
	dels(s);
	dels(t);
	if (s==t) return 0;
	else return -1;
	
}
int main()
{
	string ans1,ans2;
	cin >> n;
//	getchar();
	cir(t,1,n)
	{
		reads(ans1);
		reads(ans2);
		int ans=cmp(ans1,ans2);
		if (ans==1) cout << "Accepted\n";
		else if (ans==0) cout << "Presentation Error\n";
		else if (ans==-1) cout << "Wrong Answer\n";
	}
	return 0;
}
