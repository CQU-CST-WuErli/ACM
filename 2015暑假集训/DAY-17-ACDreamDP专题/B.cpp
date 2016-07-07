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

int n;
int sum_a[1010],sum_b[1010];
int dp[30][30][30][30];

void init(){
	sum_a[0]=sum_b[0]=0;
	int x;
	for (int i=1;i<=n;i++) {
		scanf("%d",&x);
		sum_a[i]=sum_a[i-1]+x;
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&x);
		sum_b[i]=sum_b[i-1]+x;
	}
	OFF(dp);
} 

int dfs(int L1,int R1,int L2,int R2){
	if (dp[L1][R1][L2][R2]>=0) return dp[L1][R1][L2][R2];
	int sum=0;
	int ans=0;
	if (L1<=R1) sum+=sum_a[R1]-sum_a[L1-1];
	if (L2<=R2) sum+=sum_b[R2]-sum_b[L2-1];
	if (L1<=R1){
		ans=max(ans,sum-dfs(L1+1,R1,L2,R2));
		ans=max(ans,sum-dfs(L1,R1-1,L2,R2));
	} 
	if (L2<=R2){
		ans=max(ans,sum-dfs(L1,R1,L2+1,R2));
		ans=max(ans,sum-dfs(L1,R1,L2,R2-1));
	}
	return dp[L1][R1][L2][R2]=ans;
} 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (scanf("%d",&n)==1){
		init();
		cout << dfs(1,n,1,n) << endl;
	}
	return 0;
}


