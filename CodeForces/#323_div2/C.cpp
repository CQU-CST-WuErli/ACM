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
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int a[505*505];
std::vector<int> v;
map<int,int> mp;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	int n;cin >> n;
	for(int i=1;i<=n*n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n*n);
	v.push_back(a[n*n]);
	v.push_back(a[n*n-1]);
	mp[gcd(a[n*n],a[n*n-1])]++;
	int cnt = 2;
	int pos = n*n-2;
	while(cnt < n){
		for(int i=pos;i>=1;i--){
			if(mp[a[i]])mp[a[i]]--;
			else{
				pos = i-1;
				cnt++;
				for(int j=0;j<v.size();j++){
					//cout << gcd(v[j],a[i]) << endl;
					mp[gcd(v[j],a[i])]++;
				}
				mp[a[i]]++;
				v.push_back(a[i]);
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout << v[i] << ' ';
	}
	return 0;
}

