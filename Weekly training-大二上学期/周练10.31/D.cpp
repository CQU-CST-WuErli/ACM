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

int n,m;
int w[1010][1010];

int Lx[1010],Ly[1010];
int match[1010];
int S[1010],T[1010];
int slack[1010];
 
bool find(int i) {
	S[i]=1;
	for (int j=1;j<=n;j++) if (!T[j]) {
		if (Lx[i]+Ly[j]==w[i][j]) {
			T[j]=1;
			if (!match[j] || find(match[j])) {
				match[j]=i;
				return true;
			}
		}
		else slack[j]=min(slack[j],Lx[i]+Ly[j]-w[i][j]);
	}
	return false;
}

bool update() {
	int a=INF_INT;
	for (int i=1;i<=n;i++)  if (S[i]){
		for (int j=1;j<=n;j++) if (!T[j]) {
			a=min(a,slack[j]);
		}
	}
	if (a>=INF_INT) return false;
	for (int i=1;i<=n;i++) {
		if (S[i]) Lx[i]-=a;
		if (T[i]) Ly[i]+=a;
		else slack[i]-=a;
	}
	return true;
}

int KM() {
	for (int i=1;i<=n;i++) {
		match[i]=Ly[i]=0;
		Lx[i]=-INF_INT;
		for (int j=1;j<=n;j++)
			Lx[i]=max(Lx[i],w[i][j]);
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) slack[j]=INF_INT;
		for (;;) {
			for (int j=1;j<=n;j++) S[j]=T[j]=0;
			if (find(i)) break;
			else if (!update()) return -1;		
		}
	}
	int ret=0;
	for (int i=1;i<=n;i++) if (match[i]==0 || w[match[i]][i]==-INF_INT) return -1;
	else ret+=w[match[i]][i];
	return -ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		cin >> n >> m;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) w[i][j]=INF_INT;
		for (int i=1;i<=m;i++) {
			int u,v,c;
			SIII(u,v,c);
			w[u][v]=w[v][u]=min(w[u][v],c);
		}
		for(int i=1; i<=n; i++)  
            for(int j=1; j<=n; j++) w[i][j]=-w[i][j];
		int ans=KM();
		cout << "Case " << kase << ": ";
		if (ans==-1) cout << "NO\n";
		else cout << ans << endl;
	}
	return 0;
}

