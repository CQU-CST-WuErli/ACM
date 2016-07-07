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
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

char mp[8][8];
int dp[8][8];
bool ans=true;
int dx[]={0,0,0,1,1,1,-1,-1,-1};
int dy[]={-1,0,1,-1,0,1,-1,0,1}; 

void read(){
	for (int i=0;i<8;i++) for (int j=0;j<8;j++) {
		cin >> mp[i][j];
	}
}


void dfs(int x, int y, int cnt){
	if (ans|| cnt>=8) {
		ans=true;
		return ;
	} 
	for (int i=0;i<9;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (nx>=0 && nx<8 && ny>=0 && ny<8){
			if (mp[nx-cnt][ny]!='S' && (nx<=cnt || mp[nx-cnt-1][ny]!='S')){
				dfs(nx,ny,cnt+1);
				if (ans) return;
			}
		}
	}	
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	read();
	ans=false;
	dfs(7,0,0);
	if (ans) cout << "WIN\n";
	else cout << "LOSE\n";
	return 0;
}


