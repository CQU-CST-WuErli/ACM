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
int k;
int flag;
map<char,int> mp[6];

int dfs(string s,int cnt){
	if (cnt==5){
		flag++;
		if (flag==k) {
			cout << s << endl;
			return true;
		}
		return false;
	}
	for (map<char,int>::iterator it=mp[cnt].begin();it!=mp[cnt].end();it++){
		char c=it->first;
		if (it->second>=2 && dfs(s+c,cnt+1)) return true;
	}	
	return false;
}
 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> T;
	while (T--){
		SI(k);
		getchar();
		flag=0;
		for (int i=0;i<2;i++){
			for (int j=0;j<6;j++){
				for (int t=0;t<5;t++){
					char c;
					cin >> c;
					if(i==0){
						if (!mp[t].count(c)) mp[t][c]=1;
					}
					else if (i==1){
						if (mp[t].count(c)) mp[t][c]++;
					}
				}
			}
		}
		if (!dfs("",0)) cout << "NO\n";
		for (int i=0;i<=5;i++) mp[i].clear();
	}
	return 0;
}


