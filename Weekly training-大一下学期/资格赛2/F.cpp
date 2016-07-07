//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
#define maxn 200010
int N;
int pnt[maxn],pre[maxn],head[maxn],w[maxn];
int cnt;
int vis[maxn],d[maxn];

void addedge(int u,int v,int cost){
	pnt[cnt]=v;w[cnt]=cost;pre[cnt]=head[u];head[u]=cnt++;
}

int spfa(){
	int mmax=0;
	queue<int> q;
	CLR(vis);
	memset(d,0,sizeof(d));
	d[1]=0;
	vis[1]=1;
	q.push(1);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=0;
		for (int i=head[x];i!=-1;i=pre[i]){
			int v=pnt[i];
			if (d[v]<d[x]+w[i]) {
				d[v]=d[x]+w[i];
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
				mmax=max(mmax,d[v]);
			}
		}
	}
	return mmax;
}
int main()
{
//	freopen ("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (cin >> N)
	{
		cnt=0;
		int sum=0;
		memset(pre,-1,sizeof(pre));
		memset(head,-1,sizeof(head));
		for (int i=1;i<=N-1;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
			sum+=z;
		}
		int ans=spfa();
//		cout << ans <<endl;
		cout << sum-ans << endl; 
	}
	return 0;
}


