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
const int N=1e6+10;

map<string,int> mp;
vector<int> dpen[N];
vector<int> dpen2[N];
vector<int> inst;
vector<bool> in;
int status[N];
string name[N];
int cnt;

int get_id(string &s){
	if (!mp.count(s)) {
		mp[s]=cnt++;
		name[cnt-1]=s;
	}
	return mp[s];
}

void install(string& s,int level){
	int id=get_id(s);
	if (!status[id]){
		
		for (int i=0;i<dpen[id].size();i++){
			install(name[dpen[id][i]],0);
		}
		status[id]=level? 1:2;
		cout << "   Installing " << name[id] << endl;
		inst.push_back(id);
		in.push_back(true);
	}
}

bool is_need(string& s){
	int id=get_id(s);
	for (int i=0;i<dpen2[id].size();i++){
		if (status[dpen2[id][i]]) return true;
	} 
	return false;
}

void remove(string &s,int level){
	int id=get_id(s);
	if ((level || status[id]==2) && !is_need(s)){
		status[id]=0;
		for (int i=0;i<inst.size();i++) if (inst[i]==id) in[i]=false;
		cout << "   Removing " << name[id] << endl;
		for (int i=0;i<dpen[id].size();i++)
			remove(name[dpen[id][i]],0);
	}
} 
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;cnt=0;
	CLR(status);
	while (getline(cin,s)){
		cout << s << endl;
		if (s=="END") break;
		stringstream ss(s);
		string op;
		ss >> op;
		if (op=="DEPEND"){
			string item;
			ss >> item;
			string comb;
			while (ss >> comb){
				dpen[get_id(item)].push_back(get_id(comb));
				dpen2[get_id(comb)].push_back(get_id(item));
			}
		}
		else if (op=="INSTALL"){
			string item;
			ss >> item;
			int id=get_id(item);
			if (status[id]){
				cout << "   " << name[id] << " is already installed." << endl;
			}
			else install(item,1);
			
		}
		else if (op=="REMOVE"){
			string item;
			ss >> item;
			int id=get_id(item);
			if (is_need(item)) cout << "   " << name[id] << " is still needed." << endl;
			else if (!status[id]) {
				cout << "   " << name[id] << " is not installed." << endl;
			}			
			else remove(item,1);
		}
		else if (op=="LIST"){
			for (int i=0;i<in.size();i++){
				if (in[i]){
					int id=inst[i];
					cout << "   " << name[id] << endl;
				}
			}
		} 
	} 
	return 0;
}


