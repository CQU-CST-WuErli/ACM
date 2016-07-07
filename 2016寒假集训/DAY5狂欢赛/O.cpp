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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int m;
vector<int> pro;
vector<int> arc[11];
map<string,int> mp;
int idx;

void init() {
	pro.clear();
	for (int i=0;i<11;i++) arc[i].clear();
	mp.clear();
	idx=1;
}

int get(string& s) {
	if (!mp.count(s)) mp[s]=idx++;
	return mp[s];
}

void print() {
	for (int i=0;i<pro.size();i++) cout << pro[i] << ' ';
	cout << endl;
	for (int i=1;i<=m;i++) {
		for (int j=0;j<arc[i].size();j++) cout << arc[i][j] << ' ';
		cout << endl;
	}
}

int cal() {
	map<int,int> mpx;
	int ret=0;
	for (int i=0;i<n;i++) {
		mpx[pro[i]]++;
		for (int j=pro[i]+1;j<=n;j++) ret+=mpx[j];
	}
	return (n*(n-1)/2)-ret+1;
}

bool check(int x) {
	int cnt=0;
	for (int i=0;i<arc[x].size();i++) {
		if (arc[x][i]==pro[cnt]) {
			cnt++;
		}
		if (cnt==n) break;
	}
	return cnt==n;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		init();
		for (int i=1;i<=n;i++) {
			string x;
			cin >> x;
			pro.push_back(get(x));
		}
		SI(m);
		for (int i=1;i<=m;i++) {
			int x;SI(x);
			for (int j=1;j<=x;j++) {
				string tmp;
				cin >> tmp;
				arc[i].push_back(get(tmp));
			}
		}
//		print();
		int ans=0,id=-1;
		do {
			int tmp=cal();
			int ok=0;
			int i;
			for (i=1;i<=m;i++) if (check(i)) {
				ok=1;
				break;
			}
			if (ok) {
//				cout << "i=" << i << ' ' << "tmp=" << tmp << endl;
				if (ans<tmp){
					ans=tmp;
					id=i;
				}
				if (ans==tmp && id>i) id=i;
			}
		}while (next_permutation(pro.begin(),pro.end()));
		if (id==-1) cout << "Brand new problem!" << endl;
		else {
			cout << id << endl;
			cout << "[:";
			for (int i=1;i<=ans;i++) cout << '|';
			cout << ":]\n";
		}
	}
	return 0;
}

