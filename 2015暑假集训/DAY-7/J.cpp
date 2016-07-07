//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int v,e,t;

vector<int> g[1100];
int vis[1100];

int cnt;

void init(){
	for (int i=1;i<=v;i++) g[i].clear();
	CLR(vis);
}

void read(){
	for (int i=1;i<=e;i++){
		int U,V;
		scanf("%d%d",&U,&V);
		g[U].push_back(V);
		g[V].push_back(U);
	}
} 

void dfs(int u){
	if (vis[u]) return ;
	vis[u]=1;
	cnt+=(int) g[u].size() & 1;
	for (int i=0;i<g[u].size();i++) {
		dfs(g[u][i]);
	}
}

int solve(){
	int ret=0;
	for (int i=1;i<=v;i++){
		if (!vis[i] && g[i].size()){
			cnt=0;
			dfs(i);
			ret+=max(cnt,2); 
		}
	}
	return t*(max((ret-2)/2+e,e));
} 


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (scanf("%d%d%d",&v,&e,&t)==3 && (v || e || t)){
		init();
		read();
		cout << "Case " << kase++ << ": " << solve()<< endl;
		for (int i=0;i<=v;i++) g[i].clear();
	}
	return 0;
}


