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
#define BUG(x) printf("In line x\n")
#define seevalue(x) printf("x=%d\n",x)
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;
typedef pair<int,int> P;
int m[5][5];
int dir[4][2]={1,0,0,1};
int d[5][5],vis[5][5];
P pre[5][5];



void bfs(){
	CLR(vis);
	vis[0][0]=d[0][0]=1;
	queue<P> q;
	q.push(P(0,0));
	while (!q.empty()){
		P x=q.front();q.pop();
		int tx=x.first,ty=x.second;
		if (tx==4 && ty==4) return ; 
		for (int i=0;i<2;i++) {
			int nx=tx+dir[i][0],ny=ty+dir[i][1];
			if (nx<0 || ny<0 || nx>=5 || ny>=5 || m[nx][ny]) continue;
			m[nx][ny]=1;
			d[nx][ny]=d[tx][ty]+1;
			pre[nx][ny]=P(tx,ty);
			q.push(P(nx,ny));
		}
	}
}


int main(){
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	for (int i=0;i<=4;i++)
		for (int j=0;j<5;j++)
			cin >> m[i][j];
	bfs();
	deque<P> q;
	q.push_front(P(4,4));
	P now=pre[4][4];
	while (1){
		q.push_front(now);
		if (now.first==0 && now.second==0) break;
		now=pre[now.first][now.second];
	} 
	while (q.size()){
		P x=q.front();q.pop_front();
		cout << "(" << x.first << ", " << x.second << ")\n";
	}
	return 0;
}

