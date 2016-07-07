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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct P{
	string name;
	int prio;
	P(){prio=0;}
}a[110];

map<string,int> mp;
int cnt;

int get_id(string &s){
	if (!mp.count(s)) {
		mp[s]=cnt++;
		a[cnt-1].prio=0;
		a[cnt-1].name=s;
	}
	return mp[s];
}

int get_op(string &s){
	if (s[0]=='p') return 1;
	else if (s[0]=='c') return 2;
	else if (s[0]=='l') return 3;
}

bool cmp(const P& a, const P& b){
	if (a.prio==b.prio) return a.name<b.name;
	else return a.prio>b.prio;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string me;
	cin >> me;
	int n;
	cin >> n;
	getchar();
	cnt=0;
	string s;
	for (int i=1;i<=n;i++){
		getline(cin,s);
		stringstream ss(s);
		string str[5];int tcnt=0;
		string tmp;
		while (ss >> tmp) str[tcnt++]=tmp;
		int op=get_op(str[1]);  
		if (op==1 || op==2){
			int id_1=get_id(str[0]);
			int j=0;string tmp;
			while (isalpha(str[3][j])) tmp+=str[3][j++];
			int id_2=get_id(tmp);
			if (str[0]==me) a[id_2].prio+=(op==1?15:10);
			else if (tmp==me) a[id_1].prio+=(op==1?15:10); 
		}
		else {
			int id_1=get_id(str[0]);
			int j=0;string tmp;
			while (isalpha(str[2][j])) tmp+=str[2][j++];
			int id_2=get_id(tmp);
			if (str[0]==me) a[id_2].prio+=5;
			else if (tmp==me) a[id_1].prio+=5;
		} 	
	}
	sort(a,a+cnt,cmp);
	for (int i=0;i<cnt;i++) if (a[i].name!=me) cout << a[i].name << endl;
	return 0;
}


