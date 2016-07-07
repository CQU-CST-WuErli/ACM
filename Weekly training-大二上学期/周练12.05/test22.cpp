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
#define null NULL
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

int mp[110][110];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int n;
	int kase=1;
	while (cin >> n) {
		CLR(mp);
		int flag=1;
		int line=0,row=0;
		for (int i=1;i<=n;i++) {
			set<int> st;
			int tot=0;
			for (int j=1;j<=n;j++) {
				cin >> mp[i][j];
				if (mp[i][j]>0) tot++,st.insert(mp[i][j]);
			}
			if (st.size()!=tot) flag=0,line=i;
		}
		for (int i=1;i<=n;i++) {
			set<int> st;
			int tot=0;
			for (int j=1;j<=n;j++) {
				if (mp[j][i]) tot++,st.insert(mp[j][i]);
			}
			if (st.size()!=tot) flag=0,row=i;
		}
		cout << "Case " << kase++ << ": ";
		if (flag) cout << "AC\n";
		else {
			cout << "WA\n";
			if (line) {
				cout << "in line " << line << endl;
				for (int i=1;i<=n;i++) cout << mp[line][i] << ' ';
				cout << endl;
			}
			else {
				cout << "in row " << row << endl;
				for (int i=1;i<=n;i++) cout << mp[i][row] << ' ' ;
				cout << endl; 
			}
		} 
	}
	return 0;
}

