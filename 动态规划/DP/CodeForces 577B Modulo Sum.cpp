//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
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
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
int a[1000100];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
	    rep(i,1,n) SI(a[i]);
	    int flag=0;
	    if (n>m) {
	    	int sum[1010];
	    	set<int> st;
	    	CLR(sum);
	    	rep(i,1,n) {
	    		sum[i]=(sum[i-1]+a[i])%m;
	    		if (st.count(sum[i])) {
	    			flag=1;break;
	    		}
	    		st.insert(sum[i]);
	    	}
	    }
	    else {
	    	set<int> st;
	    	vector<int> v;
	    	for (int i=1;i<=n;i++) {
	    		int tmp=v.size();
	    		for (int j=0;j<tmp;j++) {
	    			if (!st.count((a[i]+v[j])%m)) {
	    				v.push_back((a[i]+v[j])%m);
	    				st.insert((a[i]+v[j])%m);
	    			}
	    		}
	    		if (!st.count(a[i]%m)) st.insert(a[i]%m),v.push_back(a[i]%m);
	    	}
	    	if (st.count(0)) flag=1;
	    }
	    puts(flag?"YES":"NO");
	}
	return 0;
}
