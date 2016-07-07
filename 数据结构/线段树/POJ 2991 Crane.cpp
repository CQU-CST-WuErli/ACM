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

const int N=2e4+100;

int n,q;
struct P{
	double x,y;
}p[N<<2];
int angle[N<<2];
int add[N<<2];

void push_up(int rt) {
	p[rt].x=p[rt<<1].x+p[rt<<1|1].x;
	p[rt].y=p[rt<<1].y+p[rt<<1|1].y;
}

void work(int angle,int rt) {
	double x=p[rt].x,y=p[rt].y;
    double ang = pi/180.0*angle*1.0;
    p[rt].x = cos(ang)*x-sin(ang)*y;
    p[rt].y = sin(ang)*x+cos(ang)*y;
}

void push_down(int rt) {
	if (add[rt]) {
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		work(add[rt],rt<<1);
		work(add[rt],rt<<1|1);
		add[rt]=0;
	}
}

void build(int l,int r,int rt) {
	add[rt]=0;
	if (l==r) {
		scanf("%lf",&p[rt].y);
		p[rt].x=0.0;
		return;
	}
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
	push_up(rt);
}

void update(int L,int R,int v,int l,int r,int rt) {
	if (L<=l && r<=R) {
		add[rt]+=v;
		work(v,rt);
		return;
	}
	push_down(rt);
	int mid=(l+r)>>1;
	if (L<=mid) update(L,R,v,Lson);
	if (R>mid) update(L,R,v,Rson);
	push_up(rt);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while(SII(n,q)==2) {
		if (kase!=1) puts("");kase++;
		build(Root);
		rep(i,1,n) angle[i]=180;
		rep(i,1,q) {
			int pos,ang;
			SII(pos,ang);
			int tmp=(ang-angle[pos]+360)%360;
			update(pos+1,n,tmp,Root);
			angle[pos]=ang;
			printf("%.2f %.2f\n",p[1].x,p[1].y);
		}
	}
	return 0;
}

