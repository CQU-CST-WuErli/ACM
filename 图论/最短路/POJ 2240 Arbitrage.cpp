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
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

map<string,int> mp;
int ID;
void get_id(string &s){
	if (!mp.count(s)) mp[s]=ID++;
} 
int n,m;
double g[33][33];


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freope("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && n){
		mp.clear();ID=1;
		string s;MEM(g,0);
		for (int i=1;i<=n;i++) {
			cin >> s;
			get_id(s);g[i][i]=1.00;
		}
		cin >> m;
		for (int i=1;i<=m;i++){
			string u,v;
			double cost;
			cin >> u >> cost >> v;
			g[mp[u]][mp[v]]=cost;
		}
		for (int k=1;k<=n;k++){
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=n;j++){
					g[i][j]=max(g[i][j],g[i][k]*g[k][j]);
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++) if (g[i][i]>1) {
			ans=1;break;
		}
		cout << "Case " << kase++ << ": " ;
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

