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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;

string s;
string ans="angry goddess";
int next[100050];

void getnext(string &s){
	int i=0,j=-1;
	next[0]=-1;
	while (i<s.size()){
		if (j==-1 || s[i]==s[j]){
			i++,j++;
			next[i]=j;
		}
		else j=next[j];
	}
}

int kmp(string &s,string &t){           //ÔÚsÖÐËÑË÷p 
	getnext(t);
	int i=0,j=0;
	int sl=s.length();
	int tl=t.length();
	while (i<sl && j<tl){
		if (j==-1 || s[i]==s[j]) i++,j++;
		else j=next[j];
	}
	if (j==tl)
		return 1;
	else return -1;	
}

int main()
{
	while (cin >> s){
//		getnext(s);
//		for (int i=0;s[i];i++) cout << next[i] << " ";
//		cout << endl;
	}
	return 0;
}


