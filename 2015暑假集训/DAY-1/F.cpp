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

string s;

int main(){
	int n;
	cin >> n;
	getchar();
	for (int i=1;i<=n;i++){
		cin >> s;
		int cnt=0;
		string tmp=s;
		for (int i=1;s[i];i++){
			string t;
			for (int j=i;s[j];j++) t+=s[j];
			for (int j=0;j<i;j++)  t+=s[j];
			if (t<tmp) tmp=t;
		}
		cout << tmp << endl;
	}
	return 0;
}

