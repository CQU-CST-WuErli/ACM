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

string tt="AEHIJLMOSTUVWXYZ12358";
string ss="A3HILJMO2TUVWXY51SEZ8";

char find(char c){
	int cnt;
	for (int i=0;tt[i];i++){
		if (tt[i]==c){
			cnt=i;
			break;
		}
	}
	return ss[cnt];
}

int main(){
//	freopen ("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	string s;
	while (cin >> s){
//		cout << s << endl;
		int len=s.size();
		int mid=len/2;
		bool mir=true,pal=true;
		for (int i=0;i<=mid;i++){
			if (s[i]==s[len-1-i]){
				if (pal==true) pal=true;
			}
			else pal=false;
			if (s[i]==find(s[len-1-i])){
				if (mir==true) mir=true;
			}
			else mir=false;
			if (mir==false && pal==false) break;
		} 
		if (pal==false && mir==false) cout << s << " -- is not a palindrome.\n";
		else if (pal==true && mir==false) cout << s << " -- is a regular palindrome.\n";
		else if (pal==false && mir==true) cout << s << " -- is a mirrored string.\n";
		else if (pal==true && mir==true)  cout << s << " -- is a mirrored palindrome.\n";
		printf("\n");
	}
	return 0;
}

