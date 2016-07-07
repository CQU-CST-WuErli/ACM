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
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int t;
char mp[50][50];
int n,m;
double sum;
int vis[50][50];
int dir[4][2]={2,0,0,2,-2,0,0,-2};

bool dfs(int x,int y,double val){
	if (val==sum) return true;
	vis[x][y]=1;
	for (int i=0;i<4;i++) {
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if (tx<1 || tx>n || ty<1 || ty>m || vis[tx][ty] || !isdigit(mp[tx][ty])) continue;
		char op;
		if (dir[i][0]==0) op=mp[tx][dir[i][1]>0?ty-1:ty+1];
		else op=mp[dir[i][0]>0?tx-1:tx+1][ty];
		double num=mp[tx][ty]-'0'*1.0;
		double tmp;
		if (op=='+') tmp=val+num;
		else if (op=='-') tmp=val-num;
		else if (op=='*') tmp=val*num;
		else tmp=val/num;
		if (dfs(tx,ty,tmp)) return true;
	}
	vis[x][y]=0;
	return false;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	SI(t);
	while (t--) {
		SII(n,m);
		cin >> sum;
		set<pair<int,int> > st;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			cin >> mp[i][j];
			if (mp[i][j]>='0' && mp[i][j]<='9') st.insert(make_pair(i,j)); 
		}
//		for (int i=1;i<=n;i++) {
//			for (int j=1;j<=m;j++) cout << mp[i][j] ;
//			cout << endl;
//		} 
		bool ans=false;
		set<pair<int,int> >::iterator it;
		for (it=st.begin();it!=st.end();it++) {
			CLR(vis);
			if (dfs(it->first,it->second,1.0*mp[it->first][it->second]-'0')) {
//				cout << it->first << ' ' << it->second << endl; 
				ans=true;
				break;
			}
		}
		puts(ans?"Possible":"Impossible");		
	}
	return 0;
}

