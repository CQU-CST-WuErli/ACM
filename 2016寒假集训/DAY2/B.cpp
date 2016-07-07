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

const int N=200010;
int x[N],w[N];
int n,d;

int LMax[N],LMax_id[N];
int RMax[N],RMax_id[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,d)==2) {
		x[0]=-1;
		rep(i,1,n) {
			SII(x[i],w[i]);
		}
		LMax[1]=w[1];LMax_id[1]=1;
		rep(i,2,n) {
			if (w[i]>LMax[i-1]) {
				LMax[i]=w[i];
				LMax_id[i]=i;
			}
			else {
				LMax[i]=LMax[i-1];
				LMax_id[i]=LMax_id[i-1];
			}
		}
		RMax[n]=w[n];RMax_id[n]=n;
		Rep(i,n-1,1) {
			if (w[i]>RMax[i+1]) {
				RMax[i]=w[i];
				RMax_id[i]=i;
			}
			else {
				RMax[i]=RMax[i+1];
				RMax_id[i]=RMax_id[i+1];
			}
		}
		// 1 3 4 6 10 11
		// 1 2 3 4  5  6
//		int pos=upper_bound(x+1,x+1+n,5)-x;
//		lookln(pos);
		int ans=-1;
		int li,ri;
		rep(i,1,n) {
			if (x[i]-d>=1) {
				int pos=upper_bound(x+1,x+1+n,x[i]-d)-x;
				pos-=1;
				if (pos>=1) {
					if (ans<w[i]+LMax[pos]) {
						ans=w[i]+LMax[pos];
						li=i;ri=LMax_id[pos];
					}
				}
			}
			if (x[i]+d<=x[n]) {
				int pos=lower_bound(x+1,x+1+n,x[i]+d)-x;
				if (pos<=n) {
					if (ans<w[i]+RMax[pos]) {
						ans=w[i]+RMax[pos];
						li=i;ri=RMax_id[pos];
					}
				}
			}
		}
		if (ans==-1) cout << -1 << ' ' << -1 << endl;
		else cout << li << ' ' << ri << endl;
	}
	return 0;
}

