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
int n;
int h[100100]; 

int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (cin >> n){
		for (int i=1;i<=n;i++)
			scanf("%d",h+i);
		h[0]=0;
		int ans=0;
		int temp=h[1];
		ans+=temp+1;
		for (int i=2;i<=n;i++){
			if (temp<=h[i]){
				ans+=h[i]-temp+2;
				temp=h[i];
			}
			else{
				ans+=temp-h[i]+2;
				temp=h[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}


