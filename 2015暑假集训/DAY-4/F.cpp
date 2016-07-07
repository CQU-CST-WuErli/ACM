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
typedef pair<double,double> P;
P dot[1100];

bool cmp(P a,P b){
	return a.first<b.first;
}

int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	cin >> T;
	for (int t=0;t<T;t++ ){
		int n;
		cin >> n;
		for (int i=0;i<n;i++)
			cin >> dot[i].first >> dot[i].second;
		sort(dot,dot+n);
	//	for (int i=0;i<n;i++) cout << dot[i].first << " " << dot[i].second << endl;
		double mid=(double)dot[0].first+(double)dot[n-1].first;
		mid=mid/2.00;
	//	cout << mid << endl;
		map<P,int> mp;
		for (int i=0;i<n;i++){
			if (dot[i].first==mid) continue;
			P tmp;
			tmp.first=abs(dot[i].first-mid);
			tmp.second=dot[i].second;
			if (!mp.count(tmp)) mp[tmp]=1;
			else mp[tmp]++;
	//		cout << tmp.first << " " << tmp.second << endl;
		}
		int flag=1;
		for (map<P,int>::iterator it=mp.begin();it!=mp.end();it++){
			if (it->second % 2){
				flag=0;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	} 
	return 0;
}


