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

const int N=1e4+1e3;
int prime[N];
int is_prime[N];
int len;

void init(){
	len=0;
	CLR(is_prime);
	for (int i=2;i<=N;i++) if (!is_prime[i]){
		for (int j=i+i;j<=N;j+=i) is_prime[j]=1;
	}
	for (int i=2;i<=N;i++) if (!is_prime[i]) {
		prime[len++]=i;
	}
//	for (int i=0;i<10;i++) cout << prime[i] << endl;
}

int n;

int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	while (cin >> n ){
		int cnt=0;int l=0;
		vector<int> ans;
		ans.clear();
		while (prime[cnt]<=n){
			int p=prime[cnt];
			int tmp=p;
			while (tmp<=n){
				ans.push_back(tmp);
				tmp*=p;
				l++;
			}
			cnt++;
		}
		cout << l << endl;
		for (int i=0;i<ans.size();i++){
			if (i) cout << ' ';
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}

