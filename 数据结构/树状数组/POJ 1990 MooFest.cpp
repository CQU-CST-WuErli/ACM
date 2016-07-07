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
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=20010;

struct P{
	int x,v;
	int id;
	bool operator < (const P& rhs) const {
		return v<rhs.v;
	}
	void read() {
		SII(v,x);
	}
}cow[N]; 

bool cmp(const P& a,const P& b)  {
	return a.x<b.x;
}

int n;
ll sum[N],num[N];

int lowbit(int x) {
	return x&(-x);
}

void update(ll *a,int pos,int val) {
	while (pos<=n) {
		a[pos]+=val;
		pos+=lowbit(pos);
	}
}

ll query(ll *a,int pos) {
	ll ret=0;
	while (pos) {
		ret+=a[pos];
		pos-=lowbit(pos);
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		rep(i,1,n) cow[i].read();
		CLR(sum);CLR(num);
//		rep(i,1,n) cout << cow[i].v << ' ' << cow[i].x << endl;
		sort(cow+1,cow+1+n,cmp);
		rep(i,1,n) {
			cow[i].id=i; 
		}
		sort(cow+1,cow+1+n);
		ll ans=0;
		rep(i,1,n) {
			ll lsum=query(sum,cow[i].id),rsum=query(sum,n)-lsum;
			ll lnum=query(num,cow[i].id),rnum=query(num,n)-lnum;
			ans+=(lnum*cow[i].x-lsum+rsum-rnum*cow[i].x)*cow[i].v;
			update(sum,cow[i].id,cow[i].x);
			update(num,cow[i].id,1);
		}
		cout << ans << endl; 
	}
	return 0;
}

