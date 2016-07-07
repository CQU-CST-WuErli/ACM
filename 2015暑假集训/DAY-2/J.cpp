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

typedef pair<char,char> P;

P p[6];

bool cmp(P a,P b){
	return ((a.first==b.first && a.second==b.second) || (a.first==b.second && a.second==b.first));
}

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	string s;
	while (cin >> s){
		string t;
		for (int i=6;i<12;i++) {
			t+=s[i];
			s[i]='\0';
		}
	//	cout << s << endl;	cout << t << endl; 
		p[0]=P(s[0],s[5]);p[1]=P(s[2],s[3]);p[2]=P(s[1],s[4]);
		p[3]=P(t[0],t[5]);p[4]=P(t[2],t[3]);p[5]=P(t[1],t[4]);
	//	for (int i=0;i<6;i++) cout << p[i].first << p[i].second << endl;
		int vis[6]={0};
		bool ans=true;
		for (int i=0;i<3;i++){
			int flag=0;
			for (int j=3;j<6;j++){
				if (cmp(p[i],p[j]) && !vis[j]){
					vis[j]=1;flag=1;break;
				}
			}
			if (!flag){
		//		cout << i << endl;
				ans=false;
				break;
			}
		}
		if (ans) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
}


