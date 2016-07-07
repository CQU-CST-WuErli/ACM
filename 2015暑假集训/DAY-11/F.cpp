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
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << "x=" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

vector<int> g[22];
int n;
int vis[25];
int pre[25];
int cnt=0;

void dfs(int u){
//	cout << "ss" << endl;
	if (u==n ){
		cnt++;
		deque<int> dq;
		for (int i=u;;i=pre[i]){
//			cout << "ss" << endl; 
			dq.push_front(i);
			if (i==1) break;
		}
		while (!dq.empty()){
			int x=dq.front();dq.pop_front();
			cout << x;
			if (dq.size()) cout << " ";
			else cout << "\n";
		}
		return ;
	}
	vis[u]=1;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (!vis[v] ) {
			pre[v]=u;
			dfs(v);
			vis[v]=0;
		}
	}
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n){
		int u,v;
		for (int i=0;i<=20;i++) g[i].clear();
		while (cin >> u >> v && (u || v)){
//			cout << u << v << endl; 
			g[u].push_back(v);
			g[v].push_back(u);
		}
		CLR(vis);
		cnt=0;
		for (int i=0;i<=20;i++) sort(g[i].begin(),g[i].end());
		cout << "CASE " << kase++ << ":\n";
		if (g[n].size()) dfs(1);
		cout << "There are " << cnt << " routes from the firestation to streetcorner " << n << ".\n";
	}
	return 0;
}


