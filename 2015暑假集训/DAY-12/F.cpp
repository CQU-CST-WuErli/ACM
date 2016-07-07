//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
//
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
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


int n;
int sti[100];
int maxd;
int ans[110];
int vis[100];
int sum;
bool cmp (int a, int b){
	return a>b;
}


// 当前长度   从某一个开始寻找    已经找到多少个 
bool dfs(int cur,int pos,int num){     
	if (maxd*num==sum) return true;
	for (int i=pos;i<n;i++){
		if (vis[i] || (i>0 && !vis[i-1] && sti[i-1]==sti[i])) continue;  //  a special prune. if the current stick was not be used before ,then we can't use it
		if (cur+sti[i]==maxd) {
			vis[i]=true;
			if (dfs(0,0,num+1)) return true;
			vis[i]=false; 
			return false;
		}
		else if (cur+sti[i]<maxd){
			vis[i]=true;
			if (dfs(cur+sti[i],i+1,num)) return true;
			vis[i]=false;
			if (cur==0) return false;     // this condition means that although we have searhed the longest stick that we cannot match the maxd
		}
	}
	return false;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n && n){
		sum=0;
		for (int i=0;i<n;i++) {
			cin >> sti[i];
			sum+=sti[i];
		}
		sort(sti,sti+n,cmp);
		int maxlen=*max_element(sti,sti+n);
		for (maxd=maxlen;maxd<sum;maxd++){
			if (sum%maxd==0){
				CLR(vis);
				if (dfs(0,0,0)) break;
			}
		}
		cout << maxd << endl;
//		for (int i=0;i<n;i++) cout << sti[i] << endl;
	}
	return 0;
}


