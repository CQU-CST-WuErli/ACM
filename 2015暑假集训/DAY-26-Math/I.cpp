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
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

string s;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s){
		int win=0,lose=0;
		double p1,p2;
		int ls=s.size();
		for (int i=0;i<ls-1;i++){
			if (s[i]=='0' && s[i+1]=='0') win++;
			if (s[i]=='0' && s[i+1]=='1') lose++;
		}
		if (s[ls-1]=='0' && s[0]=='0') win++;
		if (s[ls-1]=='0' && s[0]=='1') lose++;
		p1=(double)win/(double)(win+lose)*1.00;
		int sum_zero=0;
		for (int i=0;s[i];i++){
			if (s[i]=='0') sum_zero++; 
		}
		p2=(double)sum_zero/(double)ls*1.00;
		if (p1-p2<=eps && p1-p2>=-eps) cout << "EQUAL\n";
		else if (p1>p2) cout << "SHOOT\n";
		else cout << "ROTATE\n";
	}
	return 0;
}


