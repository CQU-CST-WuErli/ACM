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

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	
	set<string> st;
	string s;
	while (getline(cin,s)){
		string t;
	//	cout << s << endl;
		for (int i=0;s[i];i++){
			if (isalpha(s[i])){
				if (s[i]>='A' && s[i] <='Z') s[i]='a'+s[i]-'A';
				t+=s[i];
			}
			else {
				if (t.length()) {
					st.insert(t);
					t.clear();
				}
			}
		}
		if (t.length()) {
			st.insert(t);
			t.clear();
		}
		
	}
	for (set<string>::iterator it=st.begin();it!=st.end();it++){
		cout <<*it << endl;
	}
	st.clear();
	return 0;
}


