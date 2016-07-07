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

char s[200010],t[200010];
int flag;

bool cmp(char x[],char y[],int len){
	int ok=1;
	for (int i=0;i<len;i++){
		if (x[i]!=y[i]) {
			ok=0;
		}
	} 
	return ok;
}

int dfs(char x[],char y[],int len){
	if (cmp(x,y,len)) return 1;
	if (len%2==0){
		if ((dfs(x,y,len/2) && dfs(x+len/2,y+len/2,len/2)) || (dfs(x,y+len/2,len/2) && dfs(x+len/2,y,len/2))) 
			return 1;
	}
	return 0;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (gets(s)){
		gets(t);
		int ls=strlen(s);
		if (dfs(s,t,ls)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


