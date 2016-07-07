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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m,q;
struct Edge{
	int u,v,dis;
	bool operator < (const Edge& rhs) const {
		return dis<rhs.dis;
	}
}es[100010];

struct Query{
	int id,dis;
	bool operator < (const Query& rhs) const {
		return dis<rhs.dis;
	}
}Q[5500];
int now;
int par[20010],rnk[20010],num[20010];

void init(){
	for (int i=1;i<=n;i++){
		par[i]=i;
		rnk[i]=0;
		num[i]=1;
	} 
}

int find(int x){
	if (x==par[x]) return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y){
	x=find(x);y=find(y);
	if (x==y) return;
	now+=num[x]*num[y];
	if (rnk[x]<rnk[y]) {
		par[x]=y;
		num[y]+=num[x];
		num[x]=0;
	}
	else {
		par[y]=x;
		num[x]+=num[y];num[y]=0;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	scanf("%d",&_);
	while (_--){
		scanf("%d%d%d",&n,&m,&q);
		for (int i=1;i<=m;i++) {
			scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].dis);
		}
		sort(es+1,es+1+m);
		for (int i=1;i<=q;i++) {
			scanf("%d",&Q[i].dis);
			Q[i].id=i;			
		}
		sort(Q+1,Q+1+q);
		init();
		int ans[5010];
		now=0;
		for (int i=1,j=1;i<=q;i++){
			int cur=Q[i].dis;
			while (j<=m){
				Edge &e=es[j];
				if (e.dis<=cur){
					unite(e.u,e.v);
				}else break;
				j++;
			}		
			ans[Q[i].id]=now*2;	
		}
		for (int i=1;i<=q;i++) cout << ans[i] << endl;
	}
	return 0;
}

