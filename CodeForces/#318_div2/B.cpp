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

int n,m;
int deg[4100];
vector<int> g[4100];
int vis[4100][4100];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		for (int i=0;i<=n;i++) g[i].clear();
		CLR(vis);
		for (int i=1;i<=m;i++){
			int a,b;
			cin >> a >> b;
			vis[a][b]=vis[b][a]=1;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans=INF;
		for (int i=1;i<=n;i++) {
			if (g[i].size()<2) continue;
			for (int j=0;j<g[i].size();j++){
				for (int k=j+1;k<g[i].size();k++){
					int u=g[i][j],v=g[i][k];
					if (vis[u][v]){
						ans=min(ans,(int)g[i].size()+(int)g[u].size()+(int)g[v].size()-6);
					}
				}
			}
		}
		if (ans>=INF) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}

