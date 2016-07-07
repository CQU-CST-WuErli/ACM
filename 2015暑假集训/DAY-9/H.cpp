//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//  26/07/15 19:4626/07/15 19:46
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

struct P{
	int v[3];
	int dis;
}; 

int pos;
int vol[3],maxv;
int vis[210][210],ans[210];
int t;

void init(){
	memset(vis,0x3f,sizeof(vis));
	memset(ans,-1,sizeof(ans));
}

void update_ans(P u){
	for (int i=0;i<3;i++){
		int d=u.v[i];
		if (ans[d]<0 || u.dis<ans[d]) ans[d]=u.dis;
 	}
}

void spfa(){
	deque<P> dq;
	P start;
	start.dis=0;
	start.v[0]=0;start.v[1]=0;start.v[2]=vol[2];
	dq.push_back(start);
	vis[0][0]=0;
	while (!dq.empty()){		
		P now=dq.front();dq.pop_front();
		P state;
		update_ans(now);
		int cup[3];
		for (int i=0;i<3;i++)  cup[i]=now.v[i];
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++){
				if (i==j) continue;
				int amount=min(vol[j],cup[i]+cup[j])-cup[j];
				memcpy(&state,&now,sizeof(now));
				state.v[i]-=amount;
				state.v[j]+=amount;
				state.dis=now.dis+amount;
				if (vis[state.v[0]][state.v[1]]>state.dis){
					vis[state.v[0]][state.v[1]]=state.dis;
					P tmp=dq.front();
					if (tmp.dis>state.dis) dq.push_front(state);
					else dq.push_back(state);
				}
			} 
	}
	while (ans[maxv]<0) maxv--;
	printf("%d %d\n",ans[maxv],maxv);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	while (t--){
		init();
		for (int i=0;i<3;i++) scanf("%d",vol+i);
		scanf("%d",&maxv);
		spfa();
	}
	return 0;
}


