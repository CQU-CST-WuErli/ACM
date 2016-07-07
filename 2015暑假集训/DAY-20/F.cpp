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
vector<ll> v;
set<ll> st;

void init(){
	int cnt=0;
	st.insert(1);
	cnt++;
	for (int i=2;i<=6000;i++){
		ll tmp=*st.begin();
		v.push_back(tmp);
		st.erase(st.begin());
		cnt++;
		st.insert(tmp*2);
		st.insert(tmp*3);
		st.insert(tmp*5);
		st.insert(tmp*7);
	}
} 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	while (cin >> n && n ){
		cout << "The " << n;
		if (n%10==1 && n%100!=11 )cout << "st ";
		else if (n%10==2 && n%100!=12) cout << "nd ";
		else if (n%10==3 && n%100!=13) cout << "rd ";
		else cout << "th ";
		cout << "humble number is "; 
		cout << v[n-1] << '.' << endl;
	}
	return 0;
}


