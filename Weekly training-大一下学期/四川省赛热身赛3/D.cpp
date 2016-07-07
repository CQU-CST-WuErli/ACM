//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
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
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
const int maxn=110;
int op;
ll x,y;
int d[maxn][maxn];
int dp[maxn][maxn];
int n,cnt;
pair<int,int> es[maxn*2];

void bfs(int s){
	d[s][s]=0;
	memset(dp,0x3f3f3f3f,sizeof dp);
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x=q.front();q.pop();
		for (int i=1;i<=cnt;i++){
			if (d[x][i] && dp[s][i]==0x3f3f3f3f )
				dp[s][i]=dp[x][i]+1;
				q.push(i);
		}
	}
}

int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF){
		cnt=0;
		memset(d,0,sizeof(d));
		for (int i=1;i<=n;i++){
			int op;
			ll u,v;
			scanf("%d%I64d%I64d",&op,&x,&v);
			if (op==1){
				es[++cnt].first=x;es[cnt].second=v;
				if (cnt>1){
					for (int j=1;j<cnt;j++){
						 if(es[cnt].first > es[j].first && es[cnt].first < es[j].second
                                || es[cnt].second > es[j].first && es[cnt].second < es[j].second)
                            d[cnt][j] = 1;
                        if(es[j].first > es[cnt].first && es[j].first < es[cnt].second
                                || es[j].second > es[cnt].first && es[j].second < es[cnt].second)
                            d[j][cnt] = 1;
					}
				}
			}
			else {
				bfs(x);
				if (dp[u][v]==0x3f3f3f3f) printf("NO\n");
				else printf("YES\n");
			}
		}
	}
	return 0;
}


