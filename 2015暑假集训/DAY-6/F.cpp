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
const ll N=200010;

int pnt[N*4],nxt[N*4],head[N*4],c[N*4],cnt;
int vis[N];
int d[N];
int n,m;

void addedge(int u,int v,int cor){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;c[cnt]=cor;
	cnt++;
}

void bfs1(int s){
	CLR(vis);
	CLR(d);
	vis[s]=1;
	queue<int> q;
	q.push(s);
	d[s]=0;
	while (!q.empty()){
		ll x=q.front();q.pop();
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (!vis[v]){
				vis[v]=1;
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
} 

vector<int> path;

void bfs2(int s){
	CLR(vis);
	vis[s]=1;
	queue<int> q;
	q.push(s);path.clear();
	path.resize(d[1]+1);
	for (int i=0;i<=d[1];i++) path[i]=0x3f3f3f3f;
	while (!q.empty()){
		int x=q.front();q.pop();
		int mmin=0x3f3f3f3f;
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (  d[v]+1==d[x] && c[i]<mmin) {
				mmin=c[i];
			}
		}
		path[d[x]-1]=min(path[d[x]-1],mmin);
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (!vis[v] && d[v]+1==d[x] && c[i]==mmin){
				vis[v]=1;
				q.push(v);
			}
		} 
	} 
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (cin >> n >> m){
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(nxt,-1,sizeof(nxt));
		for (int i=0;i<m;i++){
			int u,v,cor;
			scanf("%d%d%d",&u,&v,&cor);
			addedge(u,v,cor);
			addedge(v,u,cor);
		}	
		bfs1(n);
		bfs2(1);
		cout << d[1] << endl;
		for (int i=d[1]-1;i>=0;i--) {
			cout << path[i];
			if (i>0) cout << " ";
			else cout << endl;
		}
	}
	return 0;
}


