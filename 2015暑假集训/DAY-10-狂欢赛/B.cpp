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
#include <sstream>
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
string  a[15]={"4","7","44","47","74","77","444","447","474","744","477","747","774","777"};
int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	while (cin >> s){
//		cout << s << endl;
		map<string,int> mp;
		for (int i=0;i<14;i++) mp[a[i]]=0;
		int ans=0;string ret;
		for (int i=0;i<s.size();i++){
			
			for (int j=i;j<s.size();j++){
				string tmp;
				for (int k=i;k<=j;k++){
					tmp+=s[k];
				}
//				cout << tmp << endl;
				if (mp.count(tmp)) mp[tmp]++;
			}
		}
		ans=0;
		for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
			if (it->second>ans){
				ans=it->second;
				ret=it->first;
			}	
		}
		if (!ans) cout << "-1\n";
		else cout << ret << endl;
	}
	return 0;
}


