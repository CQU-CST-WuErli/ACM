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
const int MAX_L=200;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=100;

int T, cas = 0;
int n;
ll m, p[60];
int a[N], b[N], tot;
ll sum(ll x) {
    if(x == 1) return 0;
    if(x == 2) return 1;
    return sum(x / 2) * 2 + x / 2;
}
void ex(ll x) {
    tot = 0;
    while(x) {
        a[tot++] = x % 2;
        x /= 2;
    }
}
void init() {
    p[0] = 1;
    for(int i = 1; i < 60; i ++) p[i] = p[i-1] * 2;
}
ll work(ll x) {
    ex(x);
    ll cnt = 0, ans = 0;
    for(int i = tot - 1; i >= 0; i --) {
        if(a[i] == 1) {
            ans += sum(p[i]) + cnt * p[i];
            cnt ++;
        }
    }
    return ans;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    cin >> T;
    while(T --) {
        scanf("%I64d", &m);
        printf("%I64d\n", work(m + 1));
    }
    return 0;
}

