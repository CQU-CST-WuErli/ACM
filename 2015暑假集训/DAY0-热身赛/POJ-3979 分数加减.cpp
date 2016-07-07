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

int main(){
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	int a,b,c,d;
	char op;
	while (scanf("%d/%d%c%d/%d",&a,&b,&op,&c,&d)!=EOF){
		int gcd=b*d;
		int son;
		if (op=='+') son=a*d+b*c;
		else if (op=='-') son=a*d-b*c;
		int flag=0;
		if (son<0) flag=1;
		else if (son==0) {
			printf("0\n");
			continue;
		}
		son=abs(son);
		int m=min(gcd,son);
		for (int i=2;i<=m;i++){
			while (gcd%i==0 && son%i==0) {
				gcd/=i;son/=i;
			}
		}
		if (flag) printf("-");
		if (son==gcd || gcd==1) printf("%d\n",son);
		else
			printf("%d/%d\n",son,gcd); 
	} 
	return 0;
}

