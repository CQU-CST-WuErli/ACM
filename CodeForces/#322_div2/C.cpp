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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct P{
	int v;
	int d;
	int id;
};
P a[100100];
int n,k;

struct cmp {
	bool operator () (P& a,P& b) const {
		return a.d>b.d;
	}
};

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> k) {
		priority_queue<P,vector<P>,cmp> pq;
		int ans=0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i].v);
			a[i].d=(a[i].v/10+1)*10-a[i].v;
			a[i].id=i;
			pq.push(a[i]);
			ans+=a[i].v/10;
		}
//		for (int i=1;i<=n;i++) cout << a[i].v << ' ' << a[i].d << endl;
//		while (!pq.empty()) {
//			cout << pq.top().v << endl;
//			pq.pop();
//		}
		while (!pq.empty() && k) {
			P x=pq.top();pq.pop();
			if (x.v%10 ==0) break;
			int tmp=(x.v/10+1)*10-x.v;
			if(k>=tmp) {
				ans++;
				k-=tmp; 
//				lookln(tmp);
				a[x.id].v+=tmp;
			}			
		}
//		for (int i=1;i<=n;i++) cout << a[i].v << endl;
		if (k) {
			for (int i=1;i<=n;i++) {
				int tmp=100-a[i].v;
				if (k>=tmp) {
					k-=tmp;
					ans+=(tmp/10);
				}
				else {
					ans+=(k/10);
					break;
				} 
			}
		}
		cout << ans << endl;
	}
	return 0;
}

