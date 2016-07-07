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

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int n,m,k;
	int tr[25];
	while (cin >> n >> k >> m && (n || k || m)){
		CLR(tr);
		int sp=n;
		int cn1=1;int cn2=n;
		queue<int> q;
		while (sp){
			int tt1=0,tt2=0;
			while (tt1<k){
				if (!tr[cn1++]){
					tt1++;
				}
				if (cn1>n) cn1=1;
			}
			int tmp1;
			if (cn1==1) tmp1=n;
			else tmp1=cn1-1;
			q.push(tmp1);
			sp--;
			while (tt2<m){
				if (!tr[cn2--]){
					tt2++;
				}
				if (cn2==0) cn2=n;
			}
			int tmp2;
			if (cn2==n) tmp2=1;
			else  tmp2=cn2+1;
			tr[tmp1]=1;tr[tmp2]=1;
			if (tmp1!=tmp2) {
				sp--;
				q.push(tmp2);
			}
			if (tmp1!=tmp2) {
				if (sp) printf("%3d%3d,",tmp1,tmp2);
				else printf("%3d%3d",tmp1,tmp2);
			}
			else if (tmp1==tmp2) {
				if (sp)printf("%3d,",tmp1);
				else printf("%3d",tmp1);
			}
		}
		cout << endl; 
	}
	return 0;
}


