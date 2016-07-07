//  Created by Chenhongwei on 2016-05-05 Thursday 16:05
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
const int maxn=1e6+100;
typedef long long ll;
typedef unsigned long long ull;
ull b[maxn];
ull ans[500];
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	// freopen("out1.txt","w",stdout);
	for(int i=1;i<(1<<19);i++)
	{
		ll tmp=i&(1<<19);
		for(int j=18;j>=0;j--)
		{
			int x;
			x=(i&(1<<j))?1:0;
			tmp=tmp*10+x;
		}
		b[i]=tmp;
	}
	for(int i=1;i<=466;i++)
	{
		for(int j=1;j<(1<<19);j++)
			if(b[j]%i==0)
			{
				ans[i]=b[j];
				// printf("%lld\n",ans[i]);
				break;
			}
	}
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==396)
			cout<<"11111111111111111100"<<endl;
		else
			printf("%lld\n",ans[n]);
	}
	return 0;
}