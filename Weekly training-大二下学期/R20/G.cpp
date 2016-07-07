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

const int maxn=1e2+10,maxm=1e3+10,maxt=310,INF=0x3f3f3f3f;
int N,M,L,S,E;
int inpt[maxn][2];
int dist[maxn][maxn];
Pii desc[maxn];

int dp[maxn][maxt];

bool pcmp(Pii u, Pii v){return u.second<v.second;}

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		MST(dist,0x3f);CLR(desc);CLR(inpt);CLR(dp);
		scanf("%d%d%d%d%d", &N, &M, &L, &S, &E);
		for(int i=0; i<N; i++) scanf("%d", &inpt[i][0]);
		for(int i=0; i<N; i++) scanf("%d", &inpt[i][1]);
		for(int i=0; i<M; i++)
		{
			int u,v,w;
			scanf("%d%d%d", &u, &v, &w);
			dist[u][v]=min(dist[u][v], w);
			dist[v][u]=min(dist[v][u], w);
		}

		for(int i=0; i<N; i++) dist[i][i]=0;
		for(int k=0; k<N; k++) for(int i=0; i<N; i++) for(int j=0; j<N; j++)
		dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);

//		for(int i=0; i<N; i++)
//		{
//			for(int j=0; j<N; j++)
//			{
//				printf("%d ", dist[i][j]);
//			}
//			puts("");
//		}

		if(dist[S][E]>L){puts("0");continue;}
		for(int i=0; i<N; i++)
		{
			desc[i].first=i;
			desc[i].second=inpt[i][1];
		}
		sort(desc,desc+N,pcmp);
		for(int i=0; i<N; i++)
		{
			int id=desc[i].first;
			int nt=L-dist[S][id]-inpt[id][0];
			if(nt<0) continue;
			dp[i][nt]=inpt[id][1];
			for(int j=0; j<i; j++)
			{
				int id1=desc[j].first;
				if(inpt[id1][1]>=inpt[id][1]) break;
				for(int k=L; k>=inpt[id][0]; k--)
				{
					nt=k-dist[id][id1]-inpt[id][0];
					if(nt<0) break;
					if(!dp[j][k]) continue;
					dp[i][nt]=max(dp[i][nt], dp[j][k]+inpt[id][1]);
				}
			}
		}
		int ans=0;
		for(int i=0; i<N; i++)
		{
			int id=desc[i].first;
			if(L-dist[id][E]<0) continue;
			for(int j=dist[id][E]; j<=L; j++)
			{
//				if(id==3) printf("%d %d\n", j, dp[i][j]);
				ans=max(ans, dp[i][j]);
			}
		}
		printf("Case #%d:\n", ck);
		printf("%d\n", ans);
	}
	return 0;
}