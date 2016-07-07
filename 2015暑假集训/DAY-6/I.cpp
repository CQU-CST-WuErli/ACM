//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int t;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	cin >> t;
	getchar();
	while (t--){
		string s;
		getline(cin,s);
//		cout << s << endl;
//		if (s.size()==0) {
//			printf("Yes\n");
//			continue;
//		}
		stack<char> sc;
		for (int i=0;s[i];i++){
			if (sc.empty()) sc.push(s[i]);
			else {
				char c=sc.top();
				if ((c=='(' && s[i]==')') || (c=='[' && s[i]==']') ) sc.pop();
				else sc.push(s[i]); 
			}
		}
//		cout << sc.size() << endl;
		if (sc.empty()) printf("Yes\n");
		else printf("No\n");
		while (sc.size()) sc.pop();
	}
	return 0;
}


