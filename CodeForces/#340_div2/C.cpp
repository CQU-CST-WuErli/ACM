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

struct P{
	ll x,y;
	ll dis;
	bool operator < (const P& rhs) const {
		return dis<rhs.dis;
	} 
};
P f[3];
P p[2010];
int n;

ll getdis(P& a,P& b) {
	ll ret=0;
	ret+=(a.x-b.x)*(a.x-b.x);
	ret+=(a.y-b.y)*(a.y-b.y);
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		cin >> f[1].x >> f[1].y >> f[2].x >> f[2].y;
		rep(i,1,n) cin >> p[i].x >> p[i].y;
		rep(i,1,n) {
			p[i].dis=getdis(p[i],f[1]);
		}
		sort(p+1,p+1+n);
		ll ans=1e18;
		for (int i=1;i<=n;i++) {
			ll tmp=p[i].dis;
			ll tt=0;
			for (int j=i+1;j<=n;j++) {
				tt=max(tt,getdis(f[2],p[j]));
			}
			if (ans>tmp+tt) {
				ans=tmp+tt;
			}
		}
		rep(i,1,n) {
			p[i].dis=getdis(p[i],f[2]);
		}
		sort(p+1,p+1+n);
		for (int i=1;i<=n;i++) {
			ll tmp=p[i].dis;
			ll tt=0;
			for (int j=i+1;j<=n;j++) {
				tt=max(tt,getdis(f[1],p[j]));
			}
			if (ans>tmp+tt) {
				ans=tmp+tt;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

