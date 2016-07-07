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
#include <assert.h>
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
#define null NULL
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=200;

int link[N][N];
int color[N][N];
char mp[N][N];
int n; 
int used[N],match[N];

int outd[N],ind[N];

int dfs(int x) {
	for (int i=1;i<=n;i++) if (link[x][i] && !used[i]) {
		used[i]=1;
		if (match[i]==-1 || dfs(match[i])) {
			match[i]=x;
			return 1;
		}
	}
	return 0;
}

int hungary(int cnt) {
	OFF(match);
	int ret=0;
	for (int i=1;i<=n;i++) {
		CLR(used);
		dfs(i);
	}
	for (int i=1;i<=n;i++) if (match[i]!=-1) {
		link[match[i]][i]--;
		if (mp[match[i]][i]=='*') color[match[i]][i]=cnt;
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;SI(t);
	while (t--) {
		SI(n);
		getchar();
		CLR(link);CLR(color);CLR(mp);
		CLR(ind);CLR(outd);
		int ans=0;
		for (int i=1;i<=n;i++) {
			int tot=0;
			for (int j=1;j<=n;j++) {
				cin >> mp[i][j];
				if (mp[i][j]=='*') {
					link[i][j]=1;
					outd[i]++;
					ind[j]++;
				}
			}
		}
		for (int i=1;i<=n;i++) ans=max(ans,max(outd[i],ind[i]));
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n && outd[i]<ans;j++) {
				while (outd[i]<ans && ind[j]<ans) {
					outd[i]++;
					ind[j]++;
					link[i][j]++;
				}
			}
		}
		cout << ans << endl;
		for (int i=1;i<=ans;i++) hungary(i);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				cout << color[i][j];
				if (j<n) cout << ' ';
				else cout << '\n';
			}
		}
	}
	return 0;
}

