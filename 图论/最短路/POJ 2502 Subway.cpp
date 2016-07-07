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

struct P{
	double x,y;
	bool operator < (const P& rhs) const {
		if (x==rhs.x) return y<rhs.y;
		else return x<rhs.x;
	}
};

vector<P> sub[220];
map<P,int> mp;
int ID,cnt;
double g[220][220];

void get_id(P& a){
	if (!mp.count(a)) mp[a]=ID++;
}

void init(){
	for (int i=0;i<=200;++i) sub[i].clear();
	mp.clear();
	ID=1;cnt=0;
	CLR(g);
}

double dis(P a,P b){
	double ret=0.00;
	ret+=(a.x-b.x)*(a.x-b.x);
	ret+=(a.y-b.y)*(a.y-b.y);
	return sqrt(ret);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\r\Desktop\\out.txt","w",stdout);
#endif
	double sx,sy,tx,ty;
	while(cin >> sx >> sy >> tx >> ty){
		init();
		P s,t;
		s.x=sx,s.y=sy;t.x=tx,t.y=ty;
		double a,b;
		while (cin >> a >> b){
			if (a==-1 && b==-1) {
				cnt++;
				continue;
			}
			sub[cnt].push_back(P{a,b});
		}
		get_id(s);
		for (int i=0;i<cnt;i++){
			for (int j=0;j<sub[i].size();j++) {
				get_id(sub[i][j]);
//				cout << sub[i][j].x << ' ' << sub[i][j].y << endl;
			}
		}
		get_id(t);
//		lookln(ID);
//		cout << mp[t] << endl;
		for (int i=0;i<cnt;i++){
			for (int j=1;j<sub[i].size();j++){
				int u,v;
				u=mp[sub[i][j-1]];v=mp[sub[i][j]];
//				cout << u << ' ' << v << endl;
				g[u][v]=g[v][u]=dis(sub[i][j-1],sub[i][j])/40000.0*1.00;
//				cout << dis(sub[i][j-1],sub[i][j])/40.0*1.00 << endl;
			}
		}
		vector<P> ps;
		ps.push_back(s);
		for (int i=0;i<cnt;i++)
			for (int j=0;j<sub[i].size();j++) ps.push_back(sub[i][j]);
		ps.push_back(t);
		for (int i=0;i<ps.size();i++){
			int u=mp[ps[i]];
			for (int j=0;j<ps.size();j++){
				int v=mp[ps[j]];
				if (g[u][v]==0){
					g[u][v]=g[v][u]=dis(ps[i],ps[j])/10000.0*1.00;
				} 
			}
		}
//		for (int i=1;i<=mp[t];i++) {
//			for (int j=1;j<=mp[t];j++) cout << g[i][j] << ' ';
//			cout << endl;
//		}
		for (int k=1;k<=mp[t];k++){
			for (int i=1;i<=mp[t];i++){
				for (int j=1;j<=mp[t];j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		double ans=g[1][mp[t]];
		cout << (int)(ans+0.5) << endl;
	} 
	return 0;
}

