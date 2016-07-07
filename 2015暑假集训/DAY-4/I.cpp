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

map<string,int> arrl;
map<string,int> arrv;
	
int get_num(string s){
	int sum=0;
	for (int i=0;s[i];i++){
		sum=sum*10+s[i]-'0';
	}
	return sum;
}

int get_arrv(string s){
	int flag=0;
	for (int i=0;s[i];i++) if (isplpha(s[i])){
		flag=1;
		break;
	}
	if (!flag) return get_num(s);
	else {
		string tmp,fi,se;
		int be=s.find('['),ed=s.find(']');
		for (int i=be+1;i<ed;i++) tmp+=s[i];
		if (arrv.count(tmp)){
			return arrv[tmp];
		}
		else {
			int temp=get_arrv(tmp);
			
		}
	}
}
int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	string s;
	int end=1;
	while (getline(cin,s)){
		if (s[0]=='.') {	
			if (end==1){
				end=0;
				arrl.clear();
				arrv.clear();
				continue;
			}
			else break;
			
		} 
		end=1;
		int cnt;
		if (s.find('=')==s.npos){
			int cnt;
			string tmp1,tmp2;
			for (int i=0;s[i];i++) {
				if (s[i]=='['){
					cnt=i;break;
				}
				else {
					tmp1+=s[i];
				}
			}
			for (int i=cnt+1;s[i];i++){
				if (s[i]==']') break;
				else {
					tmp2+=s[i];
				}
			}
			arrl[tmp1]=get_num(tmp2);
		}
		else {
			string lv,rv;
			int cnt=s.find('=');
			for (int i=0;i<cnt;i++) lv+=s[i];
			for (int i=cnt+1;s[i];i++) rv+=s[i];
		//	cout << lv << endl;
		//	cout << rv << endl;
				
		}
	}
	return 0;
}


