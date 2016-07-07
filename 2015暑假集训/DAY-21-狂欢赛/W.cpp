//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

string s,t;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s){
		string suf;
		for (int i=1;i<=2001;i++) suf+='#';
		cin >> t;
		int ans=0x3f3f3f;
		int ls=s.size();
		int lt=t.size();
		if (ls>=lt){
			string temp=suf;
			temp+=s; 
			s=temp;
			s+=suf;
			int i;
			for (i=2001-lt+1;i<2001+ls;i++){
				int tmp=0;
				for (int j=0;j<lt;j++) {
					if (s[i+j]!=t[j]) tmp++;
				}
				ans=min(ans,tmp);
			}
		}
		else {
			string temp=suf;
			temp+=t;
			t=temp;
			t+=suf;
			int i;
			for (i=2001-ls+1;i<2001+lt;i++){
				int tmp=0;
				for (int j=0;j<ls;j++){
					if (t[i+j]!=s[j]) tmp++;
				}
				ans=min(ans,tmp+lt-ls);
			}
		}
		cout << ans << endl;
	}
	return 0;
}


