//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct P{
	int x,y;
	int dis;
	bool operator == (const P& rhs) const {
		return x==rhs.x && y==rhs.y;
	}
};
int r,c,Cost;
string mp[5003];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
bool vis[5003][5003];

bool check(int i,int j){
	if (i<0 || j<0 || i>=r || j>=c || mp[i][j]=='#') return false;
	return true;
}

int bfs(P st,P ed){
	CLR(vis);
	P now,tmp,tt;
	queue<P> q;
	st.dis=0;
	q.push(st);
	vis[st.x][st.y]=1;
	while (!q.empty()){
		now=q.front(); q.pop();
		if (now==ed) return now.dis;
		for (int i=0;i<4;i++){
			int tx=now.x+dir[i][0],ty=now.y+dir[i][1];
			if (!vis[tx][ty] && check(tx,ty)){
				vis[tx][ty]=1;
				tmp.x=tx;tmp.y=ty;
				tmp.dis=now.dis+(mp[tx][ty]=='*'?Cost:0);
				q.push(tmp);
				if (mp[tx][ty]=='P'){
					for (int s=0;s<r;s++) for (int t=0;t<c;t++){
						if ((s!=tmp.x || t!=tmp.y) && mp[s][t]=='P') {
							tt.x=s;tt.y=t;tt.dis=tmp.dis;
							q.push(tt);
							vis[s][t]=1;
						}
					}
				}
			} 
		}
	}
	return -1;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SIII(r,c,Cost)==3){
//		getchar();
		P start,end;
		for (int i=0;i<r;i++) cin >> mp[i];
		for (int i=0;i<r;i++) for (int j=0;j<c;j++){
			if (mp[i][j]=='Y') {
				start.x=i;start.y=j;
			}
			else if (mp[i][j]=='C'){
				end.x=i;end.y=j;
			}
		}
		int ans=bfs(start,end);
		if (ans==-1) cout << "Damn teoy!\n";
		else cout << ans << endl;
	}
	return 0;
}
