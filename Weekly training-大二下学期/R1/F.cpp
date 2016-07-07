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

const int N=5050;

int n,m,x1,x2,y1,y2;
struct Seg {
   	int x1,x2,y1,y2;
   	Seg(){}
   	Seg(int a,int b,int c,int d):x1(a),y1(b),x2(c),y2(d){}
}seg[N];
int ans[N];

int f(Seg& a,int x,int y) {
	int xa,xb,ya,yb;
	xa=x-a.x1;ya=y-a.y1;
	xb=a.x2-a.x1;yb=a.y2-a.y1;
	// cout << xa << ' ' << ya << ' ' << xb << ' ' << yb << endl;
	return xa*yb-xb*ya;
}

bool check(Seg& a,Seg& b,int x,int y) {
	if (y>=y2 && y<=y1) {
		if (f(a,x,y)>=0 && f(b,x,y)<=0) return true;
	}
	return false;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int kase=1;
	while (SI(n)==1 && n) {
		if (kase!=1) cout << endl;kase++;
		SI(m);
		CLR(ans);
		SII(x1,y1);SII(x2,y2);
		seg[0]=Seg(x1,y2,x1,y1);
		seg[n+1]=Seg(x2,y2,x2,y1);
		rep(i,1,n) {
			int U,L;
			SII(U,L);
			seg[i]=Seg(L,y2,U,y1);
		}
		rep(i,1,m) {
			int x,y;
			SII(x,y);
			rep(j,0,n) {
				if (check(seg[j],seg[j+1],x,y)) {
					ans[j]++;
					break;
				}
			}
		}
		// cout << check(seg[0],seg[1],1,5) << endl;
		rep(i,0,n) printf("%d: %d\n",i,ans[i]);
		// rep(i,0,n+1) cout << seg[i].x1 << ' ' << seg[i].y1 << ' ' << seg[i].x2 << ' ' << seg[i].y2 << endl;
	}
	return 0;
}