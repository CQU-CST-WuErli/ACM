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

const int N=500000+100;
int n;
int a[N];
int dp[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n){
		CLR(dp);
		int len=0;
		for (int i=1;i<=n;i++){
			int p,r;
			scanf("%d%d",&p,&r);
			a[p]=r;
		}
		dp[1]=a[1];len=1;
		for (int i=2;i<=n;i++){
			if (a[i]>=dp[len]) dp[++len]=a[i];
			else {
				int pos=lower_bound(dp+1,dp+1+len,a[i])-dp;
				dp[pos]=a[i];
			}		
		} 
		if(len==1)
     		printf("Case %d:\nMy king, at most %d road can be built.\n\n",kase++,len);   
		else
   			printf("Case %d:\nMy king, at most %d roads can be built.\n\n",kase++,len);
	}
	return 0;
}


