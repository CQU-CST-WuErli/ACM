//
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
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;

char s[100010];
int m,l,r;
int d[100010];

int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	memset(d,0,sizeof(d));
	scanf("%s",s+1);
	d[1]=0;
	for (int i=2;s[i];i++){
		if (s[i]==s[i-1]) d[i]=d[i-1]+1;
		else d[i]=d[i-1];
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",d[r]-d[l]);
	}
	return 0;
}


