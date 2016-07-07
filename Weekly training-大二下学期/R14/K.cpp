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

#define Root 1,n,1
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1

const int N=2e6;
int sum[N<<2];
int cover[N<<2];
int n;
string s;

void pushup(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	if (cover[rt<<1]==cover[rt<<1|1] && cover[rt<<1]!=-1) cover[rt]=cover[rt<<1];
	else cover[rt]=-1;
}

void pushdown(int l,int r,int rt) {
	if (cover[rt]!=-1) {
		int mid=(l+r)>>1;
		sum[rt<<1]=(mid-l+1)*cover[rt];
		sum[rt<<1|1]=(r-mid)*cover[rt];
		cover[rt<<1]=cover[rt<<1|1]=cover[rt];
		cover[rt]=-1;
	}
}

void build(int l,int r,int rt) {
	if (l==r) {
		sum[rt]=s[l]-'0';
		cover[rt]=sum[rt];
		return;
	}
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
	pushup(rt);
}

void update(int L,int R,int v,int l,int r,int rt) {
	if (L<=l && r<=R && !(v==-1 && cover[rt]==-1)) {
		if (v==-1) cover[rt]^=1;
		else cover[rt]=v;
		sum[rt]=(r-l+1)*cover[rt];
		return;
	}
	pushdown(l,r,rt);
	int mid=(l+r)>>1;
	if (L<=mid) update(L,R,v,Lson);
	if (R>mid) update(L,R,v,Rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return sum[rt];
	}
	pushdown(l,r,rt);
	int mid=(l+r)>>1;
	int ret=0;
	if (L<=mid) ret+=query(L,R,Lson);
	if (R>mid) ret+=query(L,R,Rson);
	pushup(rt);
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	int x;SI(x);
    	s="@";
    	while(x--) {
    	    int num;SI(num);
    	    string tmp;cin >> tmp;
    	    while(num--) s+=tmp;
    	}
    	n=s.size()-1;
    	build(Root);
    	int m;SI(m);
    	char op;
    	int a,b;
    	int qCase=1;
    	cout << "Case " << kase << ":\n";
    	while(m--) {
    		cin >> op >> a >> b;
    		a++,b++;
    		if (op=='F') {
    			update(a,b,1,Root);
     		}
    		else if (op=='E') {
    			update(a,b,0,Root);
    		}
    		else if (op=='I') {
    			update(a,b,-1,Root);
    		}
    		else if (op=='S'){
    			cout << "Q" << qCase++ << ": " << query(a,b,Root) << endl;
    		}
    	}
    }
	return 0;
}