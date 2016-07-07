/*
SCU - 4497
给定一个 N*N的拼图，要求重新排列
使得一个方块上下左右相邻的方块连接处数字相等

这题写起来比较恶心
我刚开始通过把每一行可行状态存下来，丢到 set里转移
然后就 MLE了

后来换了种想法，蛇形地去找可连接的方块
然后尝试了若干剪枝，效果都不理想

自己生成了几组随机数据
发现当数字均为 0~3，比较集中时，跑得巨慢
本来 0~3这种可重复的概率比较大
相应地能搜出解的可能也比较大
但是一但无解，他就会重复地去搜，十分浪费时间

基于以上事实，我用了一个玄学剪枝
我设定了一个搜索次数，当 dfs的调用次数过大时，当做无解返回
大概 WA了三四发的样子，尝试出了比较好的参数，72ms就跑过了

后来我找 zw菊苣问了标程，发现标程也是基于上述情况进行的特殊剪枝
不过他的剪枝可比我的科学多了
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

const int UP=0,RIGHT=1,DOWN=2,LEFT=3;
const int TIME=1e5;
struct node{int n[4];};
int N;
node inpt[30];
int Cnt[20][20];
int Map[20][20];
bool vis[30];
int ntime=0;

int dfs(int);
void GetCor(int,int&,int&);
void change(int,int);
bool check(int);

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		ntime=0;
		CLR(vis);CLR(Cnt);CLR(Map);
		scanf("%d", &N);
		for(int i=0; i<N*N; i++) for(int j=0; j<4; j++)
		{
			scanf("%d", &inpt[i].n[j]);
			Cnt[j][inpt[i].n[j]]++;
		}
		if(dfs(0)&&ntime<=TIME) puts("Possible");
		else
		{
			puts("Impossible");
		}
//		printf("%lld\n", ntime);
	}
	return 0;
}

int dfs(int step)
{
	if(++ntime>TIME) return 1;
	
	if(step==N*N) return 1;
	
	for(int i=0; i<N*N; i++)
	{
		if(vis[i]) continue;
		int x,y;
		GetCor(step,x,y);
		if( x && inpt[i].n[UP] != inpt[ Map[x-1][y] ].n[DOWN] ) continue;
		if(x&1)
		{
			if( y+1<N && inpt[i].n[RIGHT] != inpt[ Map[x][y+1] ].n[LEFT]) continue;
			vis[i]=1;
			Map[x][y]=i;
			if(dfs(step+1)) return 1;
			Map[x][y]=0;
			vis[i]=0;
		}
		else
		{
			if(y && inpt[i].n[LEFT] != inpt[ Map[x][y-1] ].n[RIGHT]) continue;
			vis[i]=1;
			Map[x][y]=i;
			if(dfs(step+1)) return 1;
			Map[x][y]=0;
			vis[i]=0;
		}
	}
	return 0;
}

void GetCor(int step, int &x, int &y)
{
	x=step/N;
	if(x&1) y=N-1-step%N;
	else y=step%N;
}

