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
#include <sstream>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
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

string tree;
int num[200];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	int kase=1;
	while (cin >> n && n){
		getchar(); 
		string s;
		getline(cin,s);
		stringstream ss(s);
		for (int i=0;i<n;i++) {
			string tmp;
			ss >> tmp;
			num[i]=tmp[1]-'0';
//			cout << tmp;
		}
//		for (int i=0;i<n;i++) cout << num[i] << " ";
		cin >> tree;
//		cout << tree << endl;
		int q;
		cin >> q;
		getchar();
		string ans;
		while (q--){
//			string s;
			cin >> s;
//			cout << s << endl;
			int index=1;
			for (int i=0;i<n;i++){
			int x=s[num[i]-1]-'0';
			if (x) index=index*2+1;
			else index=index*2;
			}
			index-=(1<<n);
			ans+=tree[index];
		}
		printf("S-Tree #%d:\n",kase++);
		cout << ans << endl << endl;
	}
	return 0;
}


