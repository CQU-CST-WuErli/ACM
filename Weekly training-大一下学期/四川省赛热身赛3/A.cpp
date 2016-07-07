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
const ll maxn=1000000+10;
char s[maxn];
char st[10]="heavy\0";
char ed[10]="metal\0";

int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	gets(s);
	ll tot=0;
	char c;
	bool f1=false,f2=false;
	int t1=0,t2=0;
	ll sum1=0,sum2=0;
	gets(s);
	for (ll i=0;s[i];i++){
		if (s[i]=='h'){
			t1=0;
			f1=true;
		}
		if (s[i]=='m'){
			t2=0;
			f2=true;
		}
		if (f1){
			if (s[i]==st[t1]){
				t1++;
			}
			else {
				t1=0;
				f1=false;
			}
			if (t1==5){
				t1=0;
				f1=false;
				sum1++;
			}
		}
		if (f2){
			if (s[i]==ed[t2]){
				t2++;
			}
			else {
				t2=0;
				f2=false;
			}
			if (t2==5){
				t2=0;
				f2=false;
				sum2++;
				tot+=sum1;
			}
		} 
	}
	printf("%I64d\n",tot);
	return 0;
}


