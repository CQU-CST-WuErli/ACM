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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
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
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;

struct Edge{
	int u,v,w;
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
};
vector<Edge> es;
int par[110];

int find(int x){
	if (par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void init(){
	for (int i=1;i<=n;i++) par[i]=i;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2 && (n||m)){
		for (int i=1;i<=m;i++){
			int u,v,cost;
			SIII(u,v,cost);
			es.push_back(Edge{u,v,cost});
		}
		sort(ALL(es));
//		for (int i=0;i<m;i++) cout << es[i].u << " " << es[i].v << ' ' << es[i].w << endl;
		int ans=INF;
		for (int L=0;L<m;L++){
			init();
			int tmp=0;
			for (int R=L;R<m;R++){
				int u=es[R].u,v=es[R].v;
				u=find(u);v=find(v);
				if (u!=v){
					tmp++;
					par[u]=v;
					if (tmp==n-1) {	
						ans=min(ans,abs(es[R].w-es[L].w)); 
						break;	
					}
				}
			}
		}
		if (ans>=INF) cout << "-1\n";
		else cout << ans << endl;
		es.clear();
	}
	return 0;
}


