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
int T;
char s[110],t[110];

int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	cin >>T;
	getchar();
	while (T--){
		gets(s);
		int i;
		int flag=0;
		for (i=0;;i++){
			t[i]='A';
			if (strstr(s,t)==NULL) break;
		}
		puts(t);
		memset(t,'\0',sizeof(t));
	}
	return 0;
}


