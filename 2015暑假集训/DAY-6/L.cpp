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

int mp[8][8];
int vis[8][8];

typedef pair<int,int> P;

int dir[8][2]={1,2,2,1,-1,2,2,-1,1,-2,-2,1,-1,-2,-2,-1};

int bfs(P s,P e){
	if (s.first==e.first && s.second==e.second) return 0;
	CLR(mp);
	CLR(vis);
 	mp[s.first][s.second]=0;
	vis[s.first][s.second]=1;
	queue<P> q;
	q.push(P(s.first,s.second));
	while (!q.empty()){
		P tmp = q.front();q.pop();
		int x=tmp.first,y=tmp.second;
		if (x==e.first && y==e.second) return mp[x][y];
		for (int i=0;i<8;i++){
			int tx=x+dir[i][0],ty=y+dir[i][1];
			if (tx<0 || tx>=8 || ty<0 || ty>=8) continue;
			if (!vis[tx][ty]){
				vis[tx][ty]=1;
				mp[tx][ty]=mp[x][y]+1;
				q.push(P(tx,ty));
			}
		}
	} 
	return 0;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	string s;
	while (getline(cin,s)){
		int b1,b2,e1,e2;
		b1=s[0]-'a';b2=s[1]-'0'-1;e1=s[3]-'a';e2=s[4]-'0'-1;
//		cout << b1 <<" " <<  b2 << " " << e1 << " " <<e2 << endl;
		P beg,end;
		beg.first=b1;beg.second=b2;end.first=e1;end.second=e2;
		cout << "To get from "<< s[0] << s[1]  << " to " << s[3] << s[4]  << " takes " << bfs(beg,end) << " knight moves." <<endl;
	}
	return 0;
}


