///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by  Team 3 			                       //
//  Copyright (c) 2015年 Team 3. All rights reserved.  //
/////////////////////////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>           
#include <algorithm>
#include <cctype>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 10000
int n;
int d[1005];
int t;
bool connect[1005][1005];
struct edge
{
	int u,v,w;
}g[10000]; 

bool Bellman()
{
	memset(d,0x3f,sizeof(d));
	d[1]=-100;
	for (int i=1;i<=n;i++)
		for (int j=1;j<t;j++)
		{
			if(d[g[j].v]>d[g[j].u]+g[j].w && d[g[j].u]+g[j].w<0)
			{
				d[g[j].v]=d[g[j].u]+g[j].w;
				if (i==n && connect[1][g[j].v] && connect[g[j].v][n])      //当执行到第n次时已经全部更新过，只需找到一条通路及最短路。 
				return true;
			}
		}
	return false;
}
int main()
{
	while (cin >> n && n!=-1 )
	{
		t=1;
		CLR(g);
		memset(connect,false,sizeof(connect));
		for (int i=1;i<=n;i++) connect[i][i]=true;
		for (int i=1;i<=n;i++)
		{
			int cost,m,v;
			cin >> cost >> m;
			for (int j=1;j<=m;j++)
			{
				cin >> v;
				connect[i][v]=true;
				g[t].u=i;
				g[t].v=v;
				g[t].w=-cost;
				t++;
			} 
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
				if (connect[i][k]&&connect[k][j])
					connect[i][j]=true;
		if (connect[1][n])
		{
			if (Bellman() || d[n]<0) cout << "winnable\n";
			else cout << "hopeless\n";
		} 
		else 
			cout << "hopeless\n";
	} 
	return 0;
}

