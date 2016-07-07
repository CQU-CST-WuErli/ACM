//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
int mp[6][6];
int vis[6][6];
int n,m;
int d[4][2]={1,0,-1,0,0,1,0,-1};
int suc[2];

void dfs(int x,int y,int c){
	int sc=0;
	for (int i=0;i<4;i++){
		int tx=x+d[i][0],ty=y+d[i][1];
		if (tx<0 || tx>n || ty<0 || ty>m) continue;
		if (mp[tx][ty] && !vis[tx][ty]){
			sc=1;
			vis[tx][ty]=1;
			dfs(tx,ty,1-c);
			vis[tx][ty]=0;
		}
		if (!sc) {
			suc[c]++;
			return;
		}
	}
//	return;
}

int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (cin >> n >> m){
		memset(vis,0,sizeof vis);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				char x;
				cin >> x;
				if (x=='*') mp[i][j]=0;
				else mp[i][j]=1;
			}
		}
		int temp=-1;
		int flag=0;
		int tt=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++){
				memset(suc,0,sizeof suc);
				if (mp[i][j] && !vis[i][j]){
					vis[i][j]=1;
					dfs(i,j,0); 
					cout << "ss=" << suc[0] << " " << suc[1]<<endl; 
					vis[i][j]=0;
				}
				if (suc[1]) flag=1;
				else flag=0;
				if (temp!=-1 && temp!=flag){
					tt=0;
					break;
				}
				else if (temp==-1) temp=flag;
			}
			if (tt) break;
		}		
		if (tt) {
			cout << "draw\n";
			continue;
		}
		if (temp==0) cout << "Alice\n";
		else if (temp==1) cout << "Bob\n";
	}		
	return 0;
}


