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

const int N=2e4;
int pnt[N],head[N],nxt[N],cost[N];
int level[110],price[110];
int cnt;
int n,m;

void add_edge(int u,int v,int c){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cost[cnt++]=c;
}	

int d[110];
int vis[110];

typedef pair<int,int> sta;
int dijkstra(){
	priority_queue<sta,vector<sta>,greater<sta> > q;
//	for (int i=1;i<=n;i++) d[i]=price[i];
	MEM(d,INF);
	q.push(sta(d[0]=0,0));
	while (!q.empty()){
		sta x=q.top();q.pop();
		if (vis[x.second]) continue;
		vis[x.second]=1;
		int u=x.second,w=x.first;
		for (int i=head[u];~i;i=nxt[i]){
			int v=pnt[i];
			if (vis[v]) continue;
			if (d[v]>w+cost[i]){
				d[v]=w+cost[i];
				q.push(sta(d[v],v));
			} 
		}
	}
	return d[1];
}
	
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> m >> n ){
		cnt=0;OFF(head);
		for (int i=1;i<=n;i++){
			int x;
			cin >> price[i] >> level[i] >> x;
			add_edge(0,i,price[i]);
			for (int j=1;j<=x;j++){
				int u,w;
				cin >> u >> w;
				add_edge(u,i,w);
			}
		}
		int ans=INF;
		for (int i=1;i<=n;i++){
			int minl=level[i];
			CLR(vis);
			for (int j=1;j<=n;j++) {
				if ((level[j]-minl)>m || level[j]<minl) vis[j]=1;
				else vis[j]=0;
			}
//			for (int i=1;i<=n;i++) cout << vis[i] << ' ';
//			cout << endl;
			int tmp;
			ans=min(ans,tmp=dijkstra());
//			lookln(tmp);
		}
		cout << ans << endl;
	}
	return 0;
}	
	
