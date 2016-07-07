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

string s;

typedef pair<string,string> P;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	set<P> sp;
	set<P> desk;
	vector<P> book;
	vector<bool> in;
	while (getline(cin,s)){
		if (s=="END") break;
		int flag=1,ok=0;;
		string tmp1,tmp2;
		int i;
		for (i=0;s[i];i++){
			char c=s[i];
			if (c=='"') {
				flag=1-flag;
				continue;
			}
			if (flag) { 
				flag=0;
				i+=3;
				ok=1;
			}
			if (ok) tmp2+=c;
			else {
				tmp1+=c;
			}
			if (i==s.size()-1){
				P temp;
				temp.first=tmp2;
				temp.second=tmp1;
				sp.insert(temp);
				book.push_back(temp);
				in.push_back(true);
			}
		}
	}
//	for (set<P>::iterator it=sp.begin();it!=sp.end();it++){
//		cout << it->first << "||" << it->second << endl;
//	}
	while (getline(cin,s)){
		if (s=="END") break;
		string t;
		int i;
		for (i=0;s[i];i++){
			if (s[i]==' ') break;
			else t+=s[i]; 
		}
//		cout << t << endl;
		string name;
		for (int j=i+1;s[j];j++){
			char c=s[j];
			if (c!='"') name+=c;
		}
//		cout << name << endl;
		if (t[0]=='B'){
			P cnt;
			for (int i=0;i<book.size();i++){
				if (book[i].second==name  && in[i]) {
					cnt=book[i];
					in[i]=false;
					break;
				}
			}
			for (set<P>::iterator it=sp.begin();it!=sp.end();it++){
				if (it->second==name) {
					sp.erase(it);break;
				}
			}
		}
		else if(t[0]=='R'){
			P cnt;
			for (int i=0;i<book.size();i++){
				if (book[i].second==name) {
					cnt=book[i];
					break;
				}
			}
			desk.insert(cnt);
		}
		else if(t[0]=='S'){
			while (desk.size()){
				set<P>::iterator it=desk.begin();
				desk.erase(desk.begin());
				P cnt=*it;
				P temp;
				set<P>::iterator tmp=sp.end();
				for (set<P>::iterator iter=sp.begin();iter!=sp.end();iter++){
					if (iter->first<cnt.first ){
						tmp=iter;
					}
				}
				sp.insert(cnt);
				if (tmp==sp.end()){
					cout << "Put " << '"' << cnt.second << '"' << " first" << endl;
				}
				else {
					temp=*tmp;
					cout << "Put " << '"' << cnt.second <<'"' <<  " after " << '"' <<  temp.second << '"' << endl;
				}
			}
			printf("END\n");
		}
	}
	return 0;
}


