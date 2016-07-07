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
void BUG(int _testnumber){
	printf("I am in line %d\n",_testnumber);
}
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	string s,t;
	while (cin >> s >> t){
	//	cout << s << "     "<< t << endl;
		int ans=false;
		int cnt=-1;
		int i=0;
		int ls=s.size();
		while (i<ls){
			char c=s[i];
			for (int j=0;t[j];j++){
				if (s[i]==t[j]){
					i++;
				}
			}
			if (i==ls) {
				ans=true;
				break;
			}
			else {
				ans=false;
				break;
			}
		}
		if (ans) printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}


