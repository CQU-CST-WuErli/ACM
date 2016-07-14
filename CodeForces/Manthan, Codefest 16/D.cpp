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

int n;
int a[1010];
int ans;
int vis[1010];
map<int,int> mp;

void dfs(int x,int y,int cnt) {
	ans=max(cnt,ans);
	if (mp[x+y]) {
		mp[x+y]--;
		dfs(y,x+y,cnt+1);
		mp[x+y]++;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1) {
	    rep(i,1,n) SI(a[i]);
	    rep(i,1,n) mp[a[i]]++;
	    int kk=0;
	    rep(i,1,n) if (a[i]==0) kk++;
	    ans=0;
	    CLR(vis);
	    rep(i,1,n) rep(j,1,n) if (i!=j) {
	    	if (a[i]==0 && a[j]==0) {
	    		ans=max(ans,kk);
	    		continue;
	    	}
	    	mp[a[i]]--;mp[a[j]]--;
	    	dfs(a[i],a[j],2);
	    	mp[a[i]]++,mp[a[j]]++;
	    }
	    cout << ans << endl;
	}
	return 0;
}