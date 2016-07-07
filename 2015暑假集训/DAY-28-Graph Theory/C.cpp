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
#define BUG cout << "I am here" << endl
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

struct Node{
	int x,y;
};
vector<Node> city;

struct Edge{
	int u,v;
	int dis;
};
vector<Edge> es;

vector<int> sub[10];
int c[10];
int par[1100],rnk[1100];
int n,q;

int dist(const Node &a,const Node &b){
	int d=0;
	d+=(a.x-b.x)*(a.x-b.x);
	d+=(a.y-b.y)*(a.y-b.y);
	return d;	
}

bool cmp(const Edge &a,const Edge &b){
	return a.dis<b.dis;	
}

void read(){
	SII(n,q);
//	look(n);lookln(q);
	for (int i=0;i<q;i++) {
		int x,cost,id;
		SII(x,cost);
//		look(x);lookln(cost);
		c[i]=cost;
		for (int j=1;j<=x;j++) {
			SI(id);
			sub[i].push_back(id);
		}
	}
	for (int i=1;i<=n;i++) {
		int x,y;
		SII(x,y);
//		look(x);lookln(y);
		city.push_back(Node{x,y});
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			int d=dist(city[i],city[j]);
			es.push_back(Edge{i+1,j+1,d});
		}
	}
//	for (auto &i:es) cout << i.u <<" " <<  i.v << " " << i.dis << endl; 
	sort(ALL(es),cmp);
}

void init(int n){
	for (int i=0;i<=n;i++) {
		par[i]=i;
		rnk[i]=0;
	} 
}

int find(int x){
	if (par[x]==x) return x;
	else return par[x]=find(par[x]);
}

bool same(int x,int y){
	return find(x)==find(y);
}

void unite(int x,int y){
	x=find(x);y=find(y);
	if (x==y) return ;
	if (rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if (rnk[x]==y) rnk[x]++;
	}
	return ;
}

int kruskal(int cnt,const vector<Edge> &e,vector<Edge> &used){
	if (cnt==1) return 0;
	int len=e.size();
	int res=0;
	used.clear();
	for (int i=0;i<len;i++){
		if (!same(e[i].u,e[i].v)){
			unite(e[i].u,e[i].v);
			res+=e[i].dis;
			used.push_back(e[i]);
			if (--cnt==1) break;
		}
	}
	return res;
}

void solve(){
	init(n+1);
	vector<Edge> used;
	int ans=kruskal(n,es,used);
//	for (auto &i:used) cout << i.u << i.v << i.dis << endl;
//	lookln(ans);
	for (int st=0;st<(1<<q);st++){
		init(n+1);
		int cost=0;
		int cnt=n;
		for (int i=0;i<q;i++) if (st&(1<<i)){
			cost+=c[i];
			for (int j=1;j<sub[i].size();j++){
				if (!same(sub[i][j],sub[i][0])){
					unite(sub[i][j],sub[i][0]);
					cnt--;
				}
			}
		} 
//		lookln(cost);
//		lookln(cnt);
		vector<Edge> tmp;
		ans=min(ans,cost+kruskal(cnt,used,tmp));
//		lookln(temp);
	}
	printf("%d\n",ans);
}

void clear(){
	city.clear();es.clear();
	for (int i=0;i<10;i++) sub[i].clear();
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T;
	SI(T);
	int kase=1;
	while (T--){
		For_UVa;	
		read();
		solve();
		clear();
		kase++;
	}
	return 0;
}


