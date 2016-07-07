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

int n,m;
struct Edge{
	int u,v;
	int w;
	bool operator < (const Edge& rhs) const {
		return w<rhs.w;
	}
};
vector<Edge> es;
int mp[20][20];
int par[20],rnk[20];
int cost[20];

int find(int x) {
	return par[x]=par[x]==x?x:find(par[x]);
}

bool same(int x,int y) {
	return find(x)==find(y);
}

void unite(int x,int y) {
	x=find(x);y=find(y);
	if (x==y) return;
	if (rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
	return;
}

double kruskal(int sta) {
	es.clear();
	for (int i=0;i<=n;i++) par[i]=i,rnk[i]=0;
	int nsum=0;
	set<int> st;
	for (int i=0;i<n;i++) if ((sta>>i)&1) st.insert(i+1),nsum+=cost[i+1];
	rep(i,1,n) rep(j,i+1,n) {
		if (st.count(i) && st.count(j)) {
			es.push_back(Edge{i,j,mp[i][j]});
		}
	} 
	sort(es.begin(),es.end());
	int msum=0;
	for (int i=0;i<es.size();i++) {
		Edge &e=es[i];
		if (!same(e.u,e.v)) {
			msum+=e.w;
			unite(e.u,e.v);
		}
	}
//	lookln(nsum);
//	lookln(msum);
	return msum*1.0/nsum*1.0;
}
	
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2 && (n && m)) {
		es.clear();
		rep(i,1,n) SI(cost[i]);
		rep(i,1,n) rep(j,1,n) SI(mp[i][j]);
		double ans=INF_INT*1.0;
		int S;
		for (int sta=0;sta<1<<n;sta++) {
			int tmp=0;
			for (int i=0;i<n;i++) if ((sta>>i)&1) tmp++;
			if (tmp==m) {
				double tt=kruskal(sta);
				if (ans>tt) {
					ans=tt;
					S=sta;
				}
			}
		}
//		printf("ans=%.2f\n",ans);
		int cnt=0;
		vector<int> v;
		for (int i=0;i<n;i++) if ((S>>i)&1) v.push_back(i+1);
		sort(v.begin(),v.end());
		for (int i=0;i<v.size();i++) {
			cout << v[i];
			if (i<v.size()-1) cout << ' ';
			else cout << endl;
		}
	}
	return 0;
}

