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
#define BUG() printf("In here\n")
#define seevalue(x) printf("x=%d\n",x)
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;

int t;
int m,n;
int cnt[1010][4];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	cin >> t;
	while (t--){
		cin >> m >> n;
		getchar();
		string tmp;
		memset(cnt,0,sizeof(cnt));
		string k;
		for (int i=1;i<=m;i++){
			cin >> k;
	//		cout << k << endl; 
			for (int j=0;k[j];j++){
				if (k[j]=='A') cnt[j][0]++;
				else if (k[j]=='C') cnt[j][1]++;
				else if (k[j]=='G') cnt[j][2]++;
				else if (k[j]=='T') cnt[j][3]++;
			}
		}
		int sum=0;
		for (int i=0;i<n;i++){
			int maxn=cnt[i][0];
			int index=0;
			for (int j=1;j<4;j++){
				if (maxn<cnt[i][j]){
					maxn=cnt[i][j];
					index=j;
				}
			}
	//		cout << "index=" << index << endl; 
			if (index==0) tmp+='A';
			else if (index==1) tmp+='C';
			else if (index==2) tmp+='G';
			else if (index==3) tmp+='T';
			for (int j=0;j<4;j++){
				if (j==index) continue;
				sum+=cnt[i][j];
			}
		}
		cout << tmp << endl;
		cout << sum << endl;
	}
	return 0;
}

