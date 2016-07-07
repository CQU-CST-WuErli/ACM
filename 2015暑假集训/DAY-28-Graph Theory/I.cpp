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
#define BUG cout << "I am here" << endl
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

struct Node{
	int x,y,z;
	int r;
};
vector<Node>ns;

double g[110][110];
int n;

double dis(Node &a,Node &b){ 
	double d=0.00;
	d+=(a.x-b.x)*(a.x-b.x);
	d+=(a.y-b.y)*(a.y-b.y);
	d+=(a.z-b.z)*(a.z-b.z);
	d=sqrt(d);
	if (d<=a.r+b.r) return 0;
	else return (d-a.r-b.r)*10.0;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && (n!=-1)){
		ns.push_back(Node{0,0,0,0});
		for (int i=0;i<n;i++){
			int x,y,z,r;
			SIII(x,y,z);SI(r);
			ns.push_back(Node{x,y,z,r});
		}
		for (int i=0;i<2;i++) {
			int x,y,z;
			SIII(x,y,z);
			if (i==0) {
				ns[0].x=x;ns[0].y=y;ns[0].z=z;
			}
			else {
				ns.push_back(Node{x,y,z,0});
			}
		}
		for (int i=0;i<n+2;i++)
			for (int j=0;j<n+2;j++) g[i][j]=dis(ns[i],ns[j]);
		
		for (int k=0;k<ns.size();k++)
			for (int i=0;i<ns.size();i++)
				for (int j=0;j<ns.size();j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
		printf("Cheese %d: Travel time = %.0f sec\n",kase++,g[0][n+1]);
		ns.clear();
	}
	return 0;
}


