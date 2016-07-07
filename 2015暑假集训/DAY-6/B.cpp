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
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int G[300][300];
int vis[300][300];
int temp[300][300];
int T;
int n;
int cnt;

void dfs(int u){
	for (int v=0;v<26;v++) if (G[u][v] && temp[u][v]){
		temp[u][v]--;
		dfs(v);
		cnt++;
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	cin >> T;
	while (T--){
		cin >> n;
		getchar();
		string s;
		CLR(vis);
		CLR(temp);
		CLR(G);
		for (int i=0;i<n;i++){
			getline(cin,s);
			cout << s << endl;
			G[s[0]-'0'][s[s.size()-1]-'0']++;
			vis[s[0]-'0'][s[s.size()-1]-'0']++;	
		}
		int ans=0; 
		for (int i=0;i<26;i++){
			cnt=0;
			memcpy(temp,vis,sizeof(vis));
			dfs(i);
			if (cnt==n) {
				ans=1;
				break;
			}
		}
		if (ans) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}


