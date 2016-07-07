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

const int N=110000;

int par[N],rnk[N];
map<int,int> mp1;
map<string,int> mp2;
int ID_int,ID_str;
set<int> st[N];
int n;
set<int>::iterator it;

void init() {
	for (int i=0;i<n;i++) {
		par[i]=i;
		rnk[i]=0;
		st[i].clear();
	}
	mp1.clear();mp2.clear();
} 
int get_id(int x) {
	if (!mp1[x]) mp1[x]=ID_int++;
	return mp1[x];
}

int get_id(string &s) {
	if (!mp2[s]) mp2[s]=ID_str++;
	return mp2[s];
}

int find(int x) {
	if (par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y) {
	x=find(x);y=find(y);
	if (rnk[x]<rnk[y]) {
		par[x]=y;
		for (it=st[x].begin();it!=st[x].end();it++) st[y].insert(*it);
	}
	else {
		par[y]=x;
		for (it=st[y].begin();it!=st[y].end();it++) st[x].insert(*it);
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		getchar();
		ID_int=ID_str=1;
		init();
		string s,t;
		for (int i=1;i<=n;i++) {
			cin >> s;
			if (s[0]=='a') {
				cin >> t;
				int ID=get_id(t);
				int x;SI(x);
				while (x--) {
					int tmp;SI(tmp);
					st[ID].insert(get_id(tmp));
				}
				getchar();
			}
			else if (s[0]=='s') {
				cin >> t;
				int x=get_id(t);
				cin >> t;
				int y=get_id(t);
				unite(x,y);				
			}
			else if (s[0]=='c') {
				cin >> t;
				int ID=get_id(t);
				int ans=st[find(ID)].size();
				printf("%d\n",ans);
			} 
		}
	}
	return 0;
}

