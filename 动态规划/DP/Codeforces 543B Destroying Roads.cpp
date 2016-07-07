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
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=3010;

vector<int> g[N];
int n,m;
int s1,t1,l1,s2,t2,l2;
int d[N][N],vis[N];


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2) {
		rep(i,0,n) g[i].clear();
		rep(i,1,m) {
			int u,v;
			SII(u,v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		SIII(s1,t1,l1);
		SIII(s2,t2,l2);
		MEM(d,INF_INT);
		rep(i,1,n) {
			CLR(vis);
			queue<int> q;
			q.push(i);
			vis[i]=1;
			d[i][i]=0;
			while (!q.empty()) {
				int x=q.front();q.pop();
				for (int j=0;j<g[x].size();j++) {
					int v=g[x][j];
					if (d[i][v]>d[i][x]+1) {
						d[i][v]=d[i][x]+1;
						if (!vis[v]) {
							vis[v]=1;
							q.push(v);
						}
					}
				}
			}
		}
		if (d[s1][t1]>l1 || d[s2][t2]>l2) {
			cout << -1 << endl;
		}
		else {
			int ans=d[s1][t1]+d[s2][t2];
			rep(i,1,n) rep(j,1,n) {
				if (d[s1][i]+d[i][j]+d[j][t1]<=l1 && d[s2][i]+d[i][j]+d[j][t2]<=l2)
					ans=min(ans,d[s1][i]+d[s2][i]+d[i][j]+d[j][t1]+d[j][t2]);
				if (d[s1][i]+d[i][j]+d[j][t1]<=l1 && d[t2][i]+d[i][j]+d[j][s2]<=l2) 
					ans=min(ans,d[s1][i]+d[t2][i]+d[i][j]+d[j][t1]+d[j][s2]);
			}
			cout << m-ans << endl;
		}
	}
	return 0;
}

