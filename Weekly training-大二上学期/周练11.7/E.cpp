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

const int N=200;
int mp[N][N];
int used[N],match[N];
int n,m;
int a[N],b[N];

bool find(int x) {
	for (int i=1;i<=m;i++) {
		if (mp[x][i] && !used[i]) {
			used[i]=1;
			if (match[i]==0 || find(match[i])) {
				match[i]=x;
				return true;
			}
		}
	}
	return false;
}

int hungary() {
	CLR(match);
	int ret=0;
	for (int i=1;i<=n;i++) {
		CLR(used);
		if (find(i)) ret++;
	}
	return ret;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		cin >> n;
		for (int i=1;i<=n;i++) cin >> a[i];
		cin >> m;
		for (int i=1;i<=m;i++) cin >> b[i];
		CLR(mp);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (a[i]==0 && b[j]==0) mp[i][j]=1;
				else if (a[i]!=0 && b[j]%a[i]==0) mp[i][j]=1;
			}
		}
		printf("Case %d: %d\n",kase,hungary());
	}
	return 0;
}

