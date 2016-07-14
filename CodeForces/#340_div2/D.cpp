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
	int x,y;
	bool operator < (const P& rhs) const {
		return x==rhs.x?y<rhs.y:x<rhs.x;
	}
};
P p[3];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> p[0].x >> p[0].y) {
		cin >> p[1].x >> p[1].y;
		cin >> p[2].x >> p[2].y;
		set<int> stx,sty;
		for (int i=0;i<3;i++) {
			stx.insert(p[i].x);
			sty.insert(p[i].y);
		}
		if (stx.size()==1 || sty.size()==1)  {
			cout << 1 << endl;
		}
		else {
			sort(p,p+3);
			if (p[0].x==p[1].x) {
				if (p[2].y<=p[0].y || p[2].y>=p[1].y && p[2].x!=p[1].x) {
					cout << 2 << endl;
					continue;
				}
			}
			if (p[0].y==p[1].y) {
				if (p[2].x>=p[1].x || p[2].x<=p[0].x && p[2].y!=p[1].y) {
					cout << 2 << endl;
					continue;
				}
			}
			if (p[1].x==p[2].x) {
				if (p[0].y<=p[1].y || p[0].y>=p[2].y && p[0].x!=p[1].x) {
					cout << 2 << endl;
					continue;
				}
			}
			if (p[1].y==p[2].y) {
				if (p[0].x<=p[1].x || p[0].x>=p[2].x && p[0].y!=p[1].y) {
					cout << 2 << endl;
					continue;
				}
			}
			cout << 3 << endl;
		}
	}
	return 0;
}

