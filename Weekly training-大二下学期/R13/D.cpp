/*  ^^ ====== ^^
ID: meixiuxiu
PROG: test
LANG: C++11
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
#define pi acos(-1.0)
#define maxn 40000
#define maxv 100005
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int sx,sy,tx,ty;
int n,m;
char mp[101][101];
int id[110][110];
bool vis[101][101][11][50];
int dp[110][110][11][50];
int fx[4]={-1,1,0,0};
int fy[4]={0,0,-1,1};

int cnt;

struct Sta
{
	int x,y,c,sta;
	Sta(int x,int y,int c,int sta):x(x),y(y),c(c),sta(sta){}
};

bool check(int x,int y){
	if(x<n && y <n && x>=0 && y>=0 && mp[x][y]!='#'){
		return 1;
	}
	else return 0;
}

int bfs() {
	queue<Sta> q;
	MEM(vis,0);
	MEM(dp,inf);
	q.push(Sta(sx,sy,0,0));
	dp[sx][sy][0][0]=0;
	vis[sx][sy][0][0]=1;
	while(q.size()) {
	    Sta now=q.front();q.pop();
	    for (int i=0;i<4;i++) {
	    	int nx=now.x+fx[i],ny=now.y+fy[i];
	    	if (check(nx,ny)) {
	    		if (mp[nx][ny]-'0'==now.c+1) {
	    			if (dp[nx][ny][now.c+1][now.sta]>dp[now.x][now.y][now.c][now.sta]+1) {
	    				dp[nx][ny][now.c+1][now.sta]=dp[now.x][now.y][now.c][now.sta]+1;
	    				if (!vis[nx][ny][now.c+1][now.sta]) {
	    					q.push(Sta(nx,ny,now.c+1,now.sta));
	    					vis[nx][ny][now.c+1][now.sta]=1;
	    				}
	    			}
	    		}
	    		else if (mp[nx][ny]=='S') {
	    			int tmp=now.sta|(1<<id[nx][ny]);
	    			if (dp[nx][ny][now.c][tmp]>dp[now.x][now.y][now.c][now.sta]+(tmp==now.sta?1:2)) {
	    				dp[nx][ny][now.c][tmp]=dp[now.x][now.y][now.c][now.sta]+(tmp==now.sta?1:2);
	    				if (!vis[nx][ny][now.c][tmp]) {
	    					q.push(Sta(nx,ny,now.c,tmp));
	    					vis[nx][ny][now.c][tmp]=1;
	    				}
	    			}
	    		}
	    		else{
	    			if (dp[nx][ny][now.c][now.sta]>dp[now.x][now.y][now.c][now.sta]+1) {
	    				dp[nx][ny][now.c][now.sta]=dp[now.x][now.y][now.c][now.sta]+1;
	    				if (!vis[nx][ny][now.c][now.sta]) {
	    					q.push(Sta(nx,ny,now.c,now.sta));
	    					vis[nx][ny][now.c][now.sta]=1;
	    				}
	    			}
	    		}
	    	}
	    }
	}
	int ans=inf;
	for (int i=0;i<(1<<cnt);i++) ans=min(ans,dp[tx][ty][m][i]);
	return ans;
}

int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(cin >> n >> m && (n+m)){
		cnt=0;
		for(int i=0;i<n;i++){
			scanf("%s",mp[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(mp[i][j]=='K')sx = i, sy = j;
				else if(mp[i][j]=='T')tx = i, ty = j;
				else if(mp[i][j]=='S') id[i][j]=cnt++;
			}
		}
		// cout << sx <<  ' ' << sy << endl;
		int ans=bfs();
		if (ans>=inf) puts("impossible");
		else cout << ans << endl;
	}
	return 0;
}
