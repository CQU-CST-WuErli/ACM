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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int get_num(string &s){
	int sum=0;
	for (int i=0;s[i];i++) sum=sum*10+s[i]-'0';
	return sum;
}

string get_string (int n){
	string t;
	while(n){
		t+=n%10+'0';
		n/=10;
	}
	return t;
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	string t;
	while (cin >> s){
		cin >> t;
		string tmp1,tmp2;
		int ans=get_num(s)+get_num(t);
//		look(ans);
		string sum=get_string(ans);

		for (int i=0;s[i];i++) if (s[i]!='0') tmp1+=s[i];
		for (int i=0;t[i];i++) if (t[i]!='0') tmp2+=t[i];
		int tsum=get_num(tmp1)+get_num(tmp2);
		string temp;
		for (int i=0;sum[i];i++) if (sum[i]!='0') temp+=sum[i];
		if (get_string(tsum)==temp) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}


