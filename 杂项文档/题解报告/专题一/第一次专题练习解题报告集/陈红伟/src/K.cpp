//  Created by Chenhongwei on 2016-05-06 Friday 17:12
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
int a[maxn],n;
// int minrepresent()
// {
// 	int i=0,j=1,k=0;
// 	while(i<n&&j<n)
// 	{
// 		k=0;
// 		while(a[i+k]==a[j+k]&&k<n)
// 			k++;
// 		if(k==n)
// 			return i;
// 		if(a[i+k]>a[j+k])
// 			i=max(j+1,i+k+1);
// 		else 
// 			j=max(i+1,j+k+1);
// 	}
// 	if(i<n)
// 		return i;
// 	else
// 		return j;
// }
int minrepresent(){  
    int i=0,j=1,k=0,t;  
    while(i<n && j<n && k<n){  
        t = a[(i+k) >= n ? i+k-n : i+k] - a[(j+k) >= n ? j+k-n : j+k];  
        if(!t)k++;  
        else {  
            if(t>0)i = i+k+1;  
            else j = j+k+1;  
            if(i==j)j++;  
            k = 0;  
        }  
    }  
    return i;  
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
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int p=minrepresent();
		printf("%d",a[p]);
		for(int i=p+1;i<n;i++)
			printf(" %d",a[i]);
		for(int i=0;i<p;i++)
			printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
