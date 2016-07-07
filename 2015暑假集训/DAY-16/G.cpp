//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
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
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=1e6+10;


struct P{
	int q,d;
}a[N];

int t;
int n;

bool cmp(const P& a,const P& b){
	return a.d<b.d;
}

struct CMP{
	bool operator () (const P& a,const P& b){
		return a.q<b.q;
	}
}; 
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	while (t--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
			scanf("%d%d",&a[i].q,&a[i].d);
		int ans=0;
		sort(a+1,a+1+n,cmp);
		priority_queue<P,vector<P>, CMP> pq;
		ll tmp=0;
		for (int i=1;i<=n;i++){
			tmp+=a[i].q;
			pq.push(a[i]);
			ans++;
			if (tmp>a[i].d){
				P x=pq.top();pq.pop();
				tmp-=x.q;
				ans--;
			}
		}
		cout << ans << endl;
		if (t) cout << endl; 
	}
	return 0;
}


