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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=5e6;
int pnt[N],head[1000],nxt[N],cap[N];
int cnt;
int n,m,l,k;
int link[88][88];

void add_edge(int u,int v,int f){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=f;
}

int iter[1000],level[1000];

bool bfs(int s,int t){
	OFF(level);
	queue<int> q;
	q.push(s);
	level[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (level[v]==-1 && cap[i]){
				level[v]=level[x]+1;
				q.push(v);
			}
		}
	}
	return level[t]!=-1;
}

int dfs(int u,int t,int Flow){
	if (u==t || Flow==0) return Flow;
	int left=Flow;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(cap[i],left));
			iter[u]=i;
			cap[i]-=d;
			cap[i^1]+=d;
			left-=d;
			if (!left) return Flow; 
		}
	}
	level[u]=-1;
	return Flow-left;
}

int Dinic(int s,int t){
	int Max_flow=0;
	while (bfs(s,t)){
		for (int i=s;i<=t;i++) iter[i]=head[i];
		Max_flow+=dfs(s,t,INF_INT);
	}
	return Max_flow;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
		SII(n,m);SII(l,k);
		CLR(link);
		int source=0,sink=n+2*m+1;
		rep(i,1,l) {
			int u,v;
			SII(u,v);
			link[u][v]=1;
		}
		OFF(head);cnt=0;
		// source->singer
		rep(i,1,n) {
			add_edge(source,i,k);
			add_edge(i,source,0);
		}
		int tt=cnt;
		// singer->song
		rep(i,1,n) rep(j,1,m) {
			if (link[i][j]) {
				add_edge(i,n+m+j,1);
				add_edge(n+m+j,i,0);
			}
			else {
				add_edge(i,n+j,1);
				add_edge(n+j,i,0);
			}
		}
		int kk=cnt;
		rep(i,1,m) {
			add_edge(n+i,n+m+i,k);
			add_edge(n+m+i,n+i,0);
		}
		int ss=cnt;
		//
		rep(i,1,m) {
			add_edge(n+m+i,sink,k);
			add_edge(sink,n+m+i,0);
		}
		int l=0,r=m;
		int ans=0;
//		cout << l << ' ' << r << endl;
		while (l<=r) {
			int mid=(l+r)/2;
//			lookln(mid);
			for (int i=0;i<tt;i+=2) {
				cap[i]=mid;
				cap[i^1]=0;
			}
			for (int i=tt;i<kk;i+=2) {
				cap[i]=1;
				cap[i^1]=0;
			}
			for (int i=kk;i<ss;i+=2) {
				cap[i]=k;
				cap[i^1]=0;
			}
			for (int i=ss;i<cnt;i+=2) {
				cap[i]=mid;
				cap[i^1]=0;
			}
			int tmp=Dinic(source,sink);
//			lookln(tmp);
			if (tmp==mid*n) {
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout << "Case " << kase << ": " << ans << endl;
	}
	return 0;
}

