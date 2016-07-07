//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015�� CQU_CST_WuErli. All rights reserved.
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


int n,m;

int g[110][110];
int len[110];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		CLR(g);CLR(len);
		for (int i=0;i<m;i++){
			int u,v;
			cin >> u >> v;
			g[u][v]=g[v][u]=1;
			len[u]++;len[v]++;
		}
		int ans=0;
		while (1){
			int flag=0;
			queue<int> q;
			for (int i=1;i<=n;i++){
				if (len[i]==1){
					flag=1;
					q.push(i);
				}
			}
			while(q.size()){
				int u=q.front();q.pop();
//				cout << x << endl;
				int v;
				for (int j=1;j<=n;j++){
					if (g[u][j]) {
						v=j;
						g[u][v]=g[v][u]=0;
						len[u]--;len[v]--;
					}
				}
//				cout << x << " " << v << endl; 
			}
			if (!flag) break;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}


