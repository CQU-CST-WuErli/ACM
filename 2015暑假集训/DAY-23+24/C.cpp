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
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m,k;

int mp[25][25];
int dp[25][25][25][25];
int counter[25][25][25][25];

int check(int x1,int y1,int x2,int y2){
	int cnt=0;
	for (int i=x1;i<=x2;i++)
		for (int j=y1;j<=y2;j++) 
			cnt+=mp[i][j];
	return cnt;
}

int dfs(int x1,int y1,int x2,int y2){	
	int &ans=dp[x1][y1][x2][y2];
	if (x1>x2 || y1>y2) return ans=INF;
	if (ans!=-1) return ans;
	int tmp=counter[x1][y1][x2][y2];
	if (tmp==1) return ans=0;
	if (tmp==0) return ans=INF;
	ans=INF;
	for (int x=x1;x<x2;x++){
		ans=min(ans,dfs(x1,y1,x,y2)+dfs(x+1,y1,x2,y2)+y2-y1+1);
	}
	for (int y=y1;y<y2;y++){
		ans=min(ans,dfs(x1,y1,x2,y)+dfs(x1,y+1,x2,y2)+x2-x1+1);
	}
	if (ans==INF) ans=0;
	return dp[x1][y1][x2][y2]=ans;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n >> m >> k){
		CLR(mp);
		for (int i=1;i<=k;i++){
			int x,y;
			cin >> x >> y;
			mp[x][y]=1;
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				for (int s=i;s<=n;s++)
					for (int t=j;t<=m;t++)
						counter[i][j][s][t]=check(i,j,s,t);
		OFF(dp);
//		cout << dfs(1,1,n,m) << endl;
		printf("Case %d: %d\n",kase++,k==0?0:dfs(1,1,n,m));				
	}
	return 0;
}


