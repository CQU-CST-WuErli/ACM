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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int maxn=1e5+100;

int n,m,k;
int N,M;
int pnt[maxn],nxt[maxn],head[1010],w[maxn];
int cnt;
int have[1010];
int food[1<<12];
int sta[20];


void add_edge(int u,int v,int c) {
	pnt[cnt]=v;nxt[cnt]=head[u],w[cnt]=c;head[u]=cnt++;
}

void read() {
	SIII(n,m,k);
    CLR(sta);
	rep(i,0,n-1) {
    	int x;SI(x);
		while(x--) {
    	    int t;SI(t);
      	    sta[i]=sta[i]|(1<<t);
       	}
    }
	// rep(i,1,n) cout << sta[i] << endl;
    SII(N,M);
	OFF(head);cnt=0;
    rep(i,1,M) {
 	 	int u,v,c;
   		SIII(u,v,c);
       	add_edge(u,v,c);
       	add_edge(v,u,c);
    }
    OFF(have);
	rep(i,0,m-1) {
		int x;SI(x);
		have[x]=i;
	}
}


void preprocess() {
	for (int i=0;i<(1<<m);i++) {
		int flag=0;
		for (int j=0;j<n;j++) {
			if ((i&sta[j])==sta[j]) flag++;
		}
		food[i]=flag;
	}
	// for (int i=0;i<(1<<m);i++) cout << i << "==" <<food[i] << endl;
}

int vis[1<<12][1010];
int dp[1<<12][1010];

struct Sta
{
	int state,id;
	Sta(int state,int id):state(state),id(id){}
};

int ans;
void solve(int iCase) {
	ans=INF_INT;
	MEM(dp,INF_INT);
	CLR(vis);
	dp[0][1]=0;
	queue<Sta> q;
	q.push(Sta(0,1));
	while(q.size()) {
	    Sta now=q.front();q.pop();
	    int s=now.state,pos=now.id;
	  	vis[s][pos]=0;
	    if (food[s]>=k) {
	    	ans=min(ans,dp[s][pos]);
	    }
	    for (int i=head[pos];~i;i=nxt[i]) {
	    	int v=pnt[i];
	    	int tmp=s;
	    	if (have[v]>=0) tmp=tmp|(1<<have[v]);
	    	if (dp[tmp][v]>=dp[s][pos]+w[i]) {
	    		dp[tmp][v]=dp[s][pos]+w[i];
	    		if (!vis[tmp][v]) {
	    			q.push(Sta(tmp,v));
	    			vis[tmp][v]=1;
	    		}
	    	}
	    }
	}
	printf("Case %d: %d\n",iCase,ans);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	read();
    	preprocess();
    	solve(kase);
    }
	return 0;
}