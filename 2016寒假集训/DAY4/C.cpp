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

int rev(int x) {
	int ret=0;
	while (x) {
		int tmp=x%10;
		x/=10;
		ret=ret*10+tmp;
	}	
	return ret;
}

map<pair<int,int>,int> mpx,mpy;
map<int,int> mp;
int maxx,maxy,w;

void init() {
	rep(i,1,200000) mp[i]=rev(i);
//	rep(i,1,20) cout << i << ' ' << mp[i]  << endl;
}

pair<int,int> get(int x,int flag) {
	int tmp=__gcd(x,mp[x]);
	pair<int,int> ret;
	ret.first=x/tmp;
	ret.second=mp[x]/tmp;
	if (flag) swap(ret.first,ret.second);
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	while (SIII(maxx,maxy,w)==3) {
		mpx.clear();mpy.clear();
		rep(i,1,maxy) {
			pair<int,int> tmp=get(i,0);
			mpy[tmp]++;
		}
		int tt=0;
		int ok=0,x,ans;
		rep(i,1,maxx) {
			pair<int,int> tmp=get(i,1);
			tt+=mpy[tmp];
			mpx[tmp]++;
			if (tt>=w){
				ok=1;
				x=i;
				break;
			}
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		int y=maxy;
		ans=y*x;
		int a=x,b=y;
		while (y) {
			mpy[get(y,0)]--;
			tt-=mpx[get(y,0)];
			ok=0;
			while (x<maxx && tt<w) {
				x++;
				pair<int,int> tmp=get(x,1);
				mpx[tmp]++;
				tt+=mpy[tmp];
			}
			y--;
			if (tt>=w && x*y<ans) {
				ans=x*y;
				a=x;b=y;
			}
			if (x>=maxx) break;
		}
		cout << a << ' ' << b << endl;
	}
	return 0;
}

