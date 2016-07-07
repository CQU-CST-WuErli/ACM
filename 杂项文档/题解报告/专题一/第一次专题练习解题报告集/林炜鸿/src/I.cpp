/*
SCU - 4502
����һ������ͼ����һ�����ֳ�
ÿ��һ����һ����ɫ��һ�������ɫѭ��
Ȼ�������ǰ����ת����ת������ʱ����ͬ
�տ�ʼ�泯���ߣ���ɫ����
�����յ����յ㣬����ɫ���µ����ʱ���Ƕ���

ûɶ��˵�ģ���λ�ã�����ʱ�䣬������ɫȫ������
Ȼ��ȫ���������ֱ�� bfs�����ܼ���
�ʵ������������ҵ�˳�򣬿��Լ��ٴ�����
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
const int dir[4][2]={-1,0,0,1,1,0,0,-1};
int M,N;
struct data
{
	int x,y,d,s,t;
	data(int tx,int ty,int td,int ts,int tt):x(tx),y(ty),d(td),s(ts),t(tt){};
};
char Map[60][60];
int vis[50][50][4][5];

int modu(int x, int MOD){x%=MOD;x+=MOD;x%=MOD;return x;}

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		MST(vis,0x3f);
		int sx,sy,tx,ty;
		scanf("%d%d", &M, &N);
		for(int i=1; i<=M; i++)
		{
			scanf(" %s", Map[i]+1);
			for(int j=1; j<=N; j++)
			{
				if(Map[i][j]=='S'){sx=i;sy=j;}
				if(Map[i][j]=='T'){tx=i;ty=j;}
			}
		}
		int ans=-1;
		queue<data> que;
		que.push(data(sx,sy,UP,0,0));
		while(que.size())
		{
			data &u=que.front();
			if(u.x==tx&&u.y==ty&&u.s==0)
			{
				ans=u.t;
				break;
			}
			int x=u.x+dir[u.d][0];
			int y=u.y+dir[u.d][1];
			int d0=modu(u.d+1,4), d1=modu(u.d-1,4);
			int s=modu(u.s+1,5);
			if( x>0 && y>0 && x<=M && y<=N && u.t+1<vis[x][y][u.d][s] && Map[x][y]!='#')
			{
				que.push(data(x,y,u.d,s,u.t+1));
				vis[x][y][u.d][s]=u.t+1;
			}
			if(u.t+1<vis[u.x][u.y][d0][u.s])
			{
				que.push(data(u.x,u.y,d0,u.s,u.t+1));
				vis[u.x][u.y][d0][u.s]=u.t+1;
			}if(u.t+1<vis[u.x][u.y][d1][u.s])
			{
				que.push(data(u.x,u.y,d1,u.s,u.t+1));
				vis[u.x][u.y][d1][u.s]=u.t+1;
			}
			que.pop();
		}
		printf("%d\n", ans);
	}
	return 0;
}


