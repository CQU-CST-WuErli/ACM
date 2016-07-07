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
#define For_UVa if (kase!=1) cout << endl
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

int ans[20];
int vis[5000];
int cnt;
int k;

void dfs(int sta) {
	int s1=(sta<<1)&((1<<k)-1);
	int s2=s1+1;
	if (!vis[s1]) {
		vis[s1]=1;
		dfs(s1);
		ans[++cnt]=0;
	}
	if (!vis[s2]) {
		vis[s2]=1;
		dfs(s2);
		ans[++cnt]=1;
	}
}

int main(int argc, char const *argv[]) {
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (SI(k)==1) {
		printf("%d ",1<<k);
		CLR(vis);
		cnt=0;
		dfs(0);
		rep(i,1,k-1) cout << 0;
		Rep(i,cnt,k) cout << ans[i];
		cout << endl;
	}
	return 0;
}