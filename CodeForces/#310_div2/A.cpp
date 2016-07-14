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
#define BUG(x) puts("In line x\n")
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;

const int maxn=2e5+10;
char c;
int l; 
char a[maxn];

int main(){
	scanf("%d",&l);
	getchar();
	int ll=l;
	int flag=0;
	for (int i=1;i<=l;i++){
		scanf("%c",&c);
		if (flag==0){
			a[flag]=c;
			flag++;
			continue;
		}
		else {
			if (c==a[flag-1]){
				a[flag]=c;
				flag++;
			}
			else{
	//			BUG(57);
				ll-=2;
				flag--;
			}
		}
	} 
	printf("%d\n",ll);
	return 0;
}

