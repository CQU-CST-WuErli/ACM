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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int s[90];
int n,l;
int cnt;

int dfs(int cur){
	if (cnt==n){
		for (int i=0;i<cur;i++) {
			if (i>=4 && i%4==0 && i%64!=0) cout << " ";
			if (i%64==0 && i) cout << "\n";
			printf("%c",s[i]+'A');
		}
		cout << "\n" << cur << "\n";
		return 0;
	}
	for (int i=0;i<l;i++){
		s[cur]=i;
		int ok=1;
		for (int j=1;2*j<=cur+1;j++){
			int flag=1;
			for (int k=0;k<j;k++){
				if (s[cur-k] != s[cur-k-j]){
					flag=0;break;
				}
			}
			if (flag) {
				ok=0;break;
			}
		}
		if (ok) {
			cnt++;
			if (!dfs(cur+1)) return 0;
		}
	}
	return 1;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
// 	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> l && (n||l)){
		cnt=0;
		dfs(0);
	}
	return 0;
}


