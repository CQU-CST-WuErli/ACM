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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
typedef long long  ll;
using namespace std;

double a[1010],b[1010];
struct P
{
	double val;
	int index;
	bool operator < (const P& rhs) const {
		return val>rhs.val;
	}
}test[1010];
int n,k;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,k)==2 && (n || k)) {
	    rep(i,0,n-1) scanf("%lf",a+i);
	    rep(i,0,n-1) scanf("%lf",b+i);
	    double l=1.0,ans;
	    do {
	    	ans=l;
	    	rep(i,0,n-1) {
	    		test[i].val=a[i]-ans*b[i];
	    		test[i].index=i;
	    	}
	    	//
	    	sort(test,test+n);
	    	double p=0.0,q=0.0;
	    	rep(i,0,n-k-1) p+=a[test[i].index],q+=b[test[i].index];
	    	//
	    	l=p/q;
	    }while(abs(ans-l)>=eps);
	    printf("%.0f\n",100*l);
	}
	return 0;
}