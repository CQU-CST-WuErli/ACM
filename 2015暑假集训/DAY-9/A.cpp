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
#include <sstream>
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

int vis[10];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
  freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && n){
		if (kase!=1) cout << endl; kase++;
		int ok=0;
		for (int i=1;i<=9;i++)
			for (int j=0;j<=9;j++)
				for (int k=0;k<=9;k++)
					for (int s=0;s<=9;s++)
						for (int t=0;t<=9;t++){
							int ans=i*10000+j*1000+k*100+s*10+t;
							CLR(vis);
							if (ans%n!=0) continue;
							int tmp=ans,cnt=0;
							while (tmp){
								int x=tmp%10;
								tmp/=10;
								if (!vis[x]) {
									vis[x]=1;cnt++;
								}
							} 
							if (cnt<5) continue;
							int sol=ans/n;
							if (sol<1000) continue;
							int flag=1;
							int temp=sol;
							if (temp<10000) temp*=10;
							while (temp){
								int x=temp%10;
								temp/=10;
								if (vis[x]){
									flag=0;break;
								}
								vis[x]=1;
							}
							if (flag){
								ok=1;
								printf("%05d / %05d = %d\n",ans,sol,n);
							}
						}
		if (!ok) printf("There are no solutions for %d.\n",n);
//		cout << endl;
	}
	return 0;
}


