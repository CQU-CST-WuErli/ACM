//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


ll C(int n,int k){
	ll result[100];
	for (int i=1;i<=n;i++){
		result[i]=1;
		for (int j=i-1;j>=1;j--){
			result[j]=result[j-1]+result[j];
		}
		result[0]=1;
	}
	return result[k];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int n,m,t;
	while (cin >> n >> m >> t){
		int free=t-5;             // 还需要的名额 
		int a=n-4,b=m-1;
//		cout << C(n,m) << endl;
		ll ans=0;
		for (int i=4;i<t;i++){
//			cout << C(n,i) << endl;
//			cout << C(m,n-i) << endl;
//			cout << m << " " << n-i << endl;
			if (i>n || t-i>m) continue;
			ans+=C(n,i)*C(m,t-i);
		}
		cout << ans << endl;
	}
	return 0;
}


