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
string ans1,ans2,s,e;

map <char,int> answer;
bool isexit(char s)
{
	return (answer.find(s)!=answer.end());
}
bool AC,PE,WA;
int main()
{
	cin >> n;
	getchar();
	for (int t=1;t<=n;t++)
	{
		AC=true;
		PE=false;WA=false;
		cin>> s;
		getchar();
//		cout << s;
		if (s=="START")
		{
			getline(cin,ans1);
			getline(cin,e);
			while (e!="END")
			{
				if (e=="")
					ans1+="\n";
				else 
					ans1+=e; 
				getline(cin,e);
			}
		}
		int l1=ans1.size();
		cin >> s;
		getchar();
		if (s=="START")
		{
			getline(cin,ans2);
			getline(cin,e); 
			while(e!="END")
			{
				if (e=="")
					ans2+="\n";
				else
					ans2+=e;
				getline(cin,e);
			}
		}
//		cout << ans1 << "|" <<endl;
//		cout << ans2 << "||" << endl;
		int l2=ans2.size();
		if (l1>l2)
		{
			string temp;
			temp=ans1;
			ans1=ans2;
			ans2=temp;
		}
		l1=ans1.size();
		l2=ans2.size();
		int flag=0;
		for (int i=0;i<l2;i++)
		{
			if (ans1[flag]==ans2[i])
				flag++;
			else
			{
				AC=false;
				if (ans2[i] ==' '|| ans2[i]=='\t' || ans2[i]=='\n')
					{
						if (ans1[i] ==' '|| ans1[i]=='\t' || ans1[i]=='\n')
							{
								flag++;
								PE=true;
							}
						else 
							PE=true;
					}
				else
				{
					WA=true;
//					cout << flag << endl;
				}
			}
		}
//		cout << AC << " " <<WA << " "<< PE <<endl;
		if (flag!=l1) AC=false;
		if (AC) cout << "Accepted\n";
		else if (WA) cout << "Wrong Answer\n";
		else if (PE) cout << "Presentation Error\n";
	}	
	return 0;
}

