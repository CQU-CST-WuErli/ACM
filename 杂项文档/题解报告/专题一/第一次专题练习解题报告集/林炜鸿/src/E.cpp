/*
SCU - 4498
给定一张网格图，其中有一些不可到达点和一些时间重置装置
RunningPhoton从起点出发，身上有一个定时炸弹，当时间置 0时他就会死
但是在置 0前碰到时间重置装置又能重置时间
问是否能到达终点，若能，则输出最短时间，若不能，则输出 "Poor RunningPhoton"

这题虽然地图是有 600*600，但是有不超过 150个重置装置
普通 bfs搜的话肯定爆炸，因为你要存每个装置是否被用过了
因为我们只关心重置装置，起点，终点的位置
所以以每个重置装置及起点，终点作为起点都跑一次 bfs，
计算出两两间的最短距离后构一张图，将距离小于 K的连上边
最后再从起点跑一次 spfa即可

但是这题数据好像很水，用普通的 bfs也迷之能过
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DBL;
typedef long double LDBL;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) (a*a)

const int maxn=600+10,INF=0x3f3f3f3f;
const int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct data
{
	int x,y,t;
	data(int tx,int ty,int tt):x(tx),y(ty),t(tt){}
};
struct Edge{int u,v,w,nxt;};

int N,M,K,ncnt;
char Map[maxn][maxn];
int vis[maxn][maxn];
int posi[200][2];
int edn,last[maxn];
Edge edge[152*152+10];
int dist[200];
bool inq[200];

void adde(int,int,int);
void init(int,int,int);
int spfa(int,int);

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		edn=0;MST(last,-1);
		ncnt=0;
		int sx,sy,tx,ty;
		
		scanf("%d%d%d", &N, &M, &K);
		for(int i=1; i<=N; i++)
		{
			scanf(" %s", Map[i]+1);
			for(int j=1; j<=M; j++)
			{
				if(Map[i][j]=='R') {ncnt++;posi[ncnt][0]=i;posi[ncnt][1]=j;}
				if(Map[i][j]=='S') {sx=i;sy=j;}
				if(Map[i][j]=='E') {tx=i;ty=j;}
			}
		}
		ncnt++;
		posi[0][0]=sx; posi[0][1]=sy;
		posi[ncnt][0]=tx; posi[ncnt][1]=ty;
		for(int i=0; i<=ncnt; i++) init(i, posi[i][0], posi[i][1]);
//		for(int i=0; i<=ncnt; i++) printf("%d: %d %d\n", i, posi[i][0], posi[i][1]);
//		for(int i=0; i<edn; i++) printf("%d -> %d: %d\n", edge[i].u, edge[i].v, edge[i].w);

		int ans=spfa(0,ncnt);
		if(ans<INF) printf("%d\n", ans);
		else puts("Poor RunningPhoton!");
	}
	return 0;
}

void init(int np, int sx, int sy)
{
	MST(vis,0x3f);
	queue<data> que;
	que.push(data(sx, sy,0));
	vis[sx][sy]=0;

	while(que.size())
	{
		data &u=que.front();
		for(int d=0; d<4; d++)
		{
			int x=u.x+dir[d][0];
			int y=u.y+dir[d][1];
			if(x<=0||y<=0||x>N||y>M||u.t+1>=vis[x][y]||Map[x][y]=='W') continue;
			que.push(data(x,y,u.t+1));
			vis[x][y]=u.t+1;
		}
		que.pop();
	}
	for(int i=0; i<=ncnt; i++)
	{
		int x=posi[i][0], y=posi[i][1];
		if(i==np||vis[x][y]>=K) continue;
		adde(np,i,vis[x][y]);
	}
}

void adde(int u,int v,int w)
{
	edge[edn].u=u;
	edge[edn].v=v;
	edge[edn].w=w;
	edge[edn].nxt=last[u];
	last[u]=edn++;
}

int spfa(int S,int T)
{
	MST(dist,0x3f);
	CLR(inq);
	queue<int> que;
	que.push(S);
	dist[S]=0;
	inq[S]=1;
	
	while(que.size())
	{
		int u=que.front();
		for(int e=last[u]; ~e; e=edge[e].nxt)
		{
			int v=edge[e].v, w=edge[e].w;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if(!inq[v])
				{
					que.push(v);
					inq[v]=1;
				}
			}
		}
		inq[u]=0;
		que.pop();
	}
	return dist[T];
}
