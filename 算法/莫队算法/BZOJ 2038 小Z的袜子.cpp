//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
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

const int N=5e4+10;
const int M=250;

int n,m;
int c[N];
int num[N];
ll ans,up[N],dw[N];

struct Query
{
	int l,r,id;
	Query(int l,int r,int id):l(l),r(r),id(id){}
	bool operator < (const Query& rhs) const {
		return r<rhs.r;
	}
};
vector<Query> block[M];

void update(int x,int d) {
	ans-=num[c[x]]*num[c[x]];
	num[c[x]]+=d;
	ans+=num[c[x]]*num[c[x]];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
		rep(i,0,250) block[i].clear();
	    rep(i,0,n-1) c[i]=read();
	    rep(i,1,m) {
	    	int l,r;
	    	l=read();r=read();
	    	l--,r--;
	    	block[l/M].push_back(Query(l,r,i));
	    }
	    ans=0LL;
	    CLR(num);
	    rep(i,0,n/M+2) sort(block[i].begin(),block[i].end());
	    int pL,pR;
	    rep(i,0,n/M+2) if (block[i].size()) {
	    	pL=i*M;
	    	pR=i*M-1;
	    	rep(j,0,block[i].size()-1) {
	    		Query &q=block[i][j];
	    		if (pR<q.r) rep(k,pR+1,q.r) update(k,1);
	    		else Rep(k,pR,q.r+1) update(k,-1);
	    		pR=q.r;
	    		if (pL<q.l) rep(k,pL,q.l-1) update(k,-1);
	    		else Rep(k,pL-1,q.l) update(k,1);
	    		pL=q.l;
	    		up[q.id]=ans-q.r+q.l-1;
	    		dw[q.id]=1LL*(q.r-q.l)*(q.r-q.l+1);
	    		// cout << up[q.id] << ' ' << dw[q.id] << endl;
	    		ll tmp=__gcd(up[q.id],dw[q.id]);
	    		up[q.id]/=tmp;
	    		dw[q.id]/=tmp;
	    	}
	    	rep(j,pL,pR) update(j,-1);
	    }
	   	rep(i,1,m) printf("%lld/%lld\n",up[i],dw[i]);
	}
	return 0;
}

// 0 6
// 6 6
// 8 20
// 8 30
