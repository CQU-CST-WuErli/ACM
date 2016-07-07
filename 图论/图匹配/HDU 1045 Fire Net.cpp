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

char mp[5][5];
int mpr[30][30],mpl[30][30];
int link[30][30]; 
int used[30],match[30];
int n;
int row,col;

bool find(int x) {
	for (int i=1;i<=col;i++) {
		if (link[x][i] && !used[i]) {
			used[i]=1;
			if (match[i]==-1 || find(match[i])) {
				match[i]=x;
				return true;
			}
		}
	}
	return false;
}

int hungary() {
	int ret=0;
	OFF(match);
	for (int i=1;i<=row;i++) {
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
	while (cin >> n && n) {
		getchar();
		CLR(mpl);CLR(mpr);CLR(mp);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				cin >> mp[i][j];
				if (mp[i][j]=='X')
					mpr[i][j]=mpl[i][j]=-1;
			}
		}
		row=col=0;
		int tmp1=0;
		int i,j;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				while (mpr[i][j]==-1 && j<=n) j++;
				tmp1++;
				while (mpr[i][j]!=-1 && j<=n) {
					mpr[i][j]=tmp1;
					if (row<tmp1) row=tmp1;
					j++;
				}
			}
		}
		int tmp2=0;
		for (j=1;j<=n;j++) {
			for (i=1;i<=n;i++) {
				while (mpl[i][j]==-1 && i<=n) i++;
				tmp2++;
				while (mpl[i][j]!=-1 && i<=n) {
					mpl[i][j]=tmp2;
					if (col<tmp2) col=tmp2;
					i++;
				}
			}
		}
		CLR(link);
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (mpr[i][j]!=-1 && mpl[i][j]!=-1)
					link[mpr[i][j]][mpl[i][j]]=1;
			}
		}
		int ans=hungary();
		cout << ans << endl;
	}
	return 0;
}

