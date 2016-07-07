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

int n;
string st[70];
int vis[70];


int main(){
	while (cin >> n){
		getchar();
		memset(vis,0,sizeof vis);
		for (int i=1;i<=n;i++) {
			cin >> st[i];
	//		cout << st[i] << endl;
		}
		for (int i=1;i<=n;i++) vis[i]=1;
		int w,s;
		char c;
		cin >> w >> c >> s; 
	//	cout << w << "\n" << s << endl;
		int cnt=w;
		int l=n;
		int flag=0;
		for(cnt=w;cnt<=n;cnt++){
			if (vis[cnt]){
				flag++;
			}
			if (flag==s){
				vis[cnt]=0;
				cout << st[cnt] << endl;
				l--;
				flag=0; 
			}
			if (cnt==n) cnt=0;
			if (l==0) break;
		}
	}
	return 0;
}

