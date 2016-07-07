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

#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1

int color[N<<2],cover[N<<2];
int n,m;

// 0->rand
void build(int l,int r,int rt) {
	color[rt]=2;
	cover[rt]=-1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
}

void pushup(int rt) {
	if (color[rt<<1]==0 || color[rt<<1|1]==0 || color[rt<<1]!=color[rt<<1|1]) color[rt]=0;
	else color[rt]=color[rt<<1];
}

void pushdown(int rt) {
	if (cover[rt]!=-1) {
		cover[rt<<1]=cover[rt<<1|1]=cover[rt];
		color[rt<<1]=color[rt<<1|1]=cover[rt];
		cover[rt]=-1;
	}
}

set<int> st;

void update(int L,int R,int v,int l,int r,int rt) {
	if (L<=l && r<=R) {
		cover[rt]=v;
		color[rt]=v;
		return;
	}
	// cout << "l=" << l << " r=" << r << endl;
	pushdown(rt);
	int mid=(l+r)>>1;
	if (L<=mid) update(L,R,v,Lson);
	if (R>mid) update(L,R,v,Rson);
	pushup(rt);
	return;
}

void query(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R && color[rt]!=0) {
		st.insert(color[rt]);
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if (L<=mid) query(L,R,Lson);
	if (R>mid) query(L,R,Rson);
	pushup(rt);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2 && (n||m)) {
		char op;
		int a,b,c;
		getchar();
		build(1,n,1);
		// BUG;
	    rep(i,1,m) {
	    	// lookln(i);
	    	scanf("%c %d %d",&op,&a,&b);
	    	if (op=='P') {
	    		scanf("%d",&c);
	    		getchar();
	    		// cout << a << ' ' << b << ' ' << c << endl;
	    		update(a,b,c,Root);
	    	}
	    	else if (op=='Q') {
	    		getchar();
	    		st.clear();
	    		// cout << a << ' ' << b << endl;
	    		query(a,b,Root);
	    		set<int>::iterator it=st.begin();
	    		printf("%d",*it);
	    		it++;
	    		for (;it!=st.end();it++) {
	    			printf(" %d",*it);
	    		}
	    		puts("");
	    	}
	    }
	}
	return 0;
}