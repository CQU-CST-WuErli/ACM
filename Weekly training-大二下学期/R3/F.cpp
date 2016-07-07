//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
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
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
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

const int N=5050;
int n,m,k;
int pnt[N<<1],nxt[N<<1],head[N],cap[N<<1],cost[N<<1],pre[N<<1];
int cnt;

void add_edge(int u,int v,int f,int c) {
	pnt[cnt]=v;pre[cnt]=u;nxt[cnt]=head[u];
	cap[cnt]=f;cost[cnt]=c;head[u]=cnt++;
}

int a[N],d[N],vis[N],p[N];

bool spfa(int s,int t,int &Flow,ll& Cost) {
	CLR(a);CLR(vis);
	rep(i,s,t) d[i]=INF_INT;
	queue<int> q;
	vis[s]=1;
	a[s]=INF_INT;
	d[s]=0;
	q.push(s);
	while (q.size()) {
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]) {
			int v=pnt[i];
			if (d[v]>d[x]+cost[i] && cap[i]) {
				d[v]=d[x]+cost[i];
				p[v]=i;
				a[v]=min(a[x],cap[i]);
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	if (d[t]>=INF_INT) return false;
	Flow+=a[t];
	Cost+=d[t];
	for (int u=t;u!=s;u=pre[p[u]]) {
		cap[p[u]]-=a[t];
		cap[p[u]^1]+=a[t];
	}
	return true;
}

ll MFMC(int s,int t) {
	int Flow=0;
	ll Cost=0;
	int ans=INF_INT;
	int sump=k;
	int nowp=0;
	int cur=0;
	while (spfa(s,t,Flow,Cost)) {
		sump-=(d[t]-cur)*nowp+a[t];
		cur=d[t];nowp+=a[t];
		int tmp=d[t]+(sump<=0?0:sump)/nowp+((sump<=0?0:sump)%nowp?1:0);
		ans=min(ans,tmp);
		if (sump<=0) break;
	}
	return ans;
}
int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SIII(n,m,k)==3) {
    	OFF(head);cnt=0;
        rep(i,1,m) {
        	int u,v,c;
        	u=read();v=read();c=read();
        	// cout << u << ' ' << v <<  ' ' << c << endl;
        	u++,v++;
        	add_edge(u,v,c,1);
        	add_edge(v,u,0,-1);
        }
        int ans;
        if (k==0) ans=0;
        else ans=MFMC(1,n);
        if (ans>=INF_INT) puts("No solution");
        else printf("%d\n",ans);
    }
	return 0;
}