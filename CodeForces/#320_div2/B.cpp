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

int n;
int vis[850];
int team[850];

struct P{
	int id;
	int val;
};

struct cmp{
	bool operator () (const P& a,const P& b) const {
		return a.val<b.val;
	}
};

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		
		priority_queue<P,vector<P>,cmp> q[810],pq;
		pq.push(P{1,22});pq.push(P{2,11});pq.push(P{3,44});
		for (int i=2;i<=2*n;i++){
			for (int j=1;j<i;j++){
				int x;
				scanf("%d",&x);
				q[i].push(P{j,x});
				q[j].push(P{i,x});
			}
		}	
//		for (int i=1;i<=2*n;i++) {
//			while (q[i].size()){
//				P tmp=q[i].top();q[i].pop();
//				cout << tmp.id << " ";
//			}
//			cout << endl;
//		}	
		queue<int> qq;
		for (int i=1;i<=2*n;i++) {
			qq.push(i);
		}
		CLR(vis);
		while (!qq.empty()){ 
			int x=qq.front();qq.pop();
			if (vis[x]) continue;
			P tmp=q[x].top();
			while (vis[tmp.id]) {
				q[x].pop();
				tmp=q[x].top();
			}
			int y=tmp.id;
			int tt=q[y].top().id;
			while (vis[tt]) {
				q[y].pop();
				tt=q[y].top().id;
			}
			if (x==tt) {
				team[x]=y;
				team[y]=x;
				vis[x]=1;vis[y]=1;
			}
			else {
				qq.push(x);
				q[x].push(tmp);
			}
		}
		for (int i=1;i<=2*n;i++) cout << team[i] << ' ';
		puts("");
	}
	return 0;
}

