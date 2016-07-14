//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;

ll value[1100];


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (cin >> n){
		int flag=0;
		for (int i=0;i<n;i++) {
			scanf("%I64d",value+i);
			if (value[i]==1) flag=1; 
		}
		if (flag) printf("-1\n");
		else {
			ll mmin;
			sort(value,value+n);
			if (value[0]>1) mmin=1;
			else {
				for (int i=1;i<n;i++){
				if (value[i]-value[i-1]>1){
					mmin=value[i-1]+1;
					break;
					} 
				}
			}
			printf("%I64d\n",mmin);
		}
		
	} 
	return 0;
}


