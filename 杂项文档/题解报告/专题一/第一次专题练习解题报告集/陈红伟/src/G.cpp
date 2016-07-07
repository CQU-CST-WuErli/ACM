//  Created by Chenhongwei on 2016-05-07 Saturday 21:09
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
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
bool num[20],vis[5500];
int n,c,m;
struct node
{
	int len;
	int s[550];
};
int mod(node p)
{
	int ret=0;
	for(int i=0;i<p.len;i++)
		ret=(ret*c+p.s[i])%n;
	return ret;
}
void print(node p)
{
	for(int i=0;i<p.len;i++)
		if(p.s[i]<10)
			printf("%d",p.s[i]);
		else
			printf("%c",'A'+(p.s[i]-10));
	printf("\n");
}
bool bfs()
{
	memset(vis,0,sizeof vis);
	queue<node> q;
	node p;
	p.len=0;
	int r;
	for(int i=1;i<16;i++)
		if(num[i])
		{
			p.len=1;
			p.s[0]=i;
			r=mod(p);
			if(!r)
			{
				print(p);
				return 1;
			}
			else if(!vis[r])
			{
				vis[r]=1;
				q.push(p);
			}
		}
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(int i=0;i<16;i++)
			if(num[i])
			{
				p.s[p.len]=i;
				p.len++;
				r=mod(p);
				if(!r)
				{
					print(p);
					return 1;
				}
				else if(!vis[r]&&p.len<499)
				{
					vis[r]=1;
					q.push(p);
				}
				p.len--;
			}
	}
	return 0;
}
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	char str[5];
	while(T--)
	{
		scanf("%d%d%d",&n,&c,&m);
		memset(num,0,sizeof num);
		for(int i=1;i<=m;i++)
		{
			scanf("%s",str);
			if(str[0]>='0'&&str[0]<='9')
				num[str[0]-'0']=1;
			else
				num[str[0]-'A'+10]=1;
		}
		if(n)
		{
			bool flag=bfs();
			if(!flag)
				puts("BOMB!!!");
		}
		else
		{
			if(num[0])
				printf("0\n");
			else
				puts("BOMB!!!");
		}
	}
	return 0;
}
