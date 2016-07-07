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
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=100;
int n,m;
double p[N];
double dp[N][N][N];
//int vis[N][N][N];
//int kase;

double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double area(double p1,double p2,double p3){
	pair<double,double> v1,v2;
	double x1,x2,x3,y1,y2,y3;
	x1=cos(p1*2*pi);y1=sin(p1*2*pi);
	x2=cos(p2*2*pi);y2=sin(p2*2*pi);
	x3=cos(p3*2*pi);y3=sin(p3*2*pi);
	double a,b,c,s;
	a=dis(x1,y1,x2,y2);
	b=dis(x1,y1,x3,y3);
	c=dis(x2,y2,x3,y3);
	s=(a+b+c)/2.00;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

//double dfs(int l,int r,int cnt){
//	if (cnt<3) return 0;
//	if (l+1>=r) return 0;
//	double &ans=dp[l][r][cnt];
//	if (vis[l][r][cnt]==kase) return ans;
//	vis[l][r][cnt]=kase;
//	ans=0;
//	for (int mid=l+1;mid<=r;mid++){
//		ans=max(ans,dfs(l,mid,cnt-1)+area(p[l],p[r],p[mid]));
////		ans=max(ans,dfs(mid,r,cnt-1)+area(p[l],p[r],p[mid]));
//	}
//	return ans;
//}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
//	kase=0;CLR(vis);
	while (SII(n,m)==2 && (n || m)){
		for (int i=1;i<=n;i++) {
			scanf("%lf",p+i);
		}
//		kase++;
		CLR(dp);
//		 dp[i][j][k]  i到j选k个点 
//		 dp[i][j][k]=max(dp[i][t][k-1]+area(i,j,k)) || max(dp[t][j][k-1]+area(i,j,k))
		  
		double maxs=0.00;
		for (int i=3;i<=m;i++){
			for (int l=1;l<=n;l++)
				for (int mid=l+1;mid<=n;mid++)
					for (int r=mid+1;r<=n;r++){
						double &ans=dp[l][r][i];
						ans=max(ans,dp[mid][r][i-1]+area(p[l],p[r],p[mid]));
//						ans=max(ans,dp[l][mid][i-1]+area(p[l],p[r],p[mid]));
						if (i==m) maxs=max(maxs,ans);	
					}
		}
		printf("%.6f\n",maxs);
//		printf("%.6f\n",dfs(1,n,m));
	}
	return 0;
}


