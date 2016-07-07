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
#define For_UVa if (kase!=1) cout << endl
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

const int N=1010;
struct P{
	int x,c,d;
	bool operator < (const P& rhs) const {
		return x<rhs.x; 
	}
}pos[N];
int sum_d[N];
double dp[N][N][2];
int vis[N][N][2];
int n,v,Pos;
int kase;

double dfs(int i,int j,int cnt){
	if (i==1 && j==n+1) return 0;
	double &ans=dp[i][j][cnt];
	if (vis[i][j][cnt]==kase) return ans;
	vis[i][j][cnt]=kase;
	ans=INF;
	int p=(cnt==0?i:j);
	if (i>1){
		double cost;
		cost=abs((double)pos[i-1].x-(double)pos[p].x)/(double)v*(double)(sum_d[i-1]+(sum_d[n+1]-sum_d[j]));
		ans=min(ans,dfs(i-1,j,0)+cost);
	}
	if (j<n+1){
		double cost;
		cost=abs((double)pos[j+1].x-pos[p].x)/(double)v*(double)(sum_d[i-1]+(sum_d[n+1]-sum_d[j]));
		ans=min(ans,dfs(i,j+1,1)+cost);
	}
	return ans;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	kase=1;CLR(vis);
	while (cin >> n >> v >> Pos && (n || v || Pos)){
		int sumc=0;int start;
		for (int i=1;i<=n;i++) {
			scanf("%ld%d%d",&pos[i].x,&pos[i].c,&pos[i].d);
			sumc+=pos[i].c;
		}
		pos[n+1].x=Pos;pos[n+1].c=0;pos[n+1].d=0; 
		sort(pos+1,pos+2+n);
		for (int i=1;i<=n+1;i++) {
			if (pos[i].x==Pos) start=i;
			sum_d[i]=(i==1?pos[i].d:sum_d[i-1]+pos[i].d); 
		} 
		int ans=floor(dfs(start,start,0));
		cout << ans+sumc << endl;
		kase++;
	}
	return 0;
}


