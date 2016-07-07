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

const int N=2e4;

int T;
int n;
int cnt[N<<2];
double one[N<<2],two[N<<2];

struct Seg {
	double l,r,h;
	int val;
	Seg(){}
	Seg(double l,double r,double h,int val):l(l),r(r),h(h),val(val){}
	bool operator < (const Seg& rhs) const {
		return h<rhs.h;
	}
};
vector<Seg> v;
vector<double> mp;

void pushup(int l,int r,int rt) {
	if (cnt[rt]>=2) two[rt]=one[rt]=mp[r]-mp[l-1];
	else if (cnt[rt]==1) {
		one[rt]=mp[r]-mp[l-1];
		if (l==r) two[rt]=0;
		else two[rt]=one[rt<<1]+one[rt<<1|1];
	}
	else {
		if (l==r) one[rt]=two[rt]=0;
		else {
			one[rt]=one[rt<<1]+one[rt<<1|1];
			two[rt]=two[rt<<1]+two[rt<<1|1];
		}
	}
}

void update(int L,int R,int val,int l,int r,int rt) {
	if (L<=l && r<=R) {
		cnt[rt]+=val;
		pushup(l,r,rt);
		return;
	}
	int mid=(l+r)>>1;
	if (L<=mid) update(L,R,val,Lson);
	if (R>mid) update(L,R,val,Rson);
	pushup(l,r,rt);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	SI(T);
	while (T--) {
		// BUG;
		double X1,X2,Y1,Y2;
		SI(n);
		mp.clear();
		v.clear();
		rep(i,1,n) {
			scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
			v.push_back(Seg(X1,X2,Y1,1));
			v.push_back(Seg(X1,X2,Y2,-1));
			mp.push_back(X1);mp.push_back(X2);
		}
		sort(v.begin(),v.end());
		sort(mp.begin(),mp.end());
		mp.resize(unique(mp.begin(),mp.end())-mp.begin());
		CLR(cnt);
		CLR(one);CLR(two);
		int m=mp.size();
		double ans=0.0;
		// BUG;
		rep(i,0,v.size()-2) {
			int l=lower_bound(mp.begin(),mp.end(),v[i].l)-mp.begin();
			// BUG;
			int r=lower_bound(mp.begin(),mp.end(),v[i].r)-mp.begin();
			l++,r++;
			if (l<r) update(l,r-1,v[i].val,1,m,1);
			// BUG;
			ans+=two[1]*(v[i+1].h-v[i].h);
		}
		printf("%.2f\n",ans+eps);

	}
	return 0;
}