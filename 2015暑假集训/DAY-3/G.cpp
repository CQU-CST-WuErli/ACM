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

void print(string s,int len){
	int ls=s.size();
	cout << s;
	for (int i=0;i<len-ls;i++) cout << " ";
}

int n;
string fn[110];


int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	  freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		cin.get();
		cout << "------------------------------------------------------------\n";
	//	BUG(52);
		int maxl=0;
		for (int i=0;i<n;i++){
			cin >> fn[i];
			int l=fn[i].size();
			maxl=max(maxl,l);
		}
		sort(fn,fn+n);
		int row,col;
		col=(60-maxl)/(maxl+2)+1;
		row=(n-1)/col+1;
		for (int r=0;r<row;r++){
			for (int c=0;c<col;c++){
				if (c*row+r<n) print(fn[c*row+r],(c==col-1?maxl:maxl+2));
			}
			cout << "\n";
		}
	}
	return 0;
}


