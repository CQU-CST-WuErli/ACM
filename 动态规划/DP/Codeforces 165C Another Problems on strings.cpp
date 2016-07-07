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

int k;
char s[1000010];
ll sum[1000010];
ll l[1000010],r[1000010];
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(k)==1) {
		scanf("%s",s+1);
		int tt=0;
		int ls=strlen(s+1);
		rep(i,1,ls) if (s[i]=='1') tt++;
		if (tt<k) {
			cout << 0 << endl;
			continue;
		}
		if (k==0) {
			ll ans=0;
			ll tmp=1;
			l[1]=1;r[ls]=ls;
			rep(i,2,ls) {
				if (s[i]==s[i-1]) l[i]=l[i-1];
				else l[i]=i;
			}
			Rep(i,ls-1,1) {
				if (s[i]==s[i+1]) r[i]=r[i+1];
				else r[i]=i;
			}
			int pos=1;
			while (pos<=ls) {
				if (s[pos]=='0') {
					ll tmp=r[pos]-l[pos]+1;
//					lookln(tmp);
					ans+=(tmp*(tmp+1))/2;
				}
				pos=r[pos]+1;
//				lookln(pos);
			}	
			cout << ans << endl;
			continue; 
		}
		CLR(sum);
		rep(i,1,ls) {
			if (s[i]=='0') sum[i]=sum[i-1];
			else sum[i]=sum[i-1]+1;
		}
		rep(i,1,ls) {
			if (sum[i]==sum[i-1]) l[i]=l[i-1];
			else l[i]=i;
		}
		Rep(i,ls,0) {
			if (sum[i]==sum[i+1]) r[i]=r[i+1];
			else r[i]=i;
		}
		int st,ed;
		st=0;
		for (ed=1;ed<=ls;ed=r[ed]+1) {
			if (sum[ed]==k) break;
		}
		ll ans=0;
		while (ed<=ls) {
			ans+=(r[st]-l[st]+1)*(r[ed]-l[ed]+1);
			st=r[st]+1;
			ed=r[ed]+1;
		}
		cout << ans << endl;
	}
	return 0;
}

