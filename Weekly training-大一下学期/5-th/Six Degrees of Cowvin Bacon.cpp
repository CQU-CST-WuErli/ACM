///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by  Team 3 			                       //
//  Copyright (c) 2015Äê Team 3. All rights reserved.  //
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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
int N,M,m=0;
#define maxn 400
int d[maxn][maxn]; 
int a[maxn];

void floyd()
{
	for (int k=1;k<=N;k++)
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
	while (cin >> N >> M)
	{
		for (int i=1;i<=maxn;i++)
			for (int j=1;j<=maxn;j++)
				d[i][j]=i==j?0:INF;
		for (int i=1;i<=M;i++)
		{
			int n;
			cin >> n;
			for (int i=1;i<=n;i++)
				cin >>a[i];
			for (int k=1;k<=n;k++)
				for (int l=1;l<=n;l++)
				{
					if(a[k]==a[l]) d[a[k]][a[l]]=0;
					else  d[a[k]][a[l]]=1;
				}
		}
		floyd();
		int ans=INF;
		for (int i=1;i<=N;i++)
		{
			int temp=0;
			for (int j=1;j<=N;j++)
				temp+=d[i][j];
			ans=min(ans,temp);
		}
		cout << ans << endl;
		double tp=ans*1.0/(N-1);
		ans=tp*100;
		cout << ans << endl;
	}
	return 0;
}
 
