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

int n,s,t;
vector<int> g[110];
int cnt[110];

int vis[110];
int d[110];

int spfa(){
	queue<int> q;
	CLR(vis);
	MEM(d,INF_INT);
	q.push(s);
	vis[s]=1;
	d[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();vis[x]=0;
		for (int i=0;i<g[x].size();i++){
			int v=g[x][i];
//			if (v==x) continue;
			int tmp=(i==0?0:1);
			if (d[v]>d[x]+tmp){
				d[v]=d[x]+tmp;
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return d[t];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> s >> t){
		for (int i=0;i<=n;i++) g[i].clear();
		CLR(cnt);
		for (int i=1;i<=n;i++){
			int k;SI(k);
			while (k--){
				int v;
				SI(v);
				g[i].push_back(v);
//				g[v].push_back(i);
			}
		}
		int ans=spfa();
		if (ans>=INF_INT) cout << "-1\n";
		else cout << ans << endl;
	}
	return 0;
}

