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

int n,m;

int mp[110][110];
int price[110];
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> n >> m;
	CLR(mp);
	for (int i=1;i<=n;i++) cin >> price[i];
	for (int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		mp[u][v]=mp[v][u]=1;
	}
	int ans=5e6;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++){
			if (mp[i][j]){
				for (int k=1;k<=n;k++){
					if (mp[j][k] && mp[k][i]) ans=min(ans,price[i]+price[j]+price[k]);
				}
			}
		}
	}
	if (ans>=5e6) cout << "-1\n";
	else cout << ans << endl;
	return 0;
}


