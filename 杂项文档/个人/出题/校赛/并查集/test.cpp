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

const int N=1e6+100;
int par[N],rnk[N];
int sum[N];
int n,m;

void init(int n) {
	for (int i=1;i<=n;i++) par[i]=i,rnk[i]=0,sum[i]=1;
}

int find(int x) {
	if (par[x]==x) return x;
	return par[x]=find(par[x]);
}

void unite(int x,int y) {
	x=find(x);y=find(y);
	if (x==y) return;
	if (rnk[x]<rnk[y]) par[x]=y,sum[y]+=sum[x],sum[x]=0;
	else {
		par[y]=x;
		sum[x]+=sum[y];
		sum[y]=0;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
	    init(n);
	    char op;
	    int a,b;
	    while(m--) {
	    	cin >> op;
	    	if (op=='U') {
	    		SII(a,b);
	    		unite(a,b);
	    	}
	    	else if (op=='D') {
	    		SI(a);
	    		int fa=find(a);
	    		for (int i=1;i<=n;i++) if (find(i)==fa) par[i]=i,sum[i]=1;
	    	}
	    	else if (op=='S') {
	    		SI(a);
	    		cout << sum[find(a)] << endl;
	    	}
	    	else if (op=='F') {
	    		SII(a,b);
	    		if (find(a)==find(b)) puts("Yes");
	    		else puts("No");
	    	}
	    }
	}
	return 0;
}