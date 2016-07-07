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
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=200;
int S;

struct SET{
	int len;
	int val[N];
	int maxv;
}st[N];

int dp[1110][20];

int dfs(int id,int sum,int cnt){
	int &ans=dp[sum][cnt];
	if (ans!=-1) return ans;
	if (sum==0) return ans=1;
	if (cnt==0) return ans=0;
	for (int i=0;i<st[id].len;i++){
		int tmp=st[id].val[i];
		if (sum>=tmp && dfs(id,sum-tmp,cnt-1)) return ans=1;
	}
	return ans=0;
}

int check(int id,int i){
	if (st[id].len<st[i].len) return id;
	if (st[id].len>st[i].len) return i;
	for (int j=st[id].len-1;j>=0;j--){
		if (st[i].val[j]<st[id].val[j]) return i;
		if (st[i].val[j]>st[id].val[j]) return id;
	}
	return id;
}
int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> S && S){
		int n;
		cin >> n;
		for (int i=1;i<=n;i++){
			int x;
			cin >> x;
			st[i].len=x;
			for (int j=0;j<x;j++) cin >> st[i].val[j];
			st[i].maxv=0;
		}
		int ans=0,ans_id=1;
		for (int id=1;id<=n;id++){
			OFF(dp);
			for (int j=1;;j++){
				if (dfs(id,j,S)) {
					st[id].maxv=j;
				}
				else break;
			}
		}
		for (int i=1;i<=n;i++){
			if (st[i].maxv>ans){
				ans=st[i].maxv;
				ans_id=i;
			}
			else if (st[i].maxv==ans){
				ans_id=check(ans_id,i);	
			}
		}
		printf("max coverage =%4d :",ans);
		for (int i=0;i<st[ans_id].len;i++) printf("%3d",st[ans_id].val[i]);
		cout << '\n';
	}
	return 0;
}


