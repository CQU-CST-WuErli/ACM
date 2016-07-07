//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
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
#define at(i,v) for (auto &i:v)
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
const int N=1010;
int W,B;
double dp[N][N]; 

void init(){
	dp[0][0]=0.00;
	for (int i=1;i<=1000;i++) dp[0][i]=0.0;
	for (int i=1;i<=1000;i++)                   
		for (int j=1;j<=1000;j++) dp[i][j]=-1;	
	for (int i=1;i<=W;i++){
		dp[i][0]=1;
		dp[i][1]=1.0*i/(double)(i+1);
		dp[i][2]=1.0*i/(double)(i+2)+2.0/(double)(i*i+3*i+2);
	}
	dp[1][2]=1.0/3.0;
}

double dfs(int w,int b){
//	if (!w) return 0;
//	if (!b) return 1;
	if (dp[w][b]!=-1) return dp[w][b];
	double ret=(double) w/(double)(w+b)*1.0;
	ret+=1.0*b/(double)(w+b)*(double)(b-1)/(double)(w+b-1)*(double)w/(double)(w+b-2)*dfs(w-1,b-2);
	ret+=1.0*b/(double)(w+b)*(double)(b-1)/(double)(w+b-1)*(double)(b-2)/(double)(w+b-2)*dfs(w,b-3);
	return dp[w][b]=ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	
	while (scanf("%d%d",&W,&B)==2){
		init();
		dfs(W,B);
		printf("%.9f\n",dp[W][B]);
	}
	return 0;
}


