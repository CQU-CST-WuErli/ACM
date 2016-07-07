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


int t;
int n,k;
int g[300][300],vis[300][300];
int dir[4][2]={1,0,0,1,0,-1,-1,0};  
char Dir[4]={'e','n','s','w'};
int ans;
int path[100];

bool check(int x,int y,int nx,int ny,int d,int dep){
	int left=(dep+1+n)*(n-dep)/2;
	if (abs(nx-150)+abs(ny-150)>left) return false;
	if (vis[nx][ny] || g[nx][ny]) return false;
	int tx=nx,ty=ny;
	while (tx!=x){
		tx-=dir[d][0];
		if (g[tx][ny]) return false;
	}
	while (ty!=y){
		ty-=dir[d][1];
		if (g[nx][ty]) return false;
	}
	return true;
}

void dfs(int x,int y,int d, int dep){
	if (dep==n+1) {
		if (x==150 && y==150 ){
			ans++;
			for (int i=1;i<dep;i++) cout << Dir[path[i]];
			cout << endl;
		}
		return ;
	}
	for (int i=0;i<4;i++){
		if (i==d || i+d==3) continue;
		int nx=x+dep*dir[i][0],ny=y+dep*dir[i][1];
		if (check(x,y,nx,ny,i,dep)) {
			vis[nx][ny]=1;
			path[dep]=i;
			dfs(nx,ny,i,dep+1);
			vis[nx][ny]=0;
		}
	}
} 
 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k);
		CLR(g);CLR(vis);
		for (int i=1;i<=k;i++){
			int x,y;
			cin >> x >> y;
			if (abs(x)>150 || abs(y)>150) continue;
			g[x+150][y+150]=1;
		}
		ans=0;
		dfs(150,150,-1,1);
		cout << "Found " << ans << " golygon(s).\n\n";
	} 
	return 0;
}


