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
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=60;

int n,m;
struct Edge{
	int v;
	double w;
};
vector<Edge> g[N];
int mp[N][N];

double mid;
int start;
int vis[N];
double dis[N];
int counter[N];

bool spfa() {
	queue<int> q;
	for (int i=1;i<=n;i++) {
		q.push(i);
		counter[i]=1;
		vis[i]=1;
		dis[i]=0.00;
	}
	while (!q.empty()) {
		int x=q.front();q.pop();
		if (counter[x]>n) return true;
		vis[x]=0;
		for (int i=0;i<g[x].size();i++) {
			int v=g[x][i].v;
			double w=g[x][i].w-mid;
			if (dis[v]>dis[x]+w) {
				dis[v]=dis[x]+w;
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
					counter[v]++;
				}
			}
		}
	}
	return false;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		cin >> n >> m;
		for (int i=1;i<=n;i++) g[i].clear();
		double sum=0.00;
		CLR(mp);
		start=0;
		for (int i=1;i<=m;i++) {
			int u,v;
			double w;
			scanf("%d%d%lf",&u,&v,&w);
			if (!start) start=u;
			g[u].push_back(Edge{v,w});
			sum+=w;
			mp[u][v]=1;
		}
		int flag=0;
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++) 
				for (int j=1;j<=n;j++) {
					mp[i][j]=mp[i][j] | (mp[i][k] & mp[k][j]);
				}
		for (int i=1;i<=n;i++) if (mp[i][i]) {
			flag=1;
			break;
		}
		if (!flag) {
			cout << "Case #" << kase << ": ";
			cout << "No cycle found.\n";
			continue;
		}
		double l=0.00,r=sum;
		while (eps<r-l) {
			mid=(l+r)/2.0;
			if (spfa()) r=mid;
			else l=mid;
//			lookln(mid);
		}
		cout << "Case #" << kase << ": ";
		printf("%.2lf\n",l);
	}
	return 0;
}

