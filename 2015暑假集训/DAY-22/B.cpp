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

const int S=18;
const int N=1e5+10;

int t;
int n,m;
int pre[S][S];
ll dp[65536];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int kase=scanf("%d",&t);kase<=t;kase++){
		scanf("%d%d",&n,&m);
		vector<int> vec[S];
		int color;
		for (int i=0;i<n;i++){			
			scanf("%d",&color);
			vec[color-1].push_back(i);
		}
		CLR(pre);
		for (int i=0;i<m;i++){
			for (int j=0;j<m;j++) if (i!=j){
				int cnt=0;
				for (int k=0;k<vec[i].size();k++){
					while (cnt<vec[j].size() && vec[i][k]>vec[j][cnt])
						cnt++;
					pre[i][j]+=cnt; 
				}
			}
		}
		MEM(dp,0x3f3f3f3f);
		dp[0]=0;
		for (int i=0;i<1<<m;i++){
			for (int j=0;j<m;j++) if (!(i>>j&1)) {
				ll tmp=0;
				for (int k=0;k<m;k++) if (k!=j && !(i>>k&1)){
					tmp+=pre[j][k];
				}
				dp[i|1<<j]=min(dp[i|1<<j],dp[i]+tmp);
			} 
		}
		printf("Case %d: %lld\n",kase,dp[(1<<m)-1]);
	}
	return 0;
}


