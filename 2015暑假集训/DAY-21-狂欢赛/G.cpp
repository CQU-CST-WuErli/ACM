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

int n;
struct P{
	int taxi,pizza,girl;
	string name;
	P(){
		taxi=0;pizza=0;girl=0;
	}
}per[110];

int get_kind(string &s){
	if (s[0]==s[1] && s[1]==s[3] && s[3]==s[4] && s[4]==s[6] && s[6]==s[7]) return 1;
	else if (s[0]>s[1] && s[1]>s[3] && s[3]>s[4] && s[4]>s[6] && s[6]>s[7]) return 2;
	else return 3;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif	
	while (cin >> n){
		int cnt=0;
		int max_taxi=0,max_pizza=0,max_girl=0;
		for (int i=1;i<=n;i++){
			int m;string s;
			cin >> m;getchar();
			cin >> per[i].name;
			for (int j=1;j<=m;j++){
				cin >> s;
				int flag=get_kind(s);
				if (flag==1) per[i].taxi++;
				else if (flag==2) per[i].pizza++;
				else if (flag==3) per[i].girl++;
			}
			if (per[i].taxi>max_taxi) max_taxi=per[i].taxi;
			if (per[i].pizza>max_pizza) max_pizza=per[i].pizza;
			if (per[i].girl>max_girl) max_girl=per[i].girl;
		}
//		for (int i=1;i<=n;i++) {
//			cout << per[i].name << endl;
//			cout << per[i].taxi << " " << per[i].pizza << " " << per[i].girl << endl;
//		}
//		cout << max_taxi << max_pizza << max_girl << endl; 
		vector<int> taxi,pizza,girl;
		for (int i=1;i<=n;i++){
			if (per[i].taxi==max_taxi) taxi.push_back(i);
			if (per[i].pizza==max_pizza) pizza.push_back(i);
			if (per[i].girl==max_girl) girl.push_back(i);
		}
		printf("If you want to call a taxi, you should call: ");
		for (int i=0;i<taxi.size();i++){
			int id=taxi[i];
			cout << per[id].name;
			if (i<taxi.size()-1)  cout << ", ";
			else cout << ".\n";
		}
		printf("If you want to order a pizza, you should call: ");
		for (int i=0;i<pizza.size();i++){
			int id=pizza[i];
			cout << per[id].name;
			if (i<pizza.size()-1)  cout << ", ";
			else cout << ".\n";
		}
		printf("If you want to go to a cafe with a wonderful girl, you should call: ");
		for (int i=0;i<girl.size();i++){
			int id=girl[i];
			cout << per[id].name;
			if (i<girl.size()-1)  cout << ", ";
			else cout << ".\n";
		}
	} 
	return 0;
}


