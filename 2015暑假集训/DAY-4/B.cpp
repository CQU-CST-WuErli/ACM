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
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int T;

int num[1100];

int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	cin >> T;
	for (int t=0;t<T;t++){
		int n;
		cin >> n;
		for (int i=1;i<=n;i++) scanf("%d",&num[i]);
		int flag=0;
		for (int i=1;i<=1200;i++){
			int sum=0;
			int tmp=num[1];
			for (int j=1;j<=n-1;j++)	{
				num[j]=abs(num[j]-num[j+1]);
				sum+=num[j];
			}
			num[n]=abs(num[n]-tmp);
			sum+=num[n];
		//	for (int j=1;j<=n;j++) cout << num[j] << " ";
		//	cout << endl;
			if (sum==0) {
				flag=1;
				break;
			}
		}
		if (flag) cout << "ZERO\n";
		else cout << "LOOP\n";
	}
	return 0;
}


