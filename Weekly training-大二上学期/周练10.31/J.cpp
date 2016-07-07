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

const int N=100100;
int n,q;
int a[N];
int value[N],counter[N],num[N],lft[N],rig[N];

int ans[N<<2];

void push_up(int rt) {
	ans[rt]=max(ans[rt<<1],ans[rt<<1|1]);
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
	int mid=(l+r)>>1;
	int ret=-1;
	if (L<=mid) ret=max(ret,query(L,R,Lson));
	if (R>mid) ret=max(ret,query(L,R,Rson));
	return ret; 
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> q) {
		for (int i=1;i<=n;i++) scanf("%d",a+i);
		int cnt=0;
		CLR(counter);value[cnt]=INF_INT; 
		for (int i=1;i<=n;i++) {
			if (a[i]!=value[cnt]) {
				cnt++;
				value[cnt]=a[i];
				counter[cnt]++;
			}
			else counter[cnt]++;
			num[i]=cnt;
		}
		lft[1]=1;
		for (int i=2;i<=n;i++) {
			if (a[i]!=a[i-1]) lft[i]=i;
			else lft[i]=lft[i-1];
		}
		rig[n]=n;
		for (int i=n-1;i>=1;i--) {
			if (a[i]!=a[i+1]) rig[i]=i;
			else rig[i]=rig[i+1];
		}
//		for (int i=1;i<=cnt;i++) cout << value[i] << ' ' << counter[i] << endl;
//		puts("---------------");
//		for (int i=1;i<=n;i++) {
//			printf("%d %d %d\n",num[i],lft[i],rig[i]);
//		}
		for (int i=1;i<=cnt;i++) {
			update(i,counter[i],1,cnt,1);
		}
		while (q--) {
			int l,r;
			SII(l,r);
			if (num[l]==num[r]) cout << r-l+1 << endl;
			else {
				int a=rig[l]-l+1;
				int b=r-lft[r]+1;
				int c=-INF_INT;
				if (rig[l]+1<=lft[r]-1) {
					c=query(num[rig[l]+1],num[lft[r]-1],1,cnt,1);
				}
				cout << max(a,max(b,c)) << endl;
			}
		}
	}
	return 0;
}

