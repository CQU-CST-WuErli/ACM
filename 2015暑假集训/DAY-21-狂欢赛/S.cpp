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
const int N=1e5+10; 
int n,m;
int on[N];
map<int,int> mp;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		getchar();
		CLR(on);
		for (int i=1;i<=m;i++){
			char op;
			int id;
			scanf("%c%d",&op,&id);
			getchar();
//			cout << op << " " << id << endl;
			if (op=='+'){
				if (on[id]) cout << "Already on\n";
				else {
					if (id==1) {
						cout << "Success\n";
						on[id]=1;
						continue;
					}
					else {
						int tmp=id;
						vector<int> div;
						int flag=0;
						for (int i=2;i*i<=tmp;i++){
							while (tmp%i==0){
								div.push_back(i);
								if (mp[i]) {
									flag=mp[i];break;
								}
								tmp/=i;
							}
							if (flag) break;
						}
						if (flag) {
							cout << "Conflict with " << flag << endl;
							continue;
						}
						if (tmp>1){
							if (mp[tmp]) {
								cout << "Conflict with " << mp[tmp] << endl;
								continue;
							}
							div.push_back(tmp);
						}
						for (int i=0;i<div.size();i++) {
							mp[div[i]]=id;
//							cout << mp[div[i]] << " ";
						}
//						cout << endl;
						on[id]=1;
//						cout << id << endl;
						cout << "Success\n";
					}
				} 
			}
			else if (op=='-'){
				if (!on[id]) cout << "Already off\n";
				else {
					on[id]=0;
					cout << "Success\n";
					for (int i=2;i*i<=id;i++){
						while (id%i==0){
							mp[i]=0;
							id/=i;
						}
					}
					if (id>1) mp[id]=0;
				}
			}
//			for  (int i=1;i<=7;i++) cout << on[i] ;
//			cout << endl;
		}
	}
	return 0;
}


