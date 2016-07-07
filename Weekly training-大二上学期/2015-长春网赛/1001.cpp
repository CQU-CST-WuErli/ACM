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

struct P{
	char name[210];
	int val;
	int ti;
}per[150100];

struct cmp{
	bool operator () (const P &a, const P &b) const {
		if (a.val==b.val) return a.ti>b.ti;
		else return a.val<b.val;
	}
};

struct In{
	int t,num;
	bool operator < (const In &rhs) const {
		return t<rhs.t;
	}
}in[150100];
int k,m,Q;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T;
	cin >> T;
	while (T--){
		cin >> k >> m >> Q;
		getchar();
		for (int j=1;j<=k;j++) {
			scanf("%s",per[j].name);
			scanf("%d",&per[j].val);
			per[j].ti=j;
//			printf("%s ",per[i].name);
//			cout << per[i].val << ' ' << per[i].ti << endl;
		}
		
		priority_queue<P,vector<P>,cmp> q;
		vector<int> v;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&in[i].t,&in[i].num);
		}
		sort(in+1,in+1+m);
//		for (int i=1;i<=m;i++) cout << in[i].t << ' ' << in[i].num << endl;
		int pos=1;int POS=0;
		for (int i=1;i<=m;i++){
			for (;pos<=in[i].t;pos++) {
				q.push(per[pos]);
			}
			int cnt=0;
			while (q.size() && cnt<in[i].num){
				P x=q.top();q.pop();
				v.push_back(x.ti);
				cnt++;
			}
		}
		for (;pos<=k;pos++) q.push(per[pos]);
		while (!q.empty()){
			P x=q.top();q.pop();
			v.push_back(x.ti);
		}
		for (int i=1;i<=Q;i++) {
			int x;scanf("%d",&x);
			printf("%s",per[v[x-1]].name);
			if (i<Q) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}

