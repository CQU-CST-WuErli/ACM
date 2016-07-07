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
#include <sstream>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
//#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N = 1005;
vector<int> ch[N];

typedef pair<int,int> P;

queue<P> q;

int bfs[N];
int dfs[N];
int n;

void BFS() {
	q.push(P(0, n));
	int p=1;
	int root;
	while (!q.empty()) {
		P s=q.front();
		q.pop();
		if (s.second-s.first<= 1 || p == n)
			continue;
		root = dfs[s.first];
		int pre=s.first + 1;
		for (int i = pre; i < s.second; i++) {
			if (dfs[i] == bfs[p]){ 					
					q.push (P(pre, i));
					ch[root].push_back (dfs[i]);	
					p++;
					pre = i;
			}
		}
		if (pre<s.second) q.push(P(pre,s.second));
	}
}

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	int num;
	while (cin >> n) {
		for (int i = 0; i < n; i++) 
			scanf ("%d", &bfs[i]);
		for (int i = 0; i < n; i++)
			scanf ("%d", &dfs[i]);	
		BFS();
		for (int i = 1; i <= n; i++) {
			printf ("%d:", i);
			for (int j = 0; j < ch[i].size(); j++)
				printf (" %d", ch[i][j]);
			printf ("\n");
			ch[i].clear();
		}
	}
	return 0;
}
