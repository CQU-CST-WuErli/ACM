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

struct Edge{
	int u,v;
	double dis;
	bool operator < (const Edge& rhs) const {
		return dis<rhs.dis;
	}
};
vector<Edge> es;
int n;
double x[110],y[110];

int par[110],rnk[110];

void init() {
	rep(i,1,n) par[i]=i,rnk[i]=0;
}

int find(int x) {
	return par[x]=par[x]==x?x:find(par[x]);
}

bool same(int x,int y) {
	return find(x)==find(y);
}

void unite(int x,int y) {
	x=find(x);y=find(y);
	if (x==y) return ;
	if (rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
	return;
}

double kruskal() {
	init();
	sort(es.begin(),es.end());
	double ret=0.00;
	rep(i,0,es.size()-1) {
		Edge& e=es[i];
		if (!same(e.u,e.v)) {
			unite(e.u,e.v);
			ret+=e.dis;
		}
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		rep(i,1,n) cin >> x[i] >> y[i];
		es.clear();
		rep(i,1,n) rep(j,i+1,n) {
			double dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			dis=sqrt(dis);
			es.push_back(Edge{i,j,dis});
		}
		double ans=kruskal();
		printf("%.2f\n",ans);
	}
	return 0;
}

