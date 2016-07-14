//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin)
#define BUG(x) printf("In line x\n")
#define seevalue(x) printf("x=%d\n",x)
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;

int n;
int a[1010];

int main(){
	scanf("%d",&n);
	bool ans=1;
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	int tt;
	if (a[0]>0) tt=n-a[0];
	else tt=0;
//	cout << tt<< endl;
	int temp;
	for (int i=1;i<n;i++){
		if ((i+1)%2==1){
			if (a[i]>i) temp=n-(a[i]-i);
			else if (a[i]<i) temp=i-a[i];
			else temp=0;
		}
		else if ((i+1)%2==0){
			if (a[i]>i) temp=a[i]-i;
			else if (a[i]<i) temp=n-(i-a[i]);
			else temp=0;
		}
	//	cout << temp << endl;
		if (temp!=tt){
			ans=0;
			break;
		}	
	}
	if (ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}

