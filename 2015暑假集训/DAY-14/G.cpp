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

const int N=1e5+10;
int item[N];
int n;
int t;
int maxv;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;int kase=1;
	while (t--){
		if (kase!=1) cout << endl;kase++;
		int ans=0;
		cin >> n >> maxv;
		for (int i=0;i<n;i++) scanf("%d",item+i);
		sort(item,item+n);
//		for (int i=0;i<n;i++) cout << item[i] << " ";
//		cout << endl;
		int i=0;
		int cnt=0;
		for (int i=n-1;i>=cnt;i--){
			if (item[i]+item[cnt]<=maxv) cnt++;
			ans++;
		}
		cout << ans << endl ;
//		cout << endl;
	}
	return 0;
}


