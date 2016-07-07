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

struct P
{
	int x,y;
	P(){}
	P(int x,int y):x(x),y(y){}
};
P p[710];
int n;


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	SI(n);
    	rep(i,1,n) {
    		int x,y;
    		SII(p[i].x,p[i].y);
    	}
    	int ans=0;
    	map<pair<int,int>,int> mp;
    	rep(i,1,n)  {
    		mp.clear();
    		int cnt=0;
    		rep(j,1,n) if (i!=j) {
    			int dx=p[i].x-p[j].x;
    			int dy=p[i].y-p[j].y;
    			if (dx==0) {
    				mp[make_pair(-1,-1)]++;
    				cnt=max(cnt,mp[make_pair(-1,-1)]);
    			}
    			else {
    				int tt=__gcd(dx,dy);
    				dx/=tt;dy/=tt;
    				mp[make_pair(dx,dy)]++;
    				cnt=max(cnt,mp[make_pair(dx,dy)]);
    			}
    		}
    		ans=max(cnt,ans);
    	}
    	printf("Case %d: %d\n",kase,n<3?n:ans+1);
    }
	return 0;
}