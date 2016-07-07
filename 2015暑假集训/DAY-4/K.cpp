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
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int T;


int main(){
#ifdef LOCAL
//
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	cin >> T;
	getchar();
	while (T--){
		string nw,od;
		map<string,string> mp1,mp2;
		getline(cin,od);getline(cin,nw);
	//	cout << nw << endl;
		int flag=0;
		string temp1,temp2;
		if (od!="{}"){
			for (int i=0;od[i];i++){
			char c=od[i];
			if (c=='{') continue;
			else if (c==':'){
				flag=1;
				continue;
			}
			else if (c==','){
				mp1[temp1]=temp2;
				temp1.clear();
				temp2.clear();
				flag=0;
				continue;
			}
			else if (c=='}'){
				mp1[temp1]=temp2;
				temp1.clear();
				temp2.clear();
				flag=0;
				break;
			}
			if (flag==0) temp1+=c;
			else temp2+=c;
		}
		}
		if (nw!="{}"){
			for (int i=0;nw[i];i++){
			char c=nw[i];
			if (c=='{') continue;
			else if (c==':') {
				flag=1;
				continue;
			}
			else if (c==','){
				mp2[temp1]=temp2;
				temp1.clear();
				temp2.clear();
				flag=0;
				continue;
			}
			else if (c=='}' && nw[i-1]!='{'){
				mp2[temp1]=temp2;
				temp1.clear();
				temp2.clear();
				flag=0;
				break;
			}
			if (flag==0) temp1+=c;
			else if (flag==1) temp2+=c;
		}
		}
		
//		for (map<string,string>::iterator it=mp1.begin();it!=mp1.end();it++)
//			cout << it->first << ":" << it->second << endl;
//		for (map<string,string>::iterator it=mp2.begin();it!=mp2.end();it++)
//			cout << it->first << ":" << it->second << endl;
		int ok=1;
		queue<string> q1,q2,q3;
		for (map<string,string>::iterator it=mp2.begin();it!=mp2.end();it++){
			string key=it->first;string value=it->second;
			if (!mp1.count(key)) {
				ok=0;
				q1.push(key);
			}
			else {
				if (mp1[key]!=value) {
					ok=0;
					q3.push(key);
				}
			}
		}
		for (map<string,string>::iterator it=mp1.begin();it!=mp1.end();it++){
			string key=it->first;string value=it->second;
			if (!mp2.count(key)){
				ok=0;
				q2.push(key);
			}
		}
		if (ok) printf("No changes\n");
		else {
			if (q1.size()){
				printf("+");
				while (q1.size()){
					string x=q1.front();q1.pop();
					cout << x;
					if (q1.size()!=0) cout << ",";
				}
				cout << endl;
			}
			if (q2.size()){
				printf("-");
				while (q2.size()){
					string x=q2.front();q2.pop();
					cout << x;
					if (q2.size()!=0) cout << ",";
				}
				cout << endl;
			}
			if (q3.size()){
				printf("*");
				while (q3.size()){
					string x=q3.front();q3.pop();
					cout << x;
					if (q3.size()!=0) cout << ",";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}


