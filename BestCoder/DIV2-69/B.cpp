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

bool data(char t[]) {
	int year=0,month=0,day=0;
	for (int i=0;i<4;i++) year=year*10+t[i]-'0';
	for (int i=4;i<6;i++) month=month*10+t[i]-'0';
	for (int i=6;i<8;i++) day=day*10+t[i]-'0';
//	cout << year << ' ' << month << ' ' << day << endl;
	if (year<1980 || year>2016) return false;
	if (month<1 || month>12) return false;
	if (day<1 || day>31) return false;
	set<int> big,small;
	big.insert(1);big.insert(3);big.insert(5);big.insert(7);
	big.insert(12);big.insert(10);big.insert(8);
	small.insert(4);small.insert(6);small.insert(9);small.insert(11);
	if (big.count(month) && (day<1 || day>31)) return false;
	else if (small.count(month) && (day<1 || day>30)) return false; 
	else {
		if ((year%4==0 && year%100!=0) && (day<1 || day>29)) return false;
		if ( year%400==0 && (day<1 || day>29)) return false;
		if (!(year%4==0 && year%100!=0) && !(year%400==0) && day>28) return false;
	}
	return true;
}
// 1 3 5 7 8 10 12 
// 4 6 9 11
// 2

bool check(char s[]) {
	bool ok=true;
	for (int i=6;i<10;i++) if (s[i]!=s[i+1]) {
		ok=false;
		break;
	}
	if (ok) return true;
	ok=true;
	for (int i=6;i<10;i++) if (s[i]-'0'+1!=s[i+1]-'0') {
		ok=false;
		break;
	}
	if (ok) return true;
	ok=true;
	for (int i=6;i<10;i++) if (s[i]-1-'0'!=s[i+1]-'0') {
		ok=false;
		break;
	}
	if (ok) return true;
	ok=true;
	if (!data(s+3)) ok=false;
	if (ok) return true;
	return false;
}

ll x,y;
int n;
int t;
char s[13];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	SI(t);
	while (t--) {
		SI(n);
		cin >> x >> y;
//		cout << x << ' ' << y << endl;
		ll ans=0;
		for (int i=1;i<=n;i++) {
			scanf("%s",s);
			if (check(s)) {
				ans+=x;
			}
			else {
				ans+=y;
			}
		}
		cout << ans << endl; 
	}
	return 0;
}

