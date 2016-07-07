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
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int t;
int r,c;
string name;
int a[110][110];
int dp[110][110];
int ans;
int dir[4][2]={1,0,0,1,-1,0,0,-1};

int dfs(int x,int y){
	int &ret=dp[x][y];
	if (ret!=0) return ret;
	for (int i=0;i<4;i++){
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if (nx>=1 && nx<=r && ny>=1 && ny<=c){
			if (a[x][y]>a[nx][ny]){
				ret=max(ret,dfs(nx,ny)+1);
			}
		}
	}
	if (ret==0) ret=1;
	return dp[x][y]=ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	getchar();
	while (t--){
		cin >> name >> r >> c;
		getchar();
		for (int i=1;i<=r;i++)
			for (int j=1;j<=c;j++){
				scanf("%d",&a[i][j]);
			}
		CLR(dp);
		ans=0;
		for (int i=1;i<=r;i++)
			for (int j=1;j<=c;j++){
				ans=max(ans,dfs(i,j));
			}
		cout << name << ": " << ans<< endl;
	}
	return 0;
}


