//  Created by Chenhongwei on 2016-05-06 Friday 18:52
//  Copyright (c) 2016 Chenhongwei. All rights reserved.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int inf=1e9;
const int mod=1e9+7;
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
char s[55][55];
int dp[55][55][5][6];
bool f[55][55][5][6];
struct node
{
	int x,y,dir,c;//1 up 2 left 3 down 4 right
};
int m,n;
bool check(int x,int y)
{
	if(x>=1&&x<=m&&y>=1&&y<=n&&s[x][y]!='#')
		return true;
	return false;
}
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int sx,sy,ex,ey;
		scanf("%d%d",&m,&n);
		for(int i=1;i<=m;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=n;j++)
				if(s[i][j]=='S')
					sx=i,sy=j;
				else if(s[i][j]=='T')
					ex=i,ey=j;
		}
		memset(dp,0x3f,sizeof dp);
		memset(f,0,sizeof f);
		dp[sx][sy][1][0]=0;
		f[sx][sy][1][0]=1;
		queue<node> q;
		node p,np;
		p.x=sx,p.y=sy,p.dir=1,p.c=0;
		q.push(p);
		while(!q.empty())
		{
			p=q.front();
			f[p.x][p.y][p.dir][p.c]=0;
			// cout<<p.x<<' '<<p.y<<' '<<p.dir<<endl;
			q.pop();
			if(p.dir==1)
			{
				if(check(p.x-1,p.y)&&dp[p.x-1][p.y][1][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+1)
				{
					dp[p.x-1][p.y][1][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+1;
					if(!f[p.x-1][p.y][1][(p.c+1)%5])
					{
						np.x=p.x-1,np.y=p.y,np.dir=1,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y-1)&&dp[p.x][p.y-1][2][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x][p.y-1][2][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x][p.y-1][2][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y-1,np.dir=2,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x+1,p.y)&&dp[p.x+1][p.y][3][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+3)
				{
					dp[p.x+1][p.y][3][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+3;
					if(!f[p.x+1][p.y][3][(p.c+1)%5])
					{
						np.x=p.x+1,np.y=p.y,np.dir=3,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y+1)&&dp[p.x][p.y+1][4][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x][p.y+1][4][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x][p.y+1][4][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y+1,np.dir=4,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
			}
			else if(p.dir==2)
			{
				if(check(p.x-1,p.y)&&dp[p.x-1][p.y][1][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x-1][p.y][1][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x-1][p.y][1][(p.c+1)%5])
					{
						np.x=p.x-1,np.y=p.y,np.dir=1,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y-1)&&dp[p.x][p.y-1][2][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+1)
				{
					dp[p.x][p.y-1][2][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+1;
					if(!f[p.x][p.y-1][2][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y-1,np.dir=2,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x+1,p.y)&&dp[p.x+1][p.y][3][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x+1][p.y][3][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x+1][p.y][3][(p.c+1)%5])
					{
						np.x=p.x+1,np.y=p.y,np.dir=3,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y+1)&&dp[p.x][p.y+1][4][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+3)
				{
					dp[p.x][p.y+1][4][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+3;
					if(!f[p.x][p.y+1][4][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y+1,np.dir=4,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
			}
			else if(p.dir==3)
			{
				if(check(p.x-1,p.y)&&dp[p.x-1][p.y][1][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+3)
				{
					dp[p.x-1][p.y][1][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+3;
					if(!f[p.x-1][p.y][1][(p.c+1)%5])
					{
						np.x=p.x-1,np.y=p.y,np.dir=1,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y-1)&&dp[p.x][p.y-1][2][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x][p.y-1][2][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x][p.y-1][2][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y-1,np.dir=2,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x+1,p.y)&&dp[p.x+1][p.y][3][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+1)
				{
					dp[p.x+1][p.y][3][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+1;
					if(!f[p.x+1][p.y][3][(p.c+1)%5])
					{
						np.x=p.x+1,np.y=p.y,np.dir=3,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y+1)&&dp[p.x][p.y+1][4][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x][p.y+1][4][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x][p.y+1][4][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y+1,np.dir=4,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
			}
			else if(p.dir==4)
			{
				if(check(p.x-1,p.y)&&dp[p.x-1][p.y][1][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x-1][p.y][1][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x-1][p.y][1][(p.c+1)%5])
					{
						np.x=p.x-1,np.y=p.y,np.dir=1,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y-1)&&dp[p.x][p.y-1][2][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+3)
				{
					dp[p.x][p.y-1][2][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+3;
					if(!f[p.x][p.y-1][2][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y-1,np.dir=2,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x+1,p.y)&&dp[p.x+1][p.y][3][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+2)
				{
					dp[p.x+1][p.y][3][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+2;
					if(!f[p.x+1][p.y][3][(p.c+1)%5])
					{
						np.x=p.x+1,np.y=p.y,np.dir=3,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
				if(check(p.x,p.y+1)&&dp[p.x][p.y+1][4][(p.c+1)%5]>dp[p.x][p.y][p.dir][p.c]+1)
				{
					dp[p.x][p.y+1][4][(p.c+1)%5]=dp[p.x][p.y][p.dir][p.c]+1;
					if(!f[p.x][p.y+1][4][(p.c+1)%5])
					{
						np.x=p.x,np.y=p.y+1,np.dir=4,np.c=(p.c+1)%5;
						f[np.x][np.y][np.dir][np.c]=1;
						q.push(np);
					}
				}
			}

		}
		int ans=dp[ex][ey][1][0];
		for(int i=2;i<=4;i++)
			ans=min(ans,dp[ex][ey][i][0]);
		if(ans>1e9)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
