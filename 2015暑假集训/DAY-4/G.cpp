//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
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
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int T;
typedef pair<int,bool> P;

P prio[110];
int vis[110];
int n,m;

struct cmp{
	bool operator () 
		(const P a, const P b) const {
			return a.first<b.first;
		}
	
};
int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	cin >> T;
	for (int t=0;t<T;t++){
		priority_queue< P, vector<P>, cmp > pq;
		queue<P> q;
		cin >> n >> m;
		int tot=0,cnt=0;
		for (int i=0;i<n;i++){
			cin >> prio[i].first;
			if (i!=m) prio[i].second=false;
			else prio[i].second=true;
			q.push(prio[i]);
			pq.push(prio[i]);
		}
		while (1){
			P qx=q.front();q.pop();
			P pqx=pq.top();
			if (qx.first<pqx.first){
				q.push(qx);
			}
			else if (qx.first==pqx.first){
				tot++;
				pq.pop();
				if (qx.second) break;
			}
		}
		cout << tot << endl;
	} 
	return 0;
}


