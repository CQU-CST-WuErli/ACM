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

const int N=35;

int mp[N][N];
int path[N][N];   // 0-> above  1-> left
int n,m;
typedef pair<int,int> P;
int d[N][N],vis[N][N];
int dir[2][2]={1,0,0,1};

void bfs() {
	CLR(vis);
	MEM(d,INF_INT);
	d[1][1]=mp[1][1];
	vis[1][1]=1;
	queue<P> q;
	q.push(P(1,1));
	while (!q.empty()) {
		P x=q.front();q.pop();
		vis[x.first][x.second]=0;
		for (int i=0;i<2;i++) {
			int tx=x.first+dir[i][0],ty=x.second+dir[i][1];
			if (tx>n || ty>m) continue;
			if (d[tx][ty]>d[x.first][x.second]+mp[tx][ty]) {
				d[tx][ty]=d[x.first][x.second]+mp[tx][ty];
				path[tx][ty]=i;
				if (!vis[tx][ty]) {
					q.push(P(tx,ty));
					vis[tx][ty]=1;
				}
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		SII(n,m);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				scanf("%d",&mp[i][j]);
			}
		}
		OFF(path);
		bfs();
		int ans=0;
		int i=n,j=m;
		while (path[i][j]!=-1) {
			ans+=mp[i][j]*mp[i][j];
//			lookln(mp[i][j]);
			if (path[i][j]==0) i--;
			else if (path[i][j]==1) j--;
		}
		ans+=mp[1][1]*mp[1][1];
//		lookln(ans);
		ans*=(n+m-1);
		ans-=d[n][m]*d[n][m];
		printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}

