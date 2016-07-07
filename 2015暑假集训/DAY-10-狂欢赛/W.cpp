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
#include <sstream>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
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
const int N=1e5+10;

int pnt[N*3],head[N*3],nxt[N*3],vis[N*3];
vector<int> ring; 
int dis[N*3];

int n;
int cnt;
int start;

void init(){
	memset(head,-1,sizeof(head));
	memset(nxt,-1,sizeof(nxt));
	CLR(vis);
}

void addedge(int u,int v){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
}

bool dfs(int pre,int u){
	vis[u]=1;
	for (int i=head[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (v!=pre){ 
			if (vis[v]) start=v;             // the point we meet first during the recusion and let it be the start point
			if (vis[v] || dfs(u,v)){         // these points will not be the start point
				ring.push_back(v);
				if (u==start) return false;
				return true;
			}
		}
	}
	return false;
}

void bfs(){
	dfs(0,1);
	queue<int> q;
	CLR(vis);
	CLR(dis);
	for (int i=0;i<ring.size();i++) {
//		cout << ring[i] << " ";
		q.push(ring[i]);vis[ring[i]]=1;dis[ring[i]]=0;
	}
//	cout << endl;
	while (!q.empty()){
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (!vis[v]){
				vis[v]=1;
				dis[v]=dis[x]+1;
				q.push(v);
			}
		}
	}
	
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		cnt=0;
		init();
		for (int i=0;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v); 
			addedge(v,u);
		}
		bfs();
		for (int i=1;i<=n;i++){
			printf("%d",dis[i]);
			if (i<n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}


