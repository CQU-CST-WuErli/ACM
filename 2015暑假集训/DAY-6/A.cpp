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
#include <functional>
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

int G[110][110];
int vis[110];
int topo[110];

int n,m;
int cnt;

bool dfs(int u){
	vis[u]=-1;
	for (int v=1;v<=n;v++) if (G[u][v]){
		if (vis[v]<0) return false;
		else if (!vis[v] && !dfs(v)) return false;		
	}
	vis[u]=1;topo[cnt--]=u;
	return true;
}

void toposort(){
	CLR(vis);
	cnt=n;
	for (int i=1;i<=n;i++){
		if (!vis[i]) dfs(i);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (cin >> n >> m && (n || m)){
		CLR(G);
		for (int i=0;i<m;i++){
			int u,v;
			cin >> u >> v;
			G[u][v]=1;
		}

		toposort();
		for (int i=1;i<=n;i++) {
			cout << topo[i];
			if (i!=n) cout << ' ';
			else cout << endl;
		}
	}
	return 0;
}


