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

const int N=100100;
int par[N*2],vis[N*2];
int flag;

void init(){
	for (int i=0;i<=100100*2;i++) {
		par[i]=i;
	}
	CLR(vis);
} 

int find(int x){
	if (par[x]==x) return x;
	else {
//		int tmp=x;
		while (par[x]!=x) x=par[x];
		return x;
	}
}

bool unite(int x,int y){
	vis[x]=vis[y]=1;
	x=find(x),y=find(y);
	if (x==y) return false;
	else {
		par[x]=y;
		return true;
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int a,b;
	while(cin >> a >> b){
		int maxn=0,minn=99999;
		if (a==-1 && b==-1) break;
		init();
		if (a==0 && b==0){
			cout << "Yes\n";
			continue;
		}
		maxn=max(maxn,max(a,b));minn=min(minn,min(a,b));
		int flag=0;
		if (!unite(a,b)) flag=1;
		while (scanf("%d%d",&a,&b)==2 && (a || b)){
			maxn=max(maxn,max(a,b));minn=min(minn,min(a,b));
			if (!unite(a,b)) flag=1;
		}
		if (flag) cout << "No\n";
		else {
			int sum=0;
			for (int i=minn;i<=maxn;i++){
				if (vis[i] && par[i]==i) sum++;
			}
			if (sum==1) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}
