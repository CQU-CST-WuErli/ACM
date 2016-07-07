//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;SI(T_T);
	getchar();
	while (T_T--){
		string nw,od;
		map<string,string> mp1,mp2;
		getline(cin,od);getline(cin,nw);
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
		flag=1;
		vector<string> q1,q2,q3;
		for (map<string,string>::iterator it=mp2.begin();it!=mp2.end();it++){
			string key=it->first;string value=it->second;
			if (!mp1.count(key)) {
				flag=0;
				q1.push_back(key);
			}
			else {
				if (mp1[key]!=value) {
					flag=0;
					q3.push_back(key);
				}
			}
		}
		for (map<string,string>::iterator it=mp1.begin();it!=mp1.end();it++){
			string key=it->first;string value=it->second;
			if (!mp2.count(key)){
				flag=0;
				q2.push_back(key);
			}
		}
		if (flag) printf("No changes\n");
		else {
			if (q1.size()){
				printf("+");
				for (int i=0;i<q1.size();i++) {
					cout << q1[i];
					if (i<q1.size()-1) cout << ',';
				}
				cout << endl;
			}
			if (q2.size()){
				printf("-");
				for (int i=0;i<q2.size();i++) {
					cout << q2[i];
					if (i<q2.size()-1) cout << ',';
				}
				cout << endl;
			}
			if (q3.size()){
				printf("*");
				for (int i=0;i<q3.size();i++) {
					cout << q3[i];
					if (i<q3.size()-1) cout << ',';
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
