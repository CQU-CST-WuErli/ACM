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
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef unsigned long long  ll;
using namespace std;
queue<ll> q;
vector<ll> vc;

void init(){
	q.push(4);
	q.push(7);
	vc.push_back(4);
	vc.push_back(7);
	while(!q.empty()){	
		ll x=q.front();q.pop();
		if (x>1e10) break;
		vc.push_back(x*10+4);
		vc.push_back(x*10+7);
		q.push(x*10+4);
		q.push(x*10+7);
	}
	sort(vc.begin(),vc.end());
}

ll l,r;
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
//	for (int i=0;i<vc.size();i++) cout << vc[i] << endl;
	while (cin >> l >> r ){
		int lcnt=0,rcnt=0;
		ll ans=0;
		int lv=vc.size();
		while (vc[lcnt]<l) lcnt++;
		while (vc[rcnt]<r) rcnt++;
		int tmp=l;
		for (int i=lcnt;i<=rcnt;i++) {
			ans+=(min(vc[i],r)-tmp+1)*vc[i];
			tmp=vc[i]+1;
		}
		cout << ans << endl;
	}
	return 0;
}


