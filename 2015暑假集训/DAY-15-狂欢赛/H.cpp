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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
vector<int> g[110];
int vis[110];
int counter;

void dfs(int s){
	vis[s]=1;
	for (int i=0;i<g[s].size();i++){
		int v=g[s][i];
		if (!vis[v]) dfs(v);
	}
}

bool DFS(int s){

}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		for (int i=0;i<m;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=1;
		CLR(vis);
		dfs(1);
		for (int i=1;i<=n;i++) if (!vis[i]) ans=0;
//		cout << ans << " 11" << endl;
		if (ans){
			if (n!=m) ans=0;
		}
		if (ans) cout << "FHTAGN!\n";
		else cout << "NO\n";
	}
	return 0;
}


