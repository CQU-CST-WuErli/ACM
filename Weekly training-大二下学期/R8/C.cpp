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

const int N=1010;

int n,m;
int mp[N][N];
ll z[N*N+1010];
ll x[N*N+1010],y[N*N+1010];

void init() {
	rep(k,2,n*n+n) {
		x[k]=(12345+x[k-1]*23456+(x[k-2]*34567)+((x[k-1]*x[k-2])*45678))%5837501;
		y[k]=(56789+y[k-1]*67890+(y[k-2]*78901)+((y[k-1]*y[k-2])*89012))%9860381;
	}
	rep(k,0,n*n+n) z[k]=(x[k]*90123+y[k])%8475871+1;
	rep(i,0,n-1) rep(j,0,n-1) {
		if (i==j) mp[i][j]=0;
		else mp[i][j]=z[i*n+j];
	}
	// rep(i,0,n*n-1) cout << x[i] << ' ';
	// cout << endl;
	// rep(i,0,n*n-1) cout << y[i] << ' ';
	// cout << endl;
	// rep(i,0,n*n-1) cout << z[i] << ' ';
	// cout << endl;
	// rep(i,0,n-1) {
	// 	rep(j,0,n-1) cout << mp[i][j] << ' ';
	// 	cout << endl;
	// }
}

int vis[N];
ll d[N];

void spfa() {
	queue<ll> q;
	q.push(0);
	vis[0]=1;
	rep(i,0,n-1) d[i]=INF_LL;
	d[0]=0LL;
	while(q.size()) {
	    int x=q.front();q.pop();
	    vis[x]=0;
	    for (int i=1;i<n;i++) {
	    	if (i==x) continue;
	    	if (d[i]>d[x]+mp[x][i]) {
	    		d[i]=d[x]+mp[x][i];
	    		if (!vis[i]) {
	    			vis[i]=1;
	    			q.push(i);
	    		}
	    	}
	    }
	}
	ll ans=INF_LL;
	rep(i,1,n-1) ans=min(ans,d[i]%m);
	cout << ans << endl;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
        cin >> x[0] >> x[1] >> y[0] >> y[1];
        init();
        spfa();
    }
	return 0;
}