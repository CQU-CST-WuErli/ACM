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
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
ll r,s,e;

ll ksm(int n) {
	if (n==0) return 1;
	ll ret=0;
	ret=ksm(n/2);
	ret*=ret;
	if (n%2) ret*=2;
	return ret;
}

ll dfs(int n,ll r,ll s,ll e) {
	if (n==0) return 1;
	ll ret=0;
	ll tmp=ksm(n-1);
	if (r<tmp) {
		if (s<tmp && e>=tmp) {
			ret+=dfs(n-1,r,s,tmp-1);
			e%=tmp;
			ret+=dfs(n-1,r,0,e);
		}
		else if (e<tmp) {
			ret+=dfs(n-1,r,s,e);
		}
		else if (s>=tmp) {
			s%=tmp;
			e%=tmp;
			ret+=dfs(n-1,r,s,e);
		}
	}
	else {
		r%=tmp;
		if (s<tmp && e>=tmp) {
			ret+=dfs(n-1,r,s,tmp-1);
			e%=tmp;
			ret+=-1*dfs(n-1,r,0,e);
		}
		else if (e<tmp) {
			ret+=dfs(n-1,r,s,e);
		}
		else if (s>=tmp) {
			s%=tmp;
			e%=tmp;
			ret+=-1*dfs(n-1,r,s,e);
		}
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1 && n!=-1) {
	    cin >> r >> s >> e;
 		cout << dfs(n,r,s,e) << endl;
	}
	return 0;
}