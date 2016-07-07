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

int n,M;
int m[11][11][11][11];

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int kase=1;
	while (cin >> n >> M){
		int zero=0;
		if (kase!=1) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",kase++);
		CLR(m);
		for (int i=1;i<=M;i++){
			char c;int a,b;
			cin >> c >> a >> b; 
			if (c=='H') m[a][b][a][b+1]=m[a][b+1][a][b]=1;
			else if(c=='V') m[b][a][b+1][a]=m[b+1][a][b][a]=1;
	//		cout << c << a << b << endl; 
		}
		int len;
		for (len=1;len<=n-1;len++){
			int sum=0;int suc;int flag;
			for (int i=1;i<=n-len;i++){	
				for (int j=1;j<=n-len;j++){
					int ti=i+len,tj=j+len;
					flag=0;suc=1;
					for (int k=i;k<ti;k++){
						if (!m[k][j][k+1][j]){
							flag=1;break;
						}
					}
					for (int k=j;k<tj;k++){
						if (!m[i][k][i][k+1]){
							flag=1;break;
						}
					}
					for (int k=j;k<tj;k++){
						if (!m[ti][k][ti][k+1]) {
							flag=1;break;
						}
					}
					for (int k=i;k<ti;k++){
						if (!m[k][tj][k+1][tj]){
							flag=1;break;
						}
					}
					if (flag){
						suc=0;
					}
					if (suc) sum++;
				}
				
			}
			if (sum) {
				printf("%d square (s) of size %d\n",sum,len);
				zero=1;
			}
		}
		if (!zero) printf("No completed squares can be found.\n");
	}
	return 0;
}


