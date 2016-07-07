//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin)
#define BUG(x) puts("In line x\n")
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;

const int N=1e5+10;
int n,q;
int sum[N*3],cover[N*3];

void push_up(int rt){
	sum[rt]=sum[rt<<1] + sum[rt<<1|1]; 
}

int push_down(int rt,int m){
	if (cover[rt]){
		cover[rt<<1] = cover [rt<<1|1] = cover[rt];
		sum[rt<<1] = cover[rt] * (m- (m >> 1));
		sum[rt<<1|1] = cover[rt] * (m>>1);
		cover[rt] = 0;
	}
}

void build(int l,int r,int rt){
	cover[rt] = 0;
	if (l==r) {
		sum[rt]=1;
		return;
	}
	int m=l+r>>1;
	build(lson);
	build(rson);
	push_up(rt);
}

void update(int L,int R,int v,int l,int r,int rt){
	if (L<=l && r<=R){
		cover[rt] = v;
		sum[rt] = v*(r-l+1);
		return;
	}
	int m=l+r>>1;
	push_down(rt,r-l+1);
	if (L<=m) update(L,R,v,lson);
	if (R>m)  update(L,R,v,rson);
	push_up(rt); 
}

int query(int L,int R,int l,int r,int rt){
	int ret=0;
	if (L<=l && r<=R){
		return sum[rt];
	}
	int m=l+r>>1;
	push_down(rt,r-l+1);
	if (L<=m) ret+=query(L,R,lson);
	if (r>m)  ret+=query(L,R,rson);
	push_up(rt);
	return ret;
}

int main(){
	int t;
	cin >> t;
	for (int kase = 1;kase <= t;kase++){
		scanf("%d%d",&n,&q);
		build(root);
		while (q--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			update(a,b,c,root);
		}
		printf("Case %d: The total value of the hook is %d.\n",kase,sum[1]);
	}
	return 0;
}

