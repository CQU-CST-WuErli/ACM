//  Created by Chenhongwei on 2016-05-03 Tuesday 23:15
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
const int maxn=5e6+100;
typedef long long ll;
typedef unsigned long long ull;
char s[maxn],t[maxn],b[maxn];
int nxt[maxn];
void pre_kmp()
{
	memset(nxt,0,sizeof nxt);
	int j=0,m=strlen(t+1);
	for(int i=2;i<=m;i++)
	{
		while(j>0&&t[j+1]!=t[i])
			j=nxt[j];
		if(t[j+1]==t[i]) j++;
		nxt[i]=j;
	}
}
void kmp()
{
	int j=0,n=strlen(s+1),m=strlen(t+1);
	int last=1;
	for(int i=1;i<=n;i++)
	{
		while(j>0&&t[j+1]!=s[i])
			j=nxt[j];
		if(t[j+1]==s[i]) j++;
		if(j==m)
		{
			// cout<<"ok"<<endl;
			j=0;
			for(int k=last;k<=i-m;k++)
				printf("%c",s[k]);
			printf("%s",b+1);
			last=i+1;
		}
	}
	for(int i=last;i<=n;i++)
		printf("%c",s[i]);
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
		scanf("%s%s%s",s+1,t+1,b+1);
		pre_kmp();
		kmp();
		printf("\n");
	}
	return 0;
}