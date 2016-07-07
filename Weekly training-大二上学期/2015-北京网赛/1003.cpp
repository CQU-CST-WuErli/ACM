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

const int N=7e6;
int dp[N];
int vis[N];
int n;

void init() {
	CLR(vis);
	queue<int> q;
	MEM(dp,INF_INT);
	int x=0;
	for (int i=1;i<=7;i++) {
		x=x*10+i;
		q.push(x);
		lookln(x);
		vis[x]=1;
		dp[x]=0;
	}
	while (!q.empty()) {
		int x=q.front();q.pop();
		int a[10];int cnt=1;
		while (x) {
			a[cnt++]=x%10;
			x/=10;
		} 
		reverse(a+1,a+cnt);
		int top[10];OFF(top);
		for (int i=1;i<cnt;i++) {
			top[a[i]]=max(top[a[i]],i);
		}
		for (int i=1;i<cnt;i++) {
			int tmp[10];
			memcpy(tmp,a,sizeof(a));
			if (i<cnt-1) {
				if (top[i]<top[i+1])tmp[top[i]]=i+1;	
				int tt=0;
				for (int i=cnt-1;i>=1;i--) {
					tt=tt*10+tmp[i];
				}
				if (vis[tt]==0) {
					q.push(tt);
					vis[tt]=1;
					dp[tt]=dp[x]+1;
				}
			}
			memcpy(tmp,a,sizeof(a));
			if (i>1) {
				if (top[i]<top[i-1]) tmp[top[i]]=i-1;
				int tt=0;
				for (int i=cnt-1;i>=1;i--) {
					tt=tt*10+tmp[i];
				}
				if (vis[tt]==0) {
					q.push(tt);
					vis[tt]=1;
					dp[tt]=dp[x]+1;
				}
			}
		}
	}
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;cin >> _;
	init();
	while (_--) {
		cin >> n;
		int A[10],num[10];
		for (int i=1;i<=n;i++) {
			cin >> A[i];
		}
		sort(A+1,A+1+n);
		map<int,int> mp;
		for (int i=1;i<=n;i++) mp[A[i]]=i;
		for(int i=1;i<=n;i++)A[i]=mp[A[i]];
		int t=0;
		for(int i=1;i<=n;i++){
			t += pow(10,A[i]-1)*A[i];
		}
		int ans;
		if (dp[t]==INF_INT) ans=-1;
		else ans=dp[t];
		cout << ans << endl;
	}
	return 0;
}

