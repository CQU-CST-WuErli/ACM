//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
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
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
struct P
{
	int x1,y1,x2,y2;
	void read() {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1--,x2--,y1--,y2--;
	}
}pipe[20];
char mp[20][20];
int dis[20][20];

bool check(int x,int y) {
	if (x>=0 && x<n && y>=0 && y<n && mp[x][y]!='#') return true;
	return false;
}

struct Sta
{
	int x,y,dis;
	Sta(int x,int y,int dis):x(x),y(y),dis(dis){}
};
int vis[20][20];
int dir[4][2]={1,0,0,1,-1,0,0,-1};

int gao(P& a,P& b) {
	queue<Sta> q;
	CLR(vis);
	q.push(Sta(a.x2,a.y2,0));
	vis[a.x2][a.y2]=1;
	while(q.size()) {
		Sta now=q.front();q.pop();
		if (now.x==b.x1 && now.y==b.y1) return now.dis;
		for (int i=0;i<4;i++) {
			int tx=now.x+dir[i][0],ty=now.y+dir[i][1];
			if (check(tx,ty) && !vis[tx][ty]) {
				vis[tx][ty]=1;
				q.push(Sta(tx,ty,now.dis+1));
			}
		}
	}
	return -1;
}

int dp[1<<16][16];

int dfs(int S,int cnt) {
	if (S==(1<<m)-1) return 0;
	if (dp[S][cnt]!=-1) return dp[S][cnt];
	int &ret=dp[S][cnt];
	ret=INF_INT;
	for (int i=0;i<m;i++) {
		if (S&(1<<i) || dis[cnt][i]==-1) continue;
		ret=min(ret,dfs(S|(1<<i),i)+dis[cnt][i]);
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
    	for (int i=0;i<n;i++) scanf("%s",mp[i]);
    	for (int i=0;i<m;i++) pipe[i].read();
    	for (int i=0;i<m;i++) for (int j=0;j<m;j++) {
    		if (i==j) dis[i][j]=0;
    		else dis[i][j]=gao(pipe[i],pipe[j]);
    	}
    	// for (int i=0;i<m;i++) {
    	// 	for (int j=0;j<m;j++) cout << dis[i][j] << ' ';
    	// 	cout << endl;
    	// }
    	OFF(dp);
    	int ans=INF_INT;
    	for (int i=0;i<m;i++) ans=min(ans,dfs(1<<i,i));
    	if (ans>=INF_INT) cout << -1 << endl;
    	else cout << ans << endl;
    }
	return 0;
}