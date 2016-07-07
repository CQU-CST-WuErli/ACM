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
template <typename T> T max(T &a,T &b) {return a>b?a:b;}
template <typename T> T min(T &a,T &b) {return a<b?a:b;}
using namespace std;

const int N=110;

struct P{
	int x,y;
	bool operator < (const P& rhs) const {
		return y<rhs.y;
	}
};
P p[N];
int n,w,k;
int dp[N][N];
int num[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		CLR(dp);
		cin >> n >> w >> k;
		for (int i=1;i<=n;i++) cin >> p[i].x >> p[i].y;
		sort(p+1,p+1+n);
		for (int i=1;i<=n;i++) {
			int tmp=0;
			for (int j=i;j<=n;j++) {
				if (p[i].y+w>=p[j].y && p[i].y<=p[j].y) tmp++;
			}
			num[i]=tmp;
			dp[1][i]=tmp;
		}
//		for (int i=1;i<=n;i++) cout << num[i] << ' '<< endl;
		// i´Î j¸öµã 
		int ans=0;
		for (int i=1;i<=k;i++) {
			for (int j=1;j<=n;j++) {
				for (int s=1;s<j;s++) if (p[s].y+w<p[j].y) {
					dp[i][j]=max(dp[i][j],dp[i-1][s]+num[j]); 
				}
			}
		}
		for (int i=1;i<=k;i++) for (int j=1;j<=n;j++) ans=max(ans,dp[i][j]);
		cout <<"Case " << kase << ": " <<  ans << endl;
	}
	return 0;
}

