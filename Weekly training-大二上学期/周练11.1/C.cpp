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
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

int a[1010];
int n;

int dfs(int sum) {
	if (sum==1) return a[1];
	else if (sum==2) return a[2];
	else if (sum==3) return a[1]+a[2]+a[3];
	else if (sum>3) {
		int t1=a[1]+2*a[2]+a[sum];
		int t2=2*a[1]+a[sum-1]+a[sum];
		return min(t1,t2)+dfs(sum-2);
	}
}

void print(int sum) {
	if (sum==1) cout << a[1] << '\n';
	else if (sum==2) cout << a[1] << ' ' << a[2] << '\n';
	else if (sum==3) {
		cout << a[1] << ' ' << a[sum] << '\n';
		cout << a[1] << '\n';
		cout << a[1] << ' ' << a[2] << '\n';
	}
	else if (sum>3) {
		int t1=a[1]+2*a[2]+a[sum];
		int t2=2*a[1]+a[sum-1]+a[sum];
		if (t1<t2) {
			cout << a[1] << ' ' << a[2] << '\n';
			cout << a[1] << '\n';
			cout << a[sum-1] << ' ' << a[sum] << '\n';
			cout << a[2] << '\n';
		}
		else {
			cout << a[1] << ' ' << a[sum] << '\n';
			cout << a[1] << '\n';
			cout << a[1] << ' ' << a[sum-1] << '\n';
			cout << a[1] << '\n';
		}
		print(sum-2);
	}
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		For_UVa;
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> a[i];
		}
		sort(a+1,a+1+n);
		int ans=dfs(n);
		cout << ans << endl;
		print(n);
	}
	return 0;
}

