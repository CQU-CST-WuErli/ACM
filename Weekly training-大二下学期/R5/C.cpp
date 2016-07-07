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

int n,q;

int par[10010],rnk[10010],size[10010],ans[10010];

void init() {
	rep(i,1,n) {
		par[i]=i;
		size[i]=1;
		ans[i]=0;
	}
}

int find(int x) {
	if (par[x]==x) return x;
	int tmp=par[x];
	par[x]=find(par[x]);
	ans[x]+=ans[tmp];
	return par[x];
}


void unite(int x,int y) {
	x=find(x),y=find(y);
	if (x==y) return;
	ans[x]=1;
	size[y]+=size[x];
	par[x]=y;
	return;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
		SII(n,q);
		init();
		printf("Case %d:\n",kase);
		rep(i,1,q) {
			char op[10];
			int a,b;
			scanf("%s",op);
			if (op[0]=='T') {
				SII(a,b);
				unite(a,b);
			}
			else {
				SI(a);
				int tmp=find(a);
				printf("%d %d %d\n",tmp,size[tmp],ans[a]);
			}
		}
	}
	return 0;
}