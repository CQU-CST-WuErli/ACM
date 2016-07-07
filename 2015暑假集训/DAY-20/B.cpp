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

int a[7];
int dp[70000];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> a[1]){
		int sum=a[0];
		for (int i=2;i<=6;i++) {
			cin >> a[i];
			sum+=a[i];
		}
		if (sum==0) break;
		bool ans=false;
		int sumv=0;
		for (int i=1;i<=6;i++){
			for (int j=0;j<a[i];j++)
				sumv+=i;
		}
		if (sumv%2){
			ans=false;
		}
		else{
			CLR(dp);
			sumv/=2;
			dp[0]=1;
			for (int i=1;i<=6;i++){
				int tmp;
				if (!a[i]) continue;
				for (int j=1;j<=a[i];j*=2){
					tmp=j*i;
					for (int k=sumv;k>=tmp;k--){
						if (dp[k-tmp]) dp[k]=1;
					}
					a[i]-=j;			
				}
				tmp=a[i]*i;
				if (tmp>0){
					for (int k=sumv;k>=tmp;k--){
						if (dp[k-tmp]) dp[k]=1;
					}
				}
			}
			if (dp[sumv]) ans=true;
		}
		printf("Collection #%d:\n",kase++);
		if (ans) cout << "Can be divided.\n\n";
		else cout << "Can't be divided.\n\n";
	}
	return 0;
}


