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
#include <functional>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

char mp[110][110];
int vis[110][110];

int sum;
int m,n;
void dfs(int x,int y){
	if (x<0 || x>=m || y<0 || y>=n) return ;
	if (mp[x][y]!='@' || vis[x][y]) return;
	vis[x][y]=1;
	for (int i=x-1;i<=x+1;i++)
		for (int j=y-1;j<=y+1;j++){
			if (x<0 || x>=m || y<0 || y>=n) continue;
			dfs(i,j);
		}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif

	while (cin >> m >> n && (m || n)){
		sum=0;
		for (int i=0;i<m;i++) for (int j=0;j<n;j++) {
			cin >> mp[i][j];
			if (mp[i][j]=='@') vis[i][j]=0;
			else vis[i][j]=1;
		} 
		for (int i=0;i<m;i++) {
			for (int j=0;j<n;j++){
				if (mp[i][j]=='@' && vis[i][j]==0) {
					sum++;dfs(i,j);
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}


