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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
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

const int N=1e5;
int pnt[N],nxt[N],head[N],pre[N],cap[N],flow[N];
int a[500],p[500];
int cnt;
int n,F,D;

void add_edge(int u,int v,int c,int f){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	pre[cnt]=u;cap[cnt]=c;flow[cnt++]=f;
}

int Edmends_Karp(int s,int t){
	int Max_flow=0;
	for (;;){
		CLR(a);
		queue<int> q;
		a[s]=INF;
		q.push(s);
		while (!q.empty()){
			int x=q.front();q.pop();
			for (int i=head[x];~i;i=nxt[i]){
				int v=pnt[i];
				if (!a[v] && cap[i]>flow[i]){
					p[v]=i;
					a[v]=min(a[x],cap[i]-flow[i]);
					q.push(v);
				}
			}
			if (a[t]) break;
		}
		if (!a[t]) break;	
		for (int u=t;u!=s;u=pre[p[u]]){
			cap[p[u]]-=a[t];
			cap[p[u]^1]+=a[t];
		}
		Max_flow+=a[t];
	}
	return Max_flow;
}



int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SIII(n,F,D)==3){
		int s=0,t=F+D+2*n+1;
		OFF(head);cnt=0;
		for (int i=1;i<=F;i++) {   //   source -> food
			add_edge(0,i,1,0);
			add_edge(i,0,0,0);
		}                               
		for (int i=F+1;i<=F+n;i++){  //  cow  ->  cow
			add_edge(i,i+n,1,0);
			add_edge(i+n,i,0,0);
		}
		for (int i=F+2*n+1;i<=F+2*n+D;i++){  //   drink  ->  sink
			add_edge(i,t,1,0);
			add_edge(t,i,0,0);
		}
		for (int i=1;i<=n;i++){
			int sf,sd;
			SII(sf,sd);
			for (int j=1;j<=sf;j++){
				int id;
				SI(id);
				add_edge(id,i+F,1,0);
				add_edge(i+F,id,0,0);
			}
			for (int j=1;j<=sd;j++){
				int id;
				SI(id);
				add_edge(i+F+n,F+2*n+id,1,0);
				add_edge(F+2*n+id,i+F+n,0,0);
			}
		}
		printf("%d\n",Edmends_Karp(s,t));
	}
	return 0;
}



