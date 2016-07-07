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

int kase;
string s,t;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif	
	cin >> kase;
	getchar();
	for (int ca=1;ca<=kase;ca++){
		printf("Case %d: ",ca);
		cin >> s;
		cin >> t;
		int ls=s.size();
		int q_one=0,q_zero=0,one_zero=0,zero_one=0;
		int ans=0;
		for (int i=0;i<ls;i++){
			if (s[i]=='?' && t[i]=='0') q_zero++;
			else if (s[i]=='?' && t[i]=='1') q_one++;
			else if (s[i]=='1' && t[i]=='0') one_zero++;
			else if (s[i]=='0' && t[i]=='1') zero_one++;
		}
		while (one_zero && zero_one){
			ans++;
			one_zero--;
			zero_one--;
		}
		while (one_zero && q_one){
			one_zero--;q_one--;
			ans+=2;
		}
		if (one_zero) ans=-1;
		else ans+=q_one+q_zero+zero_one;
		cout << ans << endl;
	}	
rotate()
	return 0;
}


