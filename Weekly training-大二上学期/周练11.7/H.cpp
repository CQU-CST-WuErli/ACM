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
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

struct P{
	double x,y,r;
}c[1100];
int vis[1100];
double st,ed;
int n;

bool check(P& a,P& b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) <= (a.r+b.r)*(a.r+b.r);
}

bool dfs(int x) {
	vis[x]=1;
	if(c[x].r>=c[x].y) return false;
	if (c[x].r>=c[x].x) st=min(st,c[x].y-sqrt(c[x].r*c[x].r-c[x].x*c[x].x));
	if (c[x].r+c[x].x>=1000.0) ed=min(ed,c[x].y-sqrt(c[x].r*c[x].r-(1000-c[x].x)*(1000-c[x].x)));
	for (int i=1;i<=n;i++) if (!vis[i]) {
		if (check(c[x],c[i])) if (!dfs(i)) return false;
 	}
 	return true;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		CLR(vis);
		for (int i=1;i<=n;i++) cin >> c[i].x >> c[i].y >> c[i].r;
		st=1000.0,ed=1000.0;
		int flag=1;
		for (int i=1;i<=n;i++) {
			if (!vis[i] && c[i].y+c[i].r>=1000) if (!dfs(i)) {
				flag=0;break;
			}
		}
		if (flag==0) cout << "IMPOSSIBLE\n";
		else printf("0.00 %.2lf 1000.00 %.2lf\n",st,ed);
	}
	return 0;
}

