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

string s;

int stoi(string &s,int index){
	int sum=0;
	for (int i=0;s[i];i++){
		int temp;
		if (isalpha(s[i])) temp=s[i]-'A'+10;
		else temp=s[i]-'0';
		sum=sum*index+temp;
	}
	return sum;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s){
		string hour,sec;
		int i;
		for (i=0;s[i]!=':';i++) hour+=s[i]; i++;
		for (;s[i];i++) sec+=s[i];
//		cout << hour << " " << sec << endl;
		int index=2;
		for (i=0;s[i];i++) {
			if (s[i]==':') continue;
			if (isalpha(s[i])) index=max(index,s[i]-'A'+11);
			else index=max(index,s[i]-'0'+1);
		}
//		look(index);
		vector<int> ans;
		for (i=index;i<=60;i++){
			int a=stoi(hour,i);
			int b=stoi(sec,i);
//			cout << a << " " << b << endl;
			if (a>=0 && a<24 && b>=0 && b<60){
				ans.push_back(i);
//				look(i);
			}
		} 
		if (!ans.size()){
			cout << "0\n";
			continue;
		}
		else if (ans.size()==61-index) {
			cout << "-1\n";
			continue;
		}
		else {
			for (i=0;i<ans.size();i++) {
				cout << ans[i];
				if (i<ans.size()-1) cout << " ";
				else cout << endl;
			}
		}
	}
	return 0;
}


