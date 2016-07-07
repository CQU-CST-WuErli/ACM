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

const int N=1e4+100;

int n,m,k;

struct P{
	int cost;
	int vis;
	bool operator < (const P& rhs) const {
		return cost < rhs.cost;
	}
	void read() {
		SI(cost);
		vis=0;
	}
}bag[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;SI(t);
	while (t--) {
		SIII(n,m,k);
		rep(i,1,n) bag[i].read();
		ll tot=0;
		rep(i,1,m) {
			int x;SI(x);
			tot+=bag[x].cost;
//			cout << bag[x].cost;
			bag[x].vis=1;
		}
//		lookln(tot);
		if (tot>k) {
			cout << -1 << endl;
			continue;
		}
		k-=tot;
		int ans=m;
		sort(bag+1,bag+1+n);
		rep(i,1,n) if (!bag[i].vis) {
			if (k<bag[i].cost) break;
			k-=bag[i].cost;
			ans++;
			bag[i].vis=1;
		} 
		cout << ans << endl;
	} 
	return 0;
}

