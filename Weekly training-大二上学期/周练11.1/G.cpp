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
#define look(x) cout << #x << "=" << x
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

const int N=1e5+100;
int n,q;
int ans[N<<2];
vector<int> a; 

void push_up(int rt) {
	ans[rt]=min(ans[rt<<1],ans[rt<<1|1]);
}

void build(int l,int r,int rt) {
	if (l==r) {
		scanf("%d",&ans[rt]);
		a.push_back(ans[rt]);
		return;
	}
	int mid=(l+r)>>1;
	build(Lson);
	build(Rson);
	push_up(rt);
}

void update(int o,int v,int l,int r,int rt) {
	if (l==r) {
		ans[rt]=v;
		return;
	}
	int mid=(l+r)>>1;
	if (o<=mid) update(o,v,Lson);
	else update(o,v,Rson);
	push_up(rt);
}

int query(int L,int R,int l,int r,int rt) {
	if (L<=l && r<=R) {
		return ans[rt];
	}
	int ret=INF_INT;
	int mid=(l+r)>>1;
	if (L<=mid) ret=min(ret,query(L,R,Lson));
	if (R>mid) ret=min(ret,query(L,R,Rson));
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> q) {
		a.clear();
		a.push_back(-INF_INT);
		build(1,n,1);
		char s[50];
		while (q--) {
			scanf("%s",s);
			if (s[0]=='q') {
				int l=0,r=0;
				int flag=0;
				for (int i=0;s[i];i++) {
					if (s[i]=='(') {
						flag=1;
						continue;
					}
					if (s[i]==',') {
						flag=2;
						continue;
					}
					if (s[i]==')') {
						flag=0;
						continue;
					}
					if (flag==1) l=l*10+s[i]-'0';
					if (flag==2) r=r*10+s[i]-'0';
				}
				printf("%d\n",query(l,r,1,n,1));
			}
			else if (s[0]=='s') {
				int tmp=0;int flag=0;
				vector<int> pos;
				for (int i=0;s[i];i++) {
					if (s[i]=='(') {
						flag=1;
						continue;
					}
					if (s[i]==',') {
						pos.push_back(tmp);
						tmp=0;
						continue;
					}
					if (s[i]==')') {
						pos.push_back(tmp);
						tmp=0;
						continue;
					}
					if (flag) tmp=tmp*10+s[i]-'0';
				}
//				for (int i=0;i<pos.size();i++) cout << pos[i] << ' ';
//				puts("");
				int tt=a[pos[0]];
				for (int i=1;i<pos.size();i++) {
					update(pos[i-1],a[pos[i]],1,n,1);
				}
				update(pos[pos.size()-1],tt,1,n,1);
				for (int i=1;i<pos.size();i++) {
					a[pos[i-1]]=a[pos[i]];
				}
				a[pos[pos.size()-1]]=tt;
//				for (int i=1;i<a.size();i++) cout << a[i] << ' ';
//				puts("");
			}
		}
	}
	return 0;
}

