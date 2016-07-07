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

int n;
int data[20];
int vis[20];
int isprime[40];

void dfs(int cnt){
	if (cnt==n && isprime[data[0]+data[n-1]]){ 
		for (int i=0;i<n;i++){
			printf("%d",data[i]);
			if (i<n-1) cout << ' ';
			else cout << endl;
		}
	}
	else {
		for (int i=2;i<=n;i++){
			if (isprime[i+data[cnt-1]] && !vis[i]) {
				vis[i]=1;
				data[cnt]=i;
				dfs(cnt+1);
				vis[i]=0;
			}
		}
	}
} 
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	CLR(isprime);
	isprime[2]=1;isprime[3]=1;isprime[5]=1;isprime[7]=1;isprime[11]=1;
	isprime[13]=1;isprime[17]=1;isprime[19]=1;isprime[23]=1;isprime[29]=1;
	isprime[31]=1;isprime[39]=1;
	CLR(vis);
	int kase=1;
	while (scanf("%d",&n)!=EOF){
		if (kase!=1) cout << endl;
		cout << "Case " << kase++ << ":\n";
		data[0]=1;
		dfs(1);
//		cout << endl;
	}
	return 0;
}
