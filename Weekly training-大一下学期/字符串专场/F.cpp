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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
string s,tt;
int p[1010*3];
int nn;

string dif(string &x){
	if (x.length()<=1)
		return "";
	string res="";
    for(int i=1;i<x.length();++i)
        res+=abs(x[i]-x[i-1])+'a';
    return res;
}

void preprocess(string &x){
	s[0]='@';s[1]='#';nn=2;
	for (int i=0;x[i];i++){
		s[nn++]=x[i];
		s[nn++]='#';
//		cout << "s"<<endl;
	}
	s[nn]='\0'; 
}

int manacher(string &x){
	preprocess(x);
	int mxl=0,id=0;
	for (int i=1;i<nn;i++){
		if (mxl>i) p[i]=min(mxl-i,p[2*id-i]);
		else p[i]=1;
		while (s[i-p[i]]==s[i+p[i]]) p[i]++;
		if (mxl<p[i]+i) mxl=p[i]+i,id=i; 
	}
	int ret=0;
	for (int i=1;i<nn;i++) ret=max(ret,p[i]);
	return ret-1;
}
int main()
{
	while (getline(cin,tt)){
		int ans=0;
//		cout << dif(tt);
//		preprocess(tt);
//		for (int i=0;s[i];i++) cout << s[i];
		int l=tt.size();
		if (l==0){
			cout << "0\n";
			continue;
		}
		while (ans<tt.size()){
			ans=max(ans,manacher(tt));
//			cout << tt << "||" << ans <<endl; 
			tt=dif(tt);
			if (tt.size()<=ans) break;				
		}
		cout << ans << endl;
	}
	return 0;
}


