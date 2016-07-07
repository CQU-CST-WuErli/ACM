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

string s1="`1234567890-=";
string s2="QWERTYUIOP[]\\";
string s3="ASDFGHJKL;'";
string s4="ZXCVBNM,./";

char find(char c){
	for (int i=1;s1[i];i++){
		if (s1[i]==c) return s1[i-1];
	}
	for (int i=1;s2[i];i++){
		if (s2[i]==c) return s2[i-1];
	}
	for (int i=1;s3[i];i++){
		if (s3[i]==c) return s3[i-1];
	}
	for (int i=1;s4[i];i++){
		if (s4[i]==c) return s4[i-1];
	}
}

int main(){
	freopen ("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	string s;
	while (getline(cin, s)){
		for (int i=0;s[i];i++){
			if (s[i]!=' '){
				s[i]=find(s[i]);
			}
		}
		cout << s << endl;
	}

	return 0;
}

