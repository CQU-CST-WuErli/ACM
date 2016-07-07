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

int dir[4][2]={1,0,0,1,-1,0,0,-1};
char mp[310][310];
int n,m;
typedef pair<int,int> P;
int vis[310][310];
int d[310][310];
P st,ed;

int spfa(){
	CLR(vis);
	MEM(d,INF_INT);	
	queue<P> q;
	d[st.first][st.second]=0;
	vis[st.first][st.second]=1;
	q.push(st);
	while (!q.empty()){
		P x=q.front();q.pop();
		vis[x.first][x.second]=0;
		
		for (int i=0;i<4;i++){
			int tx=x.first+dir[i][0],ty=x.second+dir[i][1];
			if (tx<1 || ty<1 || tx>m || ty>n) continue;
			if (mp[tx][ty]=='S' || mp[tx][ty]=='R') continue;
			if (d[tx][ty]>d[x.first][x.second]+(mp[tx][ty]=='B'?2:1)){
				d[tx][ty]=d[x.first][x.second]+(mp[tx][ty]=='B'?2:1);
				if (!vis[tx][ty]){
					vis[tx][ty]=1;
					q.push(P(tx,ty));
				}
			}
		}
	}
	return d[ed.first][ed.second];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> m >> n && (n || m)){
		getchar();
		st,ed;
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				cin >> mp[i][j];
				if (mp[i][j]=='Y') st.first=i,st.second=j;
				if (mp[i][j]=='T') ed.first=i,ed.second=j;
			}
		}
		int ans=spfa();
		if (ans>=INF_INT) cout << "-1\n";
		else cout << ans << endl;
	}
	return 0;
}

