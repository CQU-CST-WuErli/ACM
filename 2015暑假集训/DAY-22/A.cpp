//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
//#include<bits/stdc++.h>
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

const int N=16;
int t;
int n;
int dp[1<<N];
int line[N][N]; 

struct P{
	int x,y;
}p[N];

bool check(int a,int b,int c){
	return (p[b].x-p[a].x)*(p[c].y-p[b].y)==(p[c].x-p[b].x)*(p[b].y-p[a].y);
}
void pre_process(){
	CLR(line);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				if (check(i,j,k))
					line[i][j]|=(1<<k);
}

int dfs(int s){
	if (dp[s]!=INF) return dp[s];
	int pos=__builtin_popcount(s);
	if (pos==0) return 0; 
	if (pos<=2) return 1;
	// pruning and board
	dp[s]=INF;	                   // just for insurance  
	int cnt=__builtin_ctz(s);
	for (int i=cnt+1;i<n;i++){
		dp[s]=min(dp[s],dfs(s^(s&line[cnt][i]))+1);
	}
	return dp[s];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	scanf("%d",&t);
	for (int kase=1;kase<=t;kase++){
		printf("Case %d: ",kase);
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		MEM(dp,INF);
		pre_process();		
		printf("%d\n",dfs((1<<n)-1));
	}
	return 0;
}


