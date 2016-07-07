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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 1010
char m[maxn][maxn];
int des[maxn][maxn],vis[maxn][maxn];
int d[4][2]={1,0,-1,0,0,1,0,-1};
int T;
typedef pair <int,int> pp;
bool bfs(int sn,int sm){
	queue<pp> q;
	q.push(make_pair(sn,sm));
	while (!q.empty()){
		pp temp=q.front();q.pop();
		for (int i=0;i<4;i++){
			int nx=temp.first+d[i][0],ny=temp.second+d[i][1];
			
		}
	}
}
int main()
{
	cin >> T;
	while (T--){
		int m,n;
		int sn,sm;
		cin >> n >> m;
		CLR(des);
		CLR(vis);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				cin >> m[i][j];
				if (m[i][j]=='S') {
					sn=i;
					sm=j;
				}
				if (m[i][j]=='!') des[i][j]=1;
				if (m[i][j]=='#') vis[i][j]=1;
			}
		bool ans=bfs(sn,sm);
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}


