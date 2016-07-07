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

const int N=450;
int dir[4][2]={0,1,1,0,0,-1,-1,0};

int mp[44][11];
int mx[N],my[N];
int dx[N],dy[N];
int used[N];
int dist;
int link[N][N];
int w,h;
int tot;

bool bfs() {
	queue<int> q;
	OFF(dx);OFF(dy);
	dist=INF_INT;
	for (int i=1;i<=tot;i++) {
		if (mx[i]==-1) {
			q.push(i);
			dx[i]=0;
		}
	}
	while (!q.empty()) {
		int u=q.front();q.pop();
		if (dx[u]>dist) break;
		for (int v=1;v<=tot;v++) {
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
	for (int v=1;v<=tot;v++) {
		if (link[u][v] && !used[v] && dy[v]==dx[u]+1) {
			used[v]=1;
//			if (my[v]!=-1 && dy[v]==dist) continue;
			if (my[v]==-1 || find(my[v])) {
				my[v]=u;mx[u]=v;
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
		for (int i=1;i<=tot;i++) {
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
	cin >> T_T;
	while (T_T--) {
		cin >> h >> w;
		getchar();
		tot=0;
		for (int i=1;i<=h;i++) {
			for (int j=1;j<=w;j++) {
				char c;cin >> c;
				if (c=='o') mp[i][j]=0;
				else if (c=='*') mp[i][j]=++tot;
			}
		}
		// build graph
		CLR(link); 
		for (int i=1;i<=h;i++) {
			for (int j=1;j<=w;j++) {
				if (mp[i][j]) {
					for (int k=0;k<4;k++) {
						int tx=i+dir[k][0],ty=j+dir[k][1];
						if (tx<=0 || ty<=0 || tx>h || ty>w) continue;
						if (mp[tx][ty]) {
							link[mp[i][j]][mp[tx][ty]]=1;
						}
					}
				}
			}
		}
		// HK()
		int ans=HK();
//		lookln(ans);
		cout << tot-ans/2 << endl;
	}
	return 0;
}

