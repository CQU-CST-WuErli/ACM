//  Created by  CQUWEL			                       
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.  

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

int T;
int m,n;
int a[110][110];
int d[110][110];
int pre[110][110]; 
int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	cin >> T;
	for (int test=1;test<=T;test++)
	{
		cin >> m >> n;
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
			cin >> a[i][j];
		for (int i=1;i<=n;i++)
			d[1][i]=a[1][i];
		for (int i=2;i<=m;i++)
			for (int j=1;j<=n;j++)
				d[i][j]=INF;
		memset(pre,-1,sizeof(pre));
		//------³õÊ¼»¯ --------------
		for (int i=2;i<=m;i++)
		 	for (int j=1;j<=n;j++)
		 	{
		 		if (j-1>=1 && j+1<=n)
		 		{
		 			for (int k=j-1;k<=j+1;k++)
		 			{
		 				if (a[i][j]+d[i-1][k]<=d[i][j])
		 				{
		 					d[i][j]=a[i][j]+d[i-1][k];
		 					pre[i][j]=k;
		 				}
		 			}
		 		}
		 		else if (j-1<1)
		 		{
		 			for (int k=j;k<=j+1;k++)
		 			{
		 				if (a[i][j]+d[i-1][k]<=d[i][j])
		 				{
		 					d[i][j]=a[i][j]+d[i-1][k];
		 					pre[i][j]=k;
		 				}
		 			}
		 		}
		 		else if (j+1>n)
		 		{
		 			for (int k=j-1;k<=j;k++)
		 			{
		 				if (a[i][j]+d[i-1][k]<=d[i][j])
		 				{
		 					d[i][j]=a[i][j]+d[i-1][k];
		 					pre[i][j]=k;
		 				}
		 			}
		 		}
		 	}
//		cout << pre[2][1] << endl;
/*		cout << "--------------------------\n";
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=n;j++)
				cout << pre[i][j] << " ";
			cout << endl;
		}
		cout << "--------------------------\n";*/
		 int ans=INF;
		 int flag;
		 for (int i=1;i<=n;i++)
			if (ans>=d[m][i])
			{
				ans=d[m][i];
				flag=i;
			}
		 deque<int> q;
		 q.push_front(flag);
		 int ss=m,tt=flag;
		 while(pre[ss][tt]!=-1)
		 {
		 	q.push_front(pre[ss][tt]);
			tt=pre[ss][tt];
			ss--;
		 } 
		 cout << "Case " << test << endl;
		 int l=q.size();
		 while (!q.empty())
		 {
		 	int x=q.front();
		 	printf("%d",x);
		 	if (l!=1)
		 	cout << " ";
		 	else cout << endl;
		 	q.pop_front();
		 	l--;
		 }
//		 cout << endl;
	}
	return 0;
}

