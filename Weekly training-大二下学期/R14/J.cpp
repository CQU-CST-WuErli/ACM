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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int a[110],b[110];
int n,m;
int mp[110][110];
int used[110],match[110];

int find(int x) {
	rep(i,1,m) if (mp[x][i] && !used[i]) {
		used[i]=1;
		if (match[i]==0 || find(match[i])) {
			match[i]=x;
			return 1;
		}
	}
	return 0;
}

int hungary() {
	int ret=0;
	CLR(match);
	rep(i,1,n) {
		CLR(used);
		if (find(i)) ret++;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	SI(n);
    	rep(i,1,n) SI(a[i]);
    	SI(m);
    	rep(i,1,m) SI(b[i]);
    	CLR(mp);
    	rep(i,1,n) rep(j,1,m) {
    		if (a[i]==0 && b[j]==0) mp[i][j]=1;
    		else if (a[i]!=0 && b[j]%a[i]==0) mp[i][j]=1;
    	}
    	int ans=hungary();
    	cout << "Case " << kase << ": " << ans << endl;
    }
	return 0;
}