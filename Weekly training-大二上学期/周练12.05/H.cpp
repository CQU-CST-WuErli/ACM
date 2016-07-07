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
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

const int N=3e5+110;

int cor[N<<2];
int cover[N<<2];
int n;
int li[10010],ri[10010];
int Hash[N<<2];
set<int> st;

void push_down(int rt) {
	if (cover[rt]!=-1) {
		cover[rt<<1]=cover[rt<<1|1]=cover[rt];
		cor[rt<<1]=cover[rt];
		cor[rt<<1|1]=cover[rt];
		cover[rt]=-1;
	}
}

void build(int l,int r,int rt) {
	cover[rt]=-1;
	cor[rt]=0;
	if (l==r) {
		return;
	}
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
}

void update(int L,int R,int v,int l,int r,int rt) {
	if (L<=l && r<=R) {
		cor[rt]=v;
		cover[rt]=v;
		return;
	}
	push_down(rt);
	int mid=(l+r)>>1;
	if (L<=mid) update(L,R,v,Lson);
	if (R>mid) update(L,R,v,Rson);
}

void query(int L,int R,int l,int r,int rt) {
	if (l==r) {
		if (cor[rt]) st.insert(cor[rt]);
		return;
	}
	push_down(rt);
	int mid=(l+r)>>1; 
	if (L<=mid) query(L,R,Lson);
	if (R>mid) query(L,R,Rson);
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;SI(T_T);
	while (T_T--) {
		int cnt=0;
		cin >> n;
		for (int i=1;i<=n;i++) {
			scanf("%d%d",li+i,ri+i);
			Hash[cnt++]=li[i];
			Hash[cnt++]=ri[i];
		}
		sort(Hash,Hash+cnt);
		cnt=unique(Hash,Hash+cnt)-Hash;
		sort(Hash,Hash+cnt);
		int tmp=cnt;
		for (int i=cnt-1;i>=1;i--) {
			if (Hash[i-1]+1!=Hash[i]) Hash[tmp++]=Hash[i-1]+1;
		}
		cnt=tmp;
		sort(Hash,Hash+cnt);
//		for (int i=0;i<cnt;i++) {
//			cout << Hash[i] << ' ';
//		}
//		puts("");

		build(1,cnt,1);
		for (int i=1;i<=n;i++) {
			int l,r;
			l=lower_bound(Hash,Hash+cnt,li[i])-Hash+1;
			r=lower_bound(Hash,Hash+cnt,ri[i])-Hash+1;
//			cout << "l=" << l << " r=" << r << endl;
			update(l,r,i,1,cnt,1);
		}
		st.clear();
		query(1,cnt,1,cnt,1);
		cout << st.size() << endl;
	}
	return 0;
}

