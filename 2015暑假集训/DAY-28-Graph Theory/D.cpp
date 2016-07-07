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

map<string,int> mp;
int cnt;
int g[50][50];
string name[50];
int n,m;
int kase;

int get_id(string &s){
	if (!mp.count(s)) {
		mp[s]=cnt;
		name[cnt++]=s;
	}
	return mp[s];
}

bool read(){
	bool yes=false;	
	if (SII(n,m)==2 && (n||m)){
		yes=true;
		cnt=0;
		CLR(g);
		getchar();
		for (int i=1;i<=m;i++){
			string u,v;
			cin >> u >> v;
			g[get_id(u)][get_id(v)]=1;
		}
	}
	return yes;
}

void floyd(){
	for (int k=0;k<cnt;k++) 
		for (int i=0;i<cnt;i++)
			for (int j=0;j<cnt;j++)
				g[i][j]=g[i][j]||(g[i][k] && g[k][j]);
}

void solve(){
	floyd();
//	lookln(cnt);
	printf("Calling circles for data set %d:\n",kase++);
	int vis[30]={0};
	for (int i=0;i<cnt;i++) if (!vis[i]){
		cout << name[i];
		vis[i]=1;
		for (int j=0;j<cnt;j++){
			if (j!=i && g[i][j] && g[j][i] && !vis[j]){
				cout << ", " << name[j];
				vis[j]=1;
			}
		}
		cout << endl;
	}
	mp.clear();
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	kase=1;
	while (read()){
		For_UVa;
		solve();
	}
	return 0;
}


