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

int n,m;
int par[N],group[N];

void init() {
	for (int i=1;i<=n;i++) par[i]=i,group[i]=0;
}

int find(int x) {
	if (par[x]==x) return x;
	else {
		int fa=par[x];
		par[x]=find(par[x]);
		group[x]=(group[x]+group[fa])%2;
		return par[x];
	}
}

void unite(int x,int y) {
	int fx=find(x),fy=find(y);
	if (fx==fy) return;
	else {
		par[fx]=fy;
		group[fx]=(group[x]+group[y]+1)%2;
	}
} 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;cin >> T_T;
	while (T_T--) {
		SII(n,m);
		getchar();
		init();
		for (int i=1;i<=m;i++) {
			char op;
			int x,y;
			scanf("%c %d%d",&op,&x,&y);
			getchar();
//			cout << op << x << y << endl;
			if (op=='D') {
				unite(x,y);
			}
			else if (op=='A') {
				int fx=find(x),fy=find(y);
				if (fx!=fy) cout << "Not sure yet.\n";
				else {
					if (group[x]==group[y]) cout << "In the same gang.\n";
					else cout << "In different gangs.\n";
				} 
			}
		}
	} 
	return 0;
}

