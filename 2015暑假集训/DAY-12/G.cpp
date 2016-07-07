//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

char mp[35][35];
int n,m;
int vis[35][35];
int vis1[35][35];
int can[35];
string ans,tmp,now;
typedef pair<int,int> P;
const int dir[4][2]={0,1,1,0,-1,0,0,-1};

void init(){
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> mp[i][j];
	CLR(vis);
}

int maxlen(int x,int y){       // 找到能够走的最长道路 
	queue<P> q;q.push(P(x,y));
	int ret=1;
	can[0]=mp[x][y]-'0';
	CLR(vis1);
	vis1[x][y];
	while (!q.empty()){
		P temp=q.front();q.pop();
		int nx=temp.first,ny=temp.second;
		for (int i=0;i<4;i++){
			int tx=nx+dir[i][0],ty=ny+dir[i][1];
			if (!isdigit(mp[tx][ty]) || vis[tx][ty] || vis1[tx][ty]) continue;
			vis1[tx][ty]=1;
			can[ret++]=mp[tx][ty]-'0';
			q.push(P(tx,ty));
		}
	}
	return ret;
}


void dfs(int x,int y){
	now+=mp[x][y];
	vis[x][y]=1;
	for (int i=0;i<4;i++){
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if (!isdigit(mp[tx][ty]) || vis[tx][ty]) continue;
		int maxl=maxlen(tx,ty);
		if (now.size()+maxl<ans.size()) continue;
		if (now.size()+maxl==ans.size()) {
			sort(can,can+maxl);
			tmp=now;
			for (int i=maxl-1;i>=0;i--) tmp+=(can[i]+'0');
			if (tmp<ans) continue;
		}
	}
	if (ans<now) ans=now;
	now.pop_back();
	vis[x][y]=0;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m && (n || m)){
		getchar();
		init();
		ans.clear();now.clear();
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) if (isdigit(mp[i][j])) dfs(i,j);
		cout <<ans << endl;
	}
	return 0;
}
