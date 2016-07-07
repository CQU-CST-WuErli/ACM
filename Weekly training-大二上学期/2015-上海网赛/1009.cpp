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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

typedef pair<double,double> P;

P po[4];

double dis(P& a,P& b) {
	double ret=0.00;
	ret+=(a.first-b.first)*(a.first-b.first);
	ret+=(a.second-b.second)*(a.second-b.second);
	return sqrt(ret);
}

double area(P& a,P& b,P& c) {
	double l1=dis(a,b),l2=dis(a,c),l3=dis(b,c);
	double s=0.00;
	double pp=(l1+l2+l3)/2.0;
	s=sqrt(pp*(pp-l1)*(pp-l2)*(pp-l3));
	return s;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		for (int i=1;i<=3;i++) {
			cin >> po[i].first >> po[i].second;
		}
		double len=dis(po[1],po[2]);
		double aa=area(po[1],po[2],po[3]);
		double tmp=aa*2.0/dis(po[2],po[3]);
//		lookln(tmp);
		double BC=dis(po[2],po[3]);
//		lookln(BC);
		double tt=BC*BC/(tmp*4.0);
//		lookln(tt);
		double r=sqrt(tt*tt+BC*BC/4.0);
//		lookln(r);
		double t1=atan(BC/(2.0*tt));
		double ans=t1*r*2.0;
		ans+=tmp;
		printf("Case #%d: %.4lf\n",kase,ans);
	}
	return 0;
}

