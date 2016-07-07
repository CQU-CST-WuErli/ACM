//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=5e6+10;
int isprime[N];
ll prime[N];
int cnt;

ll q;

void init(){
	cnt=0;
	for (int i=2;i<N;i++)
		isprime[i]=1;
	prime[1]=0;
	for (int i=2;i<N;i++){
		if (!isprime[i]) continue;
		for (int j=2*i;j<N;j+=i) 
			isprime[j]=0;
		prime[cnt++]=i;
	}
}

bool check(ll num){
	if (num<N) return isprime[num];
	else {
		for (int i=0;prime[i]*prime[i]<=num;i++){
			if (num%prime[i]==0) return 0;
		}
		return 1;
	}
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	while (cin >> q){
		if (q==1 || check(q)) {
			printf("1\n0\n");
			continue;
		}
		else {
			vector<ll> ans;
			ll tmp=q;
			for (int i=0;i<cnt;i++){
				if (prime[i]>q) break;
				while (tmp%prime[i]==0){
					ans.push_back(prime[i]);
					tmp/=prime[i];
					if (ans.size()==2) break;
				}
				if (ans.size()==2) break;
			}
			if (tmp!=1 && ans.size()>=2) {
				cout << 1 << endl;
				cout << ans[0]*ans[1] << endl;
			} 
			else {
				cout << 2 << endl;
			}
		}
	}
	return 0;
}


