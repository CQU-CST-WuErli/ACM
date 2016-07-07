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
#include <sstream>
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
//#define root 1,n,1
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int mid[10010];
int suf[10010];
int tree[536619999];

int cnt1,cnt2;

void build(int x1, int x2, int y1, int y2, int num){
	if (x1>x2 ){
		return;
	}
	int root=suf[y2];
	tree[num]=root;
	int cnt=x1;
	while (mid[cnt]!=root) cnt++;    
	int p=cnt-x1;
	build(x1,cnt-1,y1,y1+p-1,num*2);
	build(cnt+1,x2,y1+p,y2-1,num*2+1);
	return ;
}


ll minsum;
int ans;
void dfs(int u, ll sum){
	sum+=tree[u];
	if (tree[u*2]==-1 && tree[u*2+1]==-1) {
		if (sum<minsum){
			minsum=sum;
			ans=tree[u];
		}
	}
	if (tree[u*2]>=0) dfs(u*2,sum);
	if (tree[u*2+1]>=0) dfs(u*2+1,sum);
}


int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	string s,t;
	while (getline(cin,s)){
		memset(tree,-1,sizeof tree);
		stringstream ss(s);
		int x;
		cnt1=0;
		while (ss >> x) mid[cnt1++]=x;
//		for (int i=0;i<cnt1;i++)  cout << mid[i] << " ";
//		cout  << endl;
		getline(cin,t);
		stringstream ts(t);
		cnt2=0;
		while (ts>> x) suf[cnt2++]=x;
		build(0,cnt1-1,0,cnt2-1,1);
		ans=0;
//		for (int i=1;i<=15;i++) cout << tree[i] << " ";
//		cout << endl;	
		minsum=0x3f3f3f3f;
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}


