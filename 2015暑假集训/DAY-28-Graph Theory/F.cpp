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

int n,m;
string pat[110],sta[110];
int t[110];
int vis[1<<20];
int dp[1<<20];

// origin  1111    last  0000
// 1-> bug must exit 0-> bug can not exit

bool check(int state,int id){
	for (int i=n-1;i>=0;i--){
		if (pat[id][i]=='+' && (state&1)==0) return false;
		if (pat[id][i]=='-' && (state&1)==1) return false;
		state=state>>1;
	}	
	return true;
}

int put(int state,int id){
	int ret=0;
	for (int i=0;i<n;i++) {
		if (sta[id][i]=='-') ret=ret<<1;
		else if (sta[id][i]=='+') ret=(ret<<1)|1;
		else ret=(ret<<1)|((state>>(n-i-1))&1);
	}
//	lookln(ret);
	return ret;
}

void spfa(){
	CLR(vis);
	MEM(dp,INF);
	queue<int> q;
	q.push((1<<n)-1);
	vis[(1<<n)-1]=1;
	dp[(1<<n)-1]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=0;i<m;i++){
			if (check(x,i)){
				cout << check(x,i);
				int now=put(x,i);
//				cout << now << endl;
				if (dp[now]>dp[x]+t[i]){
					dp[now]=dp[x]+t[i];
					if (!vis[now]){
						q.push(now);
						vis[now]=1;
					}
				}
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n >> m && (n || m)){
		for (int i=0;i<m;i++){
			cin >> t[i] >> pat[i] >> sta[i];
		}
		spfa();
		printf("Product %d\n",kase++);
		if (dp[0]>=INF) cout << "Bugs cannot be fixed.\n";
		else cout << "Fastest sequence takes " << dp[0] << " seconds.\n";
		cout << endl; 
	}
	return 0;
}


