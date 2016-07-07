//  Created by Chenhongwei on 2016-05-06 Friday 15:30
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
const int maxn=1e5+100;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	//ios::sync_with_stdio(false);
    // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		int tmp;
		char s[20];
		scanf("%d",&tmp);
		scanf("%s",s);
		if(s[1]=='B')
			tmp=0;
		else if(s[1]=='K')
			tmp=1;
		else if(s[1]=='M')
			tmp=2;
		else if(s[1]=='G')
			tmp=3;
		else if(s[1]=='T')
			tmp=4;
		else if(s[1]=='P')
			tmp=5;
		else if(s[1]=='E')
			tmp=6;
		else if(s[1]=='Z')
			tmp=7;
		else if(s[1]=='Y')
			tmp=8;
		double C=(double)1000/(double)1024;
		double ans=1.0;
		for(int i=1;i<=tmp;i++)
			ans=ans*C;
		ans=1-ans;
		ans*=100;
		printf("Case #%d: %.2lf%%\n",kase,ans);

	}
	return 0;
}
