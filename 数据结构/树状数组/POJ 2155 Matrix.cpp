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
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1100;

int c[N][N];
int n,q;

int lowbit(int x) {
	return x&(-x);
}

void update(int x,int y) {
	for (int i=x;i<=n;i+=lowbit(i)) {
		for (int j=y;j<=n;j+=lowbit(j)){
			c[i][j]+=1;
		}
	}
}

int query(int x,int y) {
	int ret=0;
	for (int i=x;i>0;i-=lowbit(i)){
		for (int j=y;j>0;j-=lowbit(j)) {
			ret+=c[i][j];
		}
	}
	return ret%2;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	int kase=1;
	cin >> T_T;
	while (T_T--) {
		if (kase!=1) cout << endl;kase++;
		cin >> n >> q;
		CLR(c);
		while (q--) {
			char op;
			cin >> op;
			if (op=='C') {
				int a1,b1,a2,b2;
				SII(a1,b1);
				SII(a2,b2);
				update(a1,b1);
				update(a2+1,b1);
				update(a1,b2+1);
				update(a2+1,b2+1); 
			}
			else {
				int x,y;
				SII(x,y);
				cout << query(x,y) << endl;
			}
		}
	}
	return 0;	
}

