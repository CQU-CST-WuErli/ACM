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

int p,l,w,n;
struct pp{
	int cnt;
	double cost;
}sta[550];

bool cmp(const pp &a,const pp &b)
{
	return a.cnt < b.cnt ;
}


int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%d%d%d%d",&p,&l,&w,&n)!=EOF)
	{
		for (int i=1;i<=n;i++)
			cin >> sta[i].cost >> sta[i].cnt;
		sort(sta+1,sta+1+n,cmp);
		for (int i=1;i<=n;i++)
			cout << sta[i].cnt << endl;
		bool ans=true;
		double sum=0,ret=0,mtemp=0,cost=0;
		int pos=1;
		while (ans)
		{
			if (sum>=l) break;
			bool tt=false;
			double ss=0.00;
			int flag;
			mtemp=(p-ret)*w+sum;
			for (int i=pos;i<=n;i++){
				if (mtemp<sta[i].cnt){
					flag=i-1;
					break;
				}
			}
			if (flag==pos){
				ans=false;
				break;
			}
			for (int i=pos+1;i<=flag;i++){
				if (sta[pos].cost>sta[i].cost){
					tt=true;
					s
				}
			}
		}
		if (ans) cout << "YES" << endl << cost << endl;
		else cout << "NO" << endl << sum << endl;
	}
	return 0;
} 
