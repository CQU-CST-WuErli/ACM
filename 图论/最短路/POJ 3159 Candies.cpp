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

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

const int N=4e5;
int n,m;
int pnt[N],nxt[N],head[N],w[N];
int cnt;

void add_edge(int u,int v,int c){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	w[cnt++]=c;
}

int vis[30010];
int d[30010];
typedef pair<int,int> sta;

int dijkstra(){
	priority_queue<sta,vector<sta>,greater<sta> > q;
	CLR(vis);
	MEM(d,INF);
	q.push(sta(d[1]=0,1));
	while (!q.empty()){
		sta x=q.top();
		q.pop();
		if (vis[x.second]) continue;
		vis[x.second]=1;
		for (int i=head[x.second];~i;i=nxt[i]){
			int v=pnt[i];
			if (vis[v]) continue;
			if (d[v]>x.first+w[i]){
				d[v]=x.first+w[i];
				q.push(sta(d[v],v));
			} 
		}
	}
	return d[n];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		OFF(head);cnt=0;
		for (int i=1;i<=m;i++){
			int u,v,c;
			u=read();v=read();c=read();
			add_edge(u,v,c);
		} 
		cout << dijkstra() << endl;
	}
	return 0;
}

