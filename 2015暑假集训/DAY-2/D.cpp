//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

bool judge(string test){
	for (int i=0;test[i];i++){
		if (test[i]!='0' || test[i]!='1') return 1
	}
	return 0;
}
int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	string be;
	getline(be);
	string s,t;
	while (getline(cin,s)){
		if (judge(s)){
			map<string,string> mp;
			int len=1;
			for (int i=0;be[i];i++){
				string tmp;
				for (int i=0;i<pow(2,len-1)-1;i++){
					
				}
			}
			be=s;
			continue;
		}
		else t+=s;
		
	}
	return 0;
}


