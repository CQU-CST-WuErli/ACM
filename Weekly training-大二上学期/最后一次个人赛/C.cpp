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

int n,l;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	for (int kase=scanf("%d",&_);kase<=_;kase++){
		SII(l,n);
		int start=0;
		int dir=1; // 1 ->  -1 <-
		int ans=0;
		priority_queue<int,vector<int>,greater<int> > q;  // ->
		priority_queue<int,vector<int>,less<int> > pq;    // <-
//		pq.push(1);pq.push(2);pq.push(3);
//		q.push(1);q.push(2);pq.push(3);
//		while (!pq.empty()){
//			cou << pq.top();
//			pq.pop();
//		}
//		while (!q.empty()){
//			cout << q.top();
//			q.pop();
//		}
		for (int i=1;i<=n;i++){
			int x;SI(x);
			if (!x){
				int pos;SI(pos);
				if (pos>=start) {
					q.push(pos);
				}
				else {
					pq.push(pos);
				}
			}
			else {
				if (!q.empty() && !pq.empty()){
					int lft=start-pq.top(),rig=q.top()-start;
					if (lft<rig){
						dir=-1;
						ans+=lft;
						start=pq.top();
						pq.pop();
					}
					else if (lft>rig){
						dir=1;
						ans+=rig;
						start=q.top();
						q.pop();
					}
					else if (lft==rig){
						if (dir==1) {
							ans+=lft;
							start=q.top();
							q.pop();
						}
						else if (dir==-1){
							ans+=rig;
							start=pq.top();
							pq.pop();
						}
					}
				}
				else if (!pq.empty() && q.empty()){
					dir=-1;
					ans+=start-pq.top();
					start=pq.top();
					pq.pop();
				}
				else if (pq.empty() && !q.empty()){
					dir=1;
					ans+=q.top()-start;
					start=q.top();
					q.pop();
				}
			}
		}
		cout << "Case " << kase << ": " ;
		cout << ans << endl;
	}
	return 0;
}

