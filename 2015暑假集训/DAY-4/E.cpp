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


string s[120010];

map<string,ll> st;

int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	string t;
	int cnt=0;
	int kase=1;
	while (cin >> t){
		s[cnt++]=t;
		if (!st.count(t)) {

			st[t]=cnt;
		}
	}
//	sort(s,s+cnt);
	for (int i=0;i<cnt;i++){
		int tcnt=0;
		int flag=0;
		int ls=s[i].size(); 
		for (tcnt=1;tcnt<ls;tcnt++){
			string tmp1,tmp2;
			for (int j=0;j<tcnt;j++) tmp1+=s[i][j];
			if (st.count(tmp1)){
				for (int j=tcnt;j<ls;j++) tmp2+=s[i][j];
				if (st.count(tmp1) && st.count(tmp2)) {
					flag=1;
					break;
				}
			}
			
		}
		if (flag) cout << s[i] << endl; 
	} 
	st.clear();
	return 0;
}


