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
//  freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	getchar();
	while (t--){
		string s;
		map<ll,int> mp;
		cin >> s;
		int dep=0;
		string tmp;
		int i;
		int ans=0;
		int cnt=0;
		for (i=0;s[i];){
			if (s[i]=='[') dep++,i++;
			else if (s[i]==']') dep--,i++;
			else if (s[i]==',') {
				i++;continue;
			}
			else {
				ll num=0;
				while (isdigit(s[i])){
					num=num*10+s[i]-'0';
					i++;
				}
//				cout << "dep=" << dep  << " " ;
//				cout << num << endl;
				if (num){
					num*=(1<<dep);
					if (!mp.count(num)) {
						mp[num]=1;
						cnt++;
					}
					else {
						mp[num]++;
						cnt++;
					}
				}
				ans=max(mp[num],ans);
			}
		}
		cout << cnt-ans << endl; 
	} 
	return 0;
}


