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

string s;
int vis[200050];
int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
while (cin >> s){
	string t;
	memset(vis,0,sizeof(vis));
	ll cnt=0;
	t+=s[0];
	cnt++;
	for (int i=1;s[i];i++){
		if ((cnt>=2 && s[i]==t[cnt-1] && t[cnt-1]==t[cnt-2]) || 
			(cnt>=3 && s[i]==t[cnt-1] && t[cnt-2]==t[cnt-3]) ) continue;
		else {
			t+=s[i];
			cnt++;
		}
//		cout << t << endl;
	}
	cout << t << endl;
}
	return 0;
}


