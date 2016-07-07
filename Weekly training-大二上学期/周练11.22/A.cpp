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
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
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

const int N=1e5+100;

int lch[N],rch[N];
int par[N];
int n;
int h[N];
int dep[N];
int dp[N];
int lshift,rshift;

int dfs(int u,int d) {
	dep[u]=d;
	if (!u) return h[u]=0;
	h[u]=max(dfs(lch[u],d+1),dfs(rch[u],d+1))+1;
	return h[u];	
}

void DP(int u,int hl,int hr,int dl,int dr) {
	if (!u) return;
	int dL=h[lch[u]];
	int dR=h[rch[u]];
	dp[u]=1+max(max(hl,hr),max(dL+dl,dR+dr));
	DP(lch[u],hl,max(hr,dr+dR+1),dl,dr+1);
	DP(rch[u],max(hl,dL+dl+1),hr,dl+1,dr); 
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		CLR(lch);CLR(rch);CLR(par);
		rep(i,1,n) {
			int l,r;
			SII(l,r);
			lch[i]=l;
			rch[i]=r;
			par[l]=par[r]=1;
		}
		int root;
		rep(i,1,n) if (par[i]==0) {
			root=i;break;
		}
		dfs(root,0);
		lshift=rshift=0;
		DP(root,0,0,0,0);
		rep(i,1,n) cout << dp[i] << endl;
	}
	return 0;
}

