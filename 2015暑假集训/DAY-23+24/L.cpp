//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=30;
int n,m;
double sum;
double a[N][N];
double row[N],col[N];
double sum_row[N],sum_col[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n >> m && (n||m)){
		CLR(row);CLR(col);
		CLR(sum_col);CLR(sum_row);
		sum=0.0; 
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				scanf("%lf",&a[i][j]);
				row[i]+=a[i][j];
				col[j]+=a[i][j]; 
				sum+=a[i][j];
			}
		for (int i=1;i<=n;i++) sum_row[i]=sum_row[i-1]+row[i];
		for (int i=1;i<=m;i++) sum_col[i]=sum_col[i-1]+col[i];
		double Min_ab=30,Min_lr=30,Min=30;
		int id_x,id_y;
		for (int i=2;i<n;i++)
			for (int j=2;j<m;j++){
				double diff_ab,diff_lr,diff;
				diff_ab=max(sum_row[i-1],(sum_row[n]-sum_row[i]))-min(sum_row[i-1],(sum_row[n]-sum_row[i]));
				diff_lr=max(sum_col[j-1],(sum_col[m]-sum_col[j]))-min(sum_col[j-1],(sum_col[m]-sum_col[j]));
				diff=diff_ab+diff_lr;
				if (diff<Min){
					Min=diff;
					id_x=i;id_y=j;
				}
			}
		printf("Case %d: center at (%d, %d)\n",kase++,id_x,id_y);
	}
	return 0;
}
