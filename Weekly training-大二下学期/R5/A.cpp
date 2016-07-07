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

const int N=6e3;
const int M=100;
int t;
int n,m,k;
int pnt[N],head[M],nxt[N],w[N],cnt;
int s[M];
int vis[M][1<<12];
int d[M][1<<12],dp[1<<12];

struct Sta
{
    int id,state;
    Sta(int id,int state):id(id),state(state){}
};
queue<Sta> q;

void add_edge(int u,int v,int c) {
    pnt[cnt]=v;nxt[cnt]=head[u];w[cnt]=c;head[u]=cnt++;
}

void read() {
    SIII(n,m,k);
    CLR(s);CLR(vis);
    OFF(head);cnt=0;
    rep(i,1,m) {
        int u,v,c;
        SIII(u,v,c);
        // cout << u << ' ' << v << ' ' << c << endl;
        add_edge(u,v,c);
        add_edge(v,u,c);
    }
    MEM(d,INF_INT);
    rep(i,1,k) {
        s[i]=1<<(i-1),d[i][s[i]]=0;
        s[n-i+1]=1<<(k+i-1),d[n-i+1][s[n-i+1]]=0;
    }
}

bool check(int sta) {
    int ret=0;
    for(int i=0;sta;i++,sta>>=1)
        ret+=(sta&1)*(i<k?1:-1);
    return ret==0;
}

void spfa() {
    while(q.size()) {
        Sta now=q.front();q.pop();
        int id=now.id,sta=now.state;
        vis[id][sta]=0;
        for (int i=head[id];~i;i=nxt[i]) {
            int v=pnt[i];
            if (d[v][sta|s[v]]>d[id][sta]+w[i]) {
                d[v][sta|s[v]]=d[id][sta]+w[i];
                if (sta==(sta|s[v]) && !vis[v][sta]) {
                	vis[v][sta]=1;
                	q.push(Sta(v,sta));
                }
            }
        }
    }
}

void solve() {
    for (int S=0;S<1<<(2*k);S++) {
        for (int root=1;root<=n;root++) {
            for (int i=(S-1)&S;i;i=(i-1)&S)
                d[root][S]=min(d[root][S],d[root][i|s[root]]+d[root][(S-i)|s[root]]);
            if (d[root][S]<INF_INT) q.push(Sta(root,S)),vis[root][S]=1;
        }
        spfa();
    }
    for (int S=0;S<1<<(2*k);S++) {
        dp[S]=INF_INT;
        rep(i,1,n) dp[S]=min(dp[S],d[i][S]);
    }
    for (int S=1;S<1<<(2*k);S++) {
        if (check(S)) {
            for (int i=(S-1)&S;i;i=(i-1)&S) {
                if (check(i)) {
                    dp[S]=min(dp[S],dp[S-i]+dp[i]);
                }
            }
        }
    }
    if (dp[(1<<(2*k))-1]>=INF_INT) puts("No solution");
    else cout << dp[(1<<(2*k))-1] << endl;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    SI(t);
    while(t--) {
        read();
        solve();
    }
    return 0;
}