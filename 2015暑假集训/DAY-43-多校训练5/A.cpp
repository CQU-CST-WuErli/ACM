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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,k;
struct P{
	int v;
	int id;
	bool operator < (const P&rhs) const {
		return v>rhs.v;
	}
}; 
vector<P> s,p;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> k){
		s.clear();p.clear();
		for (int i=1;i<=n;i++) {
			int v,id;
			SII(v,id);
			if (id==1) s.push_back(P{v,i});
			else if (id==2) p.push_back(P{v,i});
		}
		sort(ALL(s));sort(ALL(p));
		double ans=0;
		vector<P> tmp;
		if (s.size()<k){
			for (int i=0;i<s.size();i++) ans+=(double)s[i].v;
			ans/=2;
			for (int i=0;i<p.size();i++) ans+=(double) p[i].v;
		}
		else {
			for (int i=0;i<k-1;i++) ans+=(double)s[i].v;
			ans/=2;		
			for (int i=k-1;i<s.size();i++) tmp.push_back(s[i]);
			for (int i=0;i<p.size();i++) tmp.push_back(p[i]);
			sort(ALL(tmp));
			ans+=((double)tmp[tmp.size()-1].v)/2;
			for (int i=0;i<tmp.size()-1;i++) ans+=(double) tmp[i].v;
		}
		printf("%.1f\n",ans);
		vector<int> tt[1100];
		if (s.size()<k){
			int i;
			for (i=0;i<s.size();i++) tt[i].push_back(s[i].id);
			int cnt=0;
			for (;i<k;i++) tt[i].push_back(p[cnt++].id);
			for (;cnt<p.size();cnt++) tt[k-1].push_back(p[cnt].id);
		}
		else {
			for (int i=0;i<k-1;i++) tt[i].push_back(s[i].id);
			for (int i=0;i<tmp.size();i++) tt[k-1].push_back(tmp[i].id);
		}
		for (int i=0;i<k;i++){
			cout << tt[i].size() << ' ';
			for (int j=0;j<tt[i].size();j++) cout << tt[i][j] << ' ';
			cout << endl;
		}
	}
	return 0;
}

