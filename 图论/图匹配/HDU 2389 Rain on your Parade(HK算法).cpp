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

const int N=3010;

int mx[N],my[N];
int dx[N],dy[N];
int t,m,n;
int link[N][N];
int used[N];
int dist;

struct P{
	double x,y;
};
P per[N],umb[N];
double speed[N];

double dis(P& a,P& b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));   
}

bool bfs() {
	queue<int> q;
	dist=INF_INT;
	OFF(dx);OFF(dy);
	for (int i=1;i<=m;i++) {
		if (mx[i]==-1) {
			q.push(i);
			dx[i]=0;
		}
	}
	while (!q.empty()) {
		int u=q.front();q.pop();
		if(dx[u]>dist) break;
		for (int v=1;v<=n;v++) {
			if (link[u][v] && dy[v]==-1) {
				dy[v]=dx[u]+1;
				if (my[v]==-1) dist=dy[v];
				else {
					dx[my[v]]=dy[v]+1;
					q.push(my[v]);
				}
			}
		} 
	}
	return dist!=INF_INT;
}

int find(int u) {
	for (int v=1;v<=n;v++) {
		if (link[u][v] && !used[v] && dy[v]==dx[u]+1) {
			used[v]=1;
//			if (my[v]!=-1 && dy[v]==dist) continue;
			if (my[v]==-1 || find(my[v])) {
				mx[u]=v;my[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

int HK() {
	int ret=0;
	OFF(mx);OFF(my);
	while (bfs()) {
		CLR(used);
		for (int i=1;i<=m;i++) {
			if (mx[i]==-1) ret+=find(i);
		}
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		scanf("%d%d",&t,&m);
		CLR(link);
		for (int i=1;i<=m;i++) {       // perple
			scanf("%lf%lf",&per[i].x,&per[i].y);
			scanf("%lf",&speed[i]);
		}
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {    // umbrella
			scanf("%lf%lf",&umb[i].x,&umb[i].y);
		}
		// build graph
		double limit=t*1.0;
		for (int i=1;i<=m;i++) {
			for (int j=1;j<=n;j++) {
				double d=dis(per[i],umb[j]);
				if (limit*speed[i]>=d) link[i][j]=1;
			}
		}
		// match process
		int ans=HK();
		printf("Scenario #%d:\n",kase);
		cout << ans << endl	<< endl;	
	} 
	return 0;
}
