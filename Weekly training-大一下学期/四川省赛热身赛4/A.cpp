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

char s[15];
ll n;
 
int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	gets(s);
//	int l=strlen(s);
	strrev(s);
//	puts(s);
	for (int i=0;s[i];i++){
		int num=s[i]-'0';
		switch(num){
			case 0: printf("O-|-OOOO\n"); break;
			case 1: printf("O-|O-OOO\n"); break;
			case 2: printf("O-|OO-OO\n"); break;
			case 3: printf("O-|OOO-O\n"); break;
			case 4: printf("O-|OOOO-\n"); break;
			case 5: printf("-O|-OOOO\n"); break;
			case 6: printf("-O|O-OOO\n"); break;
			case 7: printf("-O|OO-OO\n"); break;
			case 8: printf("-O|OOO-O\n"); break;
			case 9: printf("-O|OOOO-\n"); break;
		}
	}
	return 0;
}


