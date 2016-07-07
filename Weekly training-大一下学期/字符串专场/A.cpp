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
#define maxn 100010
#define MOD 1000000007
string s;
int next[maxn];
long long  f[maxn];
long long ans;

void init()
{
	f[0]=1;f[1]=1;f[2]=1;
	for (long long i=3;i<=maxn;i++)
		f[i]=f[i-1]+f[i-2]; 
}

void getnext()
{
	int i,j;
	next[0]=-1;
	for (i=1,j=-1;s[i];i++){
		while (j!=-1 && s[i]!=s[j+1]) j=next[j];
		if (s[j+1]==s[i]) j++;
		next[i]=j;
		
	}
}

int main()
{
	init();
	while (getline(cin,s)){
//		long long l=s.size();
		ans=0;
		getnext();
		for (int i=0;s[i];i++)
			cout << next[i] << " " ;
		cout << endl;		
	}
	return 0;
}


