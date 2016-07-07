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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=4010;
int A[N],B[N],C[N],D[N];
int t;
int n; 
int tot[N*N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	int kase=1;
	while (t--){
		if (kase!=1) cout << endl;  kase++;
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d%d%d%d",A+i,B+i,C+i,D+i);
		}
		int cnt=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) 
				tot[cnt++]=A[i]+B[j];
		sort(tot,tot+cnt);
		int sum=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++){
				int tmp=-C[i]-D[j];
				int *s=lower_bound(tot,tot+cnt,tmp);
				if (*s==tmp) sum+=(upper_bound(tot,tot+cnt,tmp)-s);
				
			}
		cout << sum << endl;
	} 
	return 0;
}


