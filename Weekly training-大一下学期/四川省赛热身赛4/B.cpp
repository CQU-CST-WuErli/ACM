
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
int n,k;
int h[200000];

int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	cin >> n >> k;
	int index=1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (i==1) h[i]=x;
		else {
			h[i]=h[i-1]+x;
		} 
	}
	int sum=h[k];
	for (int i=k+1;i<=n;i++){
		if (h[i]-h[i-k]<sum){
			sum=h[i]-h[i-k];
			index=i-k+1;
		}
	}
	printf("%d\n",index);
	return 0;
}


