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
const int N=1000100;
int n,m,k;
int t;
int used[N];
int a[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	for (int kase=1;kase<=t;kase++){
		CLR(used);
		printf("Case %d: ",kase);
		cin >> n >> m >>k;
		int ok=0;
		deque<int> dq;
		a[1]=1;a[2]=2;a[3]=3;
		for (int i=4;i<=n;i++) a[i]=(a[i-1]+a[i-2]+a[i-3])%m+1;
//		for (int i=1;i<n;i++) cout << a[i] << " ";
//		cout << endl;
		int min_len=0x3f3f3f3f;
		int max_v=k;
		for (int i=1;i<=n;i++){
			if (a[i]<=max_v && a[i]>=1){
				if (used[a[i]]++ ==0) k--;
				dq.push_back(i);
//				look(i);
			} 
			while (!k){
//				cout << "s " << endl;
				min_len=min(min_len,dq.back()-dq.front()+1);
				int pos=dq.front();dq.pop_front();
				if (--used[a[pos]]==0) k++;
			}
		}
		if (min_len==0x3f3f3f3f) cout << "sequence nai\n";
		else cout << min_len << endl; 
	}
	return 0;
}


