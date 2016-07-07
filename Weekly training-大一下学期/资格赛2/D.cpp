//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <string.h>
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

int t;
char s1[15],s[15];
int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	cin >> t;
	getchar();
	while (t--){
		gets(s1);
		int l1=strlen(s1);
		int temp=1,x=0,cnt=0;
		for (int i=l1-1;i>=0;i--){
			if (s1[i]=='.') {
				cnt=i; continue;
			}
			x+=(s1[i]-'0')*temp;
			temp*=10;
		}
		for (int i=0;i<cnt;i++) temp/=10;
//		cout << x<< endl;
//		cout << temp << endl;
		int mm=min(x,temp);
		int k=sqrt(mm);
		for (int i=2;i<=mm;i++){
			while (x%i==0 && temp%i==0){
				x/=i;
				temp/=i;
			}
		}

		cout << x << "/" << temp << endl;
	}
	return 0;
}


