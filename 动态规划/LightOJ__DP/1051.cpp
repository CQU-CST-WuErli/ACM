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

int dp[55][2]; 
int state[55];
bool isvowel(char c) {
	return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
		cout << "Case " << kase << ": ";
		CLR(dp);CLR(state);
		char s[55];
		scanf("%s",s+1);
		int ls=strlen(s+1);
		rep(i,1,ls) {
			if (isvowel(s[i])) state[i]=-1;
			else if (s[i]!='?') state[i]=1;
			else state[i]=0;
		} 
		int bad=0;
		rep(i,1,ls) {
			if (i>=3) {
                if (state[i]<=0 && state[i-1]<=0 && state[i-2]<=0) {
                    bad=1;
                    break;
                }
            }
            if (i>=5) {
                if (state[i]>=0 && state[i-1]>=0 && state[i-2]>=0 && state[i-3]>=0 && state[i-4]>=0) {
                    bad=1;
                    break;
                }
            }
		}
		if (!bad) {
			cout << "GOOD\n";
			continue; 
		}
		dp[0][1]=dp[0][0]=1;
		rep(i,1,ls) {
			if (i<3) {
				if (state[i]<=0) dp[i][0]=1;
				if (state[i]>=0) dp[i][1]=1;
			}	
			else {
                if (state[i]<=0) {
                    if (state[i-1]>=0) {
                        dp[i][0]=(dp[i-1][1] || dp[i][0]);
                    }
                    if (state[i-1]<=0 && state[i-2]>=0) {
                        dp[i][0]=(dp[i-2][1] || dp[i][0]);
                    }
                }
                if (state[i]>=0) {
                    if (state[i-1]<=0) {
                        dp[i][1]=(dp[i][1] || dp[i-1][0]);
                    }
                    if (state[i-1]>=0) {
                        if (state[i-2]<=0) {
                            dp[i][1]=(dp[i][1] || dp[i-2][0]);
                        }
                        if (state[i-2]>=0) {
                            if (state[i-3]<=0) {
                                dp[i][1]=(dp[i][1] || dp[i-3][0]);
                            }
                            if (state[i-3]>=0) {
                                if (state[i-4]<=0) {
                                    dp[i][1]=(dp[i][1] || dp[i-4][0]);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (dp[ls][1]||dp[ls][0]) cout << "MIXED\n";
        else cout << "BAD\n";
	}
	return 0;
}

