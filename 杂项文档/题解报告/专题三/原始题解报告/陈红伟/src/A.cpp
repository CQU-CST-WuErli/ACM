//  Created by Chenhongwei on 2016-06-03 Friday 16:56
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
const int maxn=3e5+100;
typedef long long ll;
typedef unsigned long long ull;
int in[550],out[550];
int f[550];
int n,m;
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
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
		bool ok1=false,ok2=false;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			f[i]=i,in[i]=out[i]=0;
		int x,y;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			out[x]++;
			in[y]++;
			x=find(x),y=find(y);
			if(x!=y)
				f[x]=y;
		}
		int cnt=0;
		vector<int> v;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i)
				cnt++;
			if(in[i]!=out[i])
				v.push_back(i);
		}
		if(cnt!=1)
		{
			puts("No No");
			continue;
		}
		if(v.size()>2)
			ok2=false;
		else if(v.size()==2)
		{
			if((in[v[0]]-out[v[0]])*(in[v[1]]-out[v[1]])==-1)
				ok2=true;
			else
				ok2=false;
		}
		else if(v.size()==1)
			ok2=false;
		else if(v.size()==0)
			ok2=true;
		cnt=0;
		for(int i=1;i<=n;i++)
			if((in[i]+out[i])%2==1)
				cnt++;
		if(cnt==0||cnt==2)
			ok1=true;
		else
			ok1=false;
		printf("%s %s\n",ok1==true?"Yes":"No",ok2==true?"Yes":"No");
	}
	return 0;
}
