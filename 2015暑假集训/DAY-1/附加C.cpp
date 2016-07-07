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
void BUG(int _testnumber){
	printf("I am in line %d\n",_testnumber);
}
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


typedef pair<int,int> P;
P l[6];
int vis[6];

bool cmp(P a,P b){
	return (a.first==b.first && a.second==b.second);
}

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int a,b;
	while (cin >> a >> b){
		CLR(vis);
		l[0].first=min(a,b);l[0].second=max(a,b);
		bool ans=true;
		for (int i=1;i<6;i++){
			cin >> a >> b;
			l[i].first=min(a,b);
			l[i].second=max(a,b);
		}
		vis[0]=1;
		int flag=0;
		for (int i=1;i<6;i++){
			if (cmp(l[0],l[i])){
				vis[i]=1;
				flag=1;
				break;
			}
		}
		int tmp=l[0].first;int ccnt;int po;
		for (int i=1;i<6;i++){
			if (vis[i]) continue;
			if (l[0].first==l[i].first || l[0].first==l[i].second){
				ccnt=i;
				vis[i]=1;
				if (flag) flag=1;
				if (l[0].first==l[i].first) po=1;
				else po=2;
				break;
			}
		}
		P tem;
		tem.first=min(l[0].second,(po==1?l[ccnt].second:l[ccnt].first));
		tem.second=max(l[0].second,(po==1?l[ccnt].second:l[ccnt].first));
		int cccnt;
		for (int i=0;i<6;i++){
			if (!vis[i] && cmp(tem,l[i])){
				cccnt=i;
				vis[i]=1;
				if (flag) flag=1;
				break;
			}
		}
		int fflag=0;
		for (int i=0;i<6;i++){
			if (!vis[i] && cmp(l[cccnt],l[i])){
				fflag=1;
			}
		}
		if (!fflag) flag=0;
		if (!flag) ans=false;
		if (ans) cout << "POSSIBLE\n";
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}


