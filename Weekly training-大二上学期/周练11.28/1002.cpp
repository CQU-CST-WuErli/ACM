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

int n;
int k;
ll a[100];
int flag[100];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	a[1]=1;
	for (int i=2;i<=70;i++) {
		a[i]=a[i-1]*2;
	}
	for (int T_T,kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		cin >> n >> k;
		for (int i=1;i<k;i++) flag[i]=-1;
		flag[k]=1;
		n--;
		int tt=0;
		while (n) {
			int pos;
			for (int i=1;i<k;i++){
				if (a[i]*2<=n) pos=i;
				else break;
			}
			flag[pos]=1;
			n-=2*a[pos];
			if (n==1) {
				tt=1;
				break;
			}
		}
		cout << "Case #" << kase << ":\n";
		for (int i=1;i<=k;i++) {
			cout << a[i]+(i==k && tt) <<  ' ';
			if (flag[i]==1) cout << '+' << endl;
			else cout << '-' << endl; 
		}
	}
	return 0;
}

