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
vector<int> fib;
set<int> in;
void init() {
	fib.push_back(0);
	fib.push_back(1);
	in.insert(0);in.insert(1);
	rep(i,0,fib.size()-1) {
		if (fib[i]+fib[i+1]<=1000000000) {
			fib.push_back(fib[i]+fib[i+1]);
			in.insert(fib[i]+fib[i+1]);
		}
		else break;
	}
//	rep(i,0,fib.size()-1) cout << fib[i] << endl;
//	lookln(fib.size());
//	lookln(in.size());
}


int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
//	init();
	while (SI(n)==1) {
//		int ok=0;
//		rep(i,0,fib.size()-1) {
//			if (fib[i]<=n) {
//				rep(j,0,fib.size()-1) {
//					if (n>=fib[i]+fib[j] && in.count(n-fib[i]-fib[j])) {
//						cout << fib[i] << ' ' << fib[j] << ' ' << n-fib[i]-fib[j] << endl;
//						ok=1;
//						break;
//					}
//				}
//			}
//			if (ok) break;
//		}
//		if (!ok) cout << "I'm too stupid to solve this problem" << endl;
		cout << "0 0 " << n << endl;
	}
	return 0;
}

