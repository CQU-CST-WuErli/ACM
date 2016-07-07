//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.

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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;

string s,tt;
int ans;
int next[10]={0};
string p="acdream";
int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (cin >> tt){
		s+=tt;
	} 
//	cout << s;= 
	int l=s.length();
	for (int i=0;s[i];i++) if (s[i]>='A' && s[i]<='Z') s[i]+=32; 
	next[0]=-1;int i=0,j=0,ans=0;
	while (i<l && j<7){
		if (s[i]=='.' || s[i]=='?' || s[i]=='!'){
			j=0;i++;
			cout << ans << endl;
			ans=0;
			continue;
		}
		if (j==-1 || s[i]==p[j]) i++,j++;
		else j=next[j];
		if (j==6){
			ans++;
			j=next[j];
		}
	}
	return 0;
}


