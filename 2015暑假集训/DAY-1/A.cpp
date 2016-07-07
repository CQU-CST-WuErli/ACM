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
#define BUG() printf("In here\n")
#define seevalue(x) printf("x=%d\n",x)
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;
string st[2]={"``","''"};
char tt='"';

int main(){
//	freopen ("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	string s;
	int flag=0;
	while (getline(cin,s)){
		int i;
		string t;
		for (i=0;s[i];i++){
			if (s[i]=='"'){
				t+=st[flag];
				flag=1-flag;
				
			}
			else t+=s[i];
		}
		cout << t << endl;
	}

	return 0;
}

