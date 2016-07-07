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

const int N=60;
int t;
int n,k;
typedef pair<int,int> P;
P v[N];
int kase;
int dp[N][N][N*N];
int vis[N][N][N*N];

bool cmp(const P& a,const P& b){
	return a.second*b.first>a.first*b.second;
}

int dfs(int id,int cnt,int h){
	if (id==n+1) return 0;
	if (cnt==k) return 0;
	int &ans=dp[id][cnt][h];
	if (vis[id][cnt][h]==kase) return ans;
	ans=0;
	vis[id][cnt][h]=kase;
	ans=max(ans,dfs(id+1,cnt,h));
	ans=max(ans,dfs(id+1,cnt+1,h+v[id].second)+2*v[id].first*h+v[id].first*v[id].second);
	return dp[id][cnt][h]=ans; 
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	kase=1;
	CLR(vis);
	while (t--){
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++){
			scanf("%d%d",&v[i].first,&v[i].second);
		} 
		sort(v+1,v+n+1,cmp);
		int ans=0;
		printf("Case %d: %d\n",kase++,dfs(1,0,0));
	}
	return 0;
}


