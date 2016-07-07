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
#define BUG(x) cout << "I am in line" << x << endl
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

int T;
ll mp[11][11];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	SI(T);
	while (T--){
		CLR(mp);
		for (int i=9;i>=1;i-=2){
			for (int j=1;j<=10-i;j+=2){
				cin >> mp[i][j];
			}
		}
		for (int i=1;i<=7;i+=2){
			mp[1][i+1]=(mp[3][i]-mp[1][i]-mp[1][i+2])/2;
		}
//		for (int i=1;i<=9;i++) cout << mp[1][i] << ' ';	
		for (int i=2;i<=9;i++){
			for (int j=1;j<=10-i;j++){
				mp[i][j]=mp[i-1][j]+mp[i-1][j+1];
			}
		}
		for (int i=9;i>=1;i--){
			for (int j=1;j<=10-i;j++){
				cout << mp[i][j];
				if (j<10-i) cout << ' ';
				else cout << endl; 
			}
		}
	}
	return 0;
}


