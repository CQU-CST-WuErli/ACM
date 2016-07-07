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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int mp[110][110];
int dist[110][110][8];
// 0 上 1 下 2 左 3 右
// 4 左上 5 左下 6 右上 7 右下

int gao(int tx,int ty,int op) {
	int x=tx,y=ty;
	int ret=0;
	if (mp[x][y]==0) return 0;
	if (op==0) {
		while(x>=1 && mp[x][y]==1) x--,ret++;
	}
	else if (op==1) {
		while(x<=n && mp[x][y]==1) x++,ret++;
	}
	else if (op==2) {
		while(y>=1 && mp[x][y]==1) y--,ret++;
	}
	else if (op==3) {
		while(y<=n && mp[x][y]==1) y++,ret++;
	}
	else if (op==4) {
		while(x>=1 && y>=1 && mp[x][y]==1) x--,y--,ret++;
	}
	else if (op==5) {
		while(x<=n && y>=1 && mp[x][y]==1) x++,y--,ret++;
	}
	else if (op==6) {
		while(x>=1 && y<=n && mp[x][y]==1) x--,y++,ret++;
	}
	else if (op==7) {
		while(x<=n && y<=n && mp[x][y]==1) x++,y++,ret++;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n)==1 && n) {
    	CLR(mp);CLR(dist);
        rep(i,1,n) rep(j,1,n) {
        	char c;cin >> c;
        	if (c=='.') mp[i][j]=1;
        }
        // rep(i,0,7) dist[3][1][i]=gao(3,1,i);
        // rep(i,0,7) cout << dist[3][1][i] << endl;
        rep(i,1,n) rep(j,1,n) if (mp[i][j]) {
        	rep(k,0,7) dist[i][j][k]=gao(i,j,k);
        }
        int ans=0;
       	rep(i,1,n) rep(j,1,n) if (mp[i][j]) {
       		ans=max(dist[i][j][0]+dist[i][j][1],ans);
       		ans=max(dist[i][j][2]+dist[i][j][3],ans);
       		ans=max(dist[i][j][4]+dist[i][j][7],ans);
       		ans=max(dist[i][j][5]+dist[i][j][6],ans);
       		ans=max(dist[i][j][0]+dist[i][j][2],ans);ans=max(dist[i][j][0]+dist[i][j][3],ans);
       		ans=max(dist[i][j][1]+dist[i][j][2],ans);ans=max(dist[i][j][1]+dist[i][j][3],ans);
       		ans=max(dist[i][j][2]+dist[i][j][0],ans);ans=max(dist[i][j][2]+dist[i][j][1],ans);
       		ans=max(dist[i][j][3]+dist[i][j][0],ans);ans=max(dist[i][j][3]+dist[i][j][1],ans);
       		ans=max(dist[i][j][4]+dist[i][j][5],ans);ans=max(dist[i][j][4]+dist[i][j][6],ans);
       		ans=max(dist[i][j][5]+dist[i][j][4],ans);ans=max(dist[i][j][5]+dist[i][j][7],ans);
       		ans=max(dist[i][j][6]+dist[i][j][4],ans);ans=max(dist[i][j][6]+dist[i][j][7],ans);
       		ans=max(dist[i][j][7]+dist[i][j][5],ans);ans=max(dist[i][j][7]+dist[i][j][6],ans);
       	}
       	cout << ans-1 << endl;
    }
	return 0;
}