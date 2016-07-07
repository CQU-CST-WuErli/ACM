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
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Pow2(a) a*a
int maxx(int a,int b){return a>b?a:b;}
int minn(int a,int b){return a<b?a:b;}
int abss(int a){return a<0?(-a):a;}

const int dir[4][2]={0,1,0,-1,1,0,-1,0};
const int INF=0x3f3f3f3f;

int N,M,K;
int Map[210][210];
int inpt[20],otd[20],ind[20];
int dp[14][1<<14];

int dist[20][20];
int ndist[41000];
bool inq[41000];

int DP(int,int);

int main()
{
	#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		MST(dist,0x3f);MST(otd,0x3f);MST(ind,0x3f);MST(dp,-1);
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) scanf("%d", &Map[i][j]);

//		for(int i=0; i<N; i++) for(int j=0; j<M; j++) {int id=i*M+j;dist[id][id]=0;}
//		for(int k=0; k<N*M; k++) for(int i=0; i<N*M; i++) for(int j=0; j<N*M; j++)
//		dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);

		scanf("%d", &K);
		for(int i=0; i<K; i++)
		{
			int x,y,id;
			scanf("%d%d", &x, &y);
			id=x*M+y;
			inpt[i]=id;
			CLR(inq);MST(ndist,0x3f);
			queue<int> que;//printf("%d\n", id);
			ndist[id]=0;
			inq[id]=1;
			que.push(id);
			while(!que.empty())
			{
				int nid=que.front();que.pop();
				int nx=nid/M,ny=nid%M;//printf("%d %d %d\n", nid, nx, ny);
				for(int k=0; k<4; k++)
				{
					int tx=nx+dir[k][0];
					int ty=ny+dir[k][1];
					if(tx<0||ty<0||tx>=N||ty>=M||Map[tx][ty]==-1) continue;
					int tid=tx*M+ty;
					if(ndist[tid]>ndist[nid]+Map[tx][ty])
					{
						ndist[tid]=ndist[nid]+Map[tx][ty];
						if(!inq[tid])
						{
							que.push(tid);
							inq[tid]=1;
						}
					}
				}
				inq[nid]=0;
			}
			for(int k=0; k<M; k++)
			{
				int id1=k,id2=(N-1)*M+k;
				ind[i]=min(ind[i], ndist[id1]+Map[x][y]);
				ind[i]=min(ind[i], ndist[id2]+Map[x][y]);
				otd[i]=min(otd[i], ndist[id1]);
				otd[i]=min(otd[i], ndist[id2]);
			}
			for(int k=0; k<N; k++)
			{
				int id1=k*M,id2=k*M+M-1;
				ind[i]=min(ind[i], ndist[id1]+Map[x][y]);
				ind[i]=min(ind[i], ndist[id2]+Map[x][y]);
				otd[i]=min(otd[i], ndist[id1]);
				otd[i]=min(otd[i], ndist[id2]);
			}
			for(int k=0; k<i; k++)
			{
				dist[i][k]=ndist[inpt[k]];
				dist[k][i]=ndist[inpt[k]]+Map[x][y]-Map[inpt[k]/M][inpt[k]%M];
//				printf("%d\n", ndist[inpt[k]]);
			}

		}
//		for(int i=0; i<K; i++) printf("%d %d\n", ind[i], otd[i]);
//		printf("%d %d\n", dist[0][1], dist[1][0]);
//		system("pause");
		int ans=INF;
		for(int i=0; i<K; i++)
		{
//			printf("%d\n", ind[inpt[i]]);
			ans=min(ans, DP(i,1<<i)+ind[i]);
//			printf("out: %d\n", ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}

int DP(int u, int mask)
{
	if(mask==(1<<K)-1) return otd[inpt[u]];
	if(~dp[u][mask]) return dp[u][mask];
	dp[u][mask]=INF;
//	printf("%d\n", u);
	for(int i=0; i<K; i++)
	{
		if(mask&(1<<i)) continue;
		dp[u][mask]=min(dp[u][mask], DP(i, mask|(1<<i))+dist[u][i]);
//		printf("%d->%d: %d\n", u, i, dp[u][mask]);
	}
	return dp[u][mask];
}
