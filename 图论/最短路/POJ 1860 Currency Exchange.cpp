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

const int N=110;
int n,m,s;
double v;
struct Edge{
	int v;
	double r,c;
}; 
vector<Edge> g[N];

int vis[N];
int cnt[N];
double d[N];

bool spfa(){
	CLR(vis);CLR(cnt);
	CLR(d);
	queue<int> q;
	q.push(s);
	d[s]=v;
	vis[s]=1;
	cnt[s]++;
	int flag=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=0;i<g[x].size();i++){
			int v=g[x][i].v;
			if (v==x) continue;
			double r=g[x][i].r,c=g[x][i].c;
			if (d[v]<(d[x]-c)*r){
				d[v]=(d[x]-c)*r;
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
					cnt[v]++;
				}
				if (cnt[v]>n){
//					lookln(cnt[v]);
					flag=1;break;
				} 
			}
		}
		if (flag) break;
	}
	if (flag) return true;
	else return false;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m >> s >> v){
		for (int i=1;i<=m;i++){
			int u,v;
			SII(u,v);
//			cout << u << ' ' << v << ' ';
			double r,c;
			scanf("%lf%lf",&r,&c);
//			cout << r << ' ' << c << ' '; 
			g[u].push_back(Edge{v,r,c});
			scanf("%lf%lf",&r,&c);
//			cout << r << ' ' << c << endl;
			g[v].push_back(Edge{u,r,c});
		}
		if (spfa()) cout << "YES\n";
		else cout << "NO\n"; 
	}
	return 0;
}

