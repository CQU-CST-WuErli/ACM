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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Line {
	int a,b,c,d;
	int flag;	// 0 vertical   1 
	void set(int _a,int _b,int _c,int _d) {
		a=_a;b=_b;c=_c;d=_d;
		if (a>c) swap(a,c);
		if (b>d) swap(b,d);
		if (a==c) flag=0;
		else flag=1;
	}
}line[1100];

int xl,yl,xr,yr;
int n,q;
vector<int> g[1100];
int vis[1100];

bool check(Line& x,Line& y) {
	if (x.flag==y.flag) return false;
	if ((x.b==y.b || x.b==y.d) && y.a>=x.a && y.a<=x.c) return true;
	if ((x.a==y.a || x.a==y.c) && y.b>=x.b && y.b<=x.d) return true;
	return false;
}

bool in(Line& x,int l,int r,int up,int down) {
	if (x.flag==0) {
		if (x.b<=up && x.d>=up && x.a>=l && x.a<=r) return true;
		if (x.d>=down && x.b<=down && x.a>=l && x.a<=r) return true;
	}
	if (x.flag==1) {
		if (x.a<=l && x.c>=l && x.b>=down && x.b<=up) return true;
		if (x.a<=r && x.c>=r && x.b>=down && x.b<=up) return true;
	}
	return false;
}

int dfs(int u) {
	vis[u]=1;
	int cnt=1;
	for (int i=0;i<g[u].size();++i) {
		int v=g[u][i];
		if (vis[v]) continue;
		cnt+=dfs(v);
	}
	return cnt;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> xl >> yl >> xr >> yr) {
		SII(n,q);
		rep(i,0,n) g[i].clear();
		rep(i,1,n){
			int a,b,c,d;
			SII(a,b);
			SII(c,d);
			line[i].set(a,b,c,d);
		}
		rep(i,1,n) {
			rep(j,1,n) {
				if (check(line[i],line[j])) {
					g[i].push_back(j);
//					cout << i << ' ' << j << endl;
				}
			} 
		}
		while (q--) {
			int a,b,c,d;
			SII(a,b);SII(c,d);
			int l=min(a,c),r=max(a,c);
			int down=min(b,d),up=max(b,d);
			vector<int> v;
			rep(i,1,n) {
				if (in(line[i],l,r,up,down)) v.push_back(i);
			}
			int ans=0;
			CLR(vis);
			for (int i=0;i<v.size();i++) if (!vis[v[i]]){
				ans+=dfs(v[i]);
			}
			cout << n-ans+1 << endl;
		}
	}
	return 0;
}
