//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int a[10010];
int dp[10010];
int st[10010];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n && n){
		int flag=0;
		for (int i=1;i<=n;i++) {
			scanf("%d",a+i);
			if (a[i]>=0) flag=1;
		}
		if (!flag) {
			cout << 0 << " " << a[1] << " " << a[n] << endl;
			continue;
		}
		else {
			CLR(dp);CLR(st);
			dp[1]=a[1];
			st[1]=1;
			int Max=-1;
			for (int i=2;i<=n;i++){
				if (dp[i-1]+a[i]<a[i]){
					dp[i]=a[i];
					st[i]=i;
				}
				else {
					dp[i]=dp[i-1]+a[i];
					st[i]=st[i-1];
				}
			}
			int l,r;
			for (int i=1;i<=n;i++){
				if (dp[i]>Max){
					Max=dp[i];
					l=st[i];
					r=i;
				}
			}
			cout << Max << " " << a[l] << " " << a[r] << endl;
		}
		
	}
	return 0;
}


