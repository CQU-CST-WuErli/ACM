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

const int N=5e4+100;

int n,m;
int par[N],group[N];

// 0->same 1->x eat y 2->y eat x
void init() {
	for (int i=0;i<=n;i++) par[i]=i,group[i]=0;
}

int find(int x) {
	if (par[x]==x) return x;
	else {
		int fa=par[x];
		par[x]=find(par[x]);
		group[x]=(group[x]+group[fa])%3;
		return par[x];
	}
} 

void unite(int x,int y,int fx,int fy,int op) {
	par[fy]=fx;
	group[fy]=(3-group[y]+op-1+group[x])%3;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> n >> m ;
		int ans=0;
		init();
		for (int i=1;i<=m;i++) {
			int x,y,op;
			SIII(op,x,y);
			if (x>n || y>n) ans++;
			else if (x==y && op==2) ans++;
			else {
				int fx=find(x),fy=find(y);
				if (fx!=fy) unite(x,y,fx,fy,op);
				else {
					if (op==1 && group[x]!=group[y]) ans++;
					else if (op==2 && (group[y]+3-group[x])%3!=1) ans++;
				}
			}
		}
		cout << ans << endl;
	
	return 0;
}

