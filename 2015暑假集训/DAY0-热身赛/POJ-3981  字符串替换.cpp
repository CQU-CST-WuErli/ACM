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
#define filetest freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin)
#define BUG(x) printf("In line x\n")
#define seevalue(x) printf("x=%d\n",x)
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;

string tt="you\0";
string kk="we";


int main(){
	
	string  s;
	while (getline(cin,s)){
//		cout << s << endl; 
		string t;
		int flag=0;
		string tmp;
		int i;
		for (i=0;s[i];i++){
			int cnt=0;
			if (s[i]==' '){
				t+=' ';
				continue;
			}
			if (s[i]=='y'){
				for (int j=0;tt[j];j++){
					if (tt[j]==s[i+j]) 
						cnt++;
				}
				if (cnt==3) {
					t+=kk;
					cnt=0;
					i+=2;
				}
				else t+=s[i];
			}
			else t+=s[i];
		}
		cout << t << endl;
	} 

	return 0;
}

