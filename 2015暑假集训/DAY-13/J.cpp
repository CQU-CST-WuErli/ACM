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

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int n;
	while (cin >> n && n){
		priority_queue<int,vector<int>,greater<int> > pq;
		ll ans=0;
		ll x;
		for (int i=0;i<n;i++) {
			cin >> x;
			pq.push(x);
		} 
		while (!pq.empty()){
			ll a=pq.top();pq.pop();
			ll b=pq.top();pq.pop();
			ll tmp=a+b;
//			cout << "a=" << a <<" b=" << b << " ";
//			look(tmp);
			ans+=tmp;
			if (pq.empty())  break;
			pq.push(tmp);
		}
		cout << ans << endl;
	}
	return 0;
}


