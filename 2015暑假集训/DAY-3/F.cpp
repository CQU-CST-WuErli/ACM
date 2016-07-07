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
//	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	set<long long> st;
	st.insert(1);
	int sum=1;
	long long cnt;
	long long mmin;
	for (int i=2;i<=1500;i++){
		mmin=*st.begin();
		st.erase(st.begin());
		st.insert(mmin*2);
		st.insert(mmin*3);
		st.insert(mmin*5);
		cnt=*st.begin();
	//	cout << cnt << endl;
	}
	printf("The 1500'th ugly number is %lld.\n",cnt);
	return 0;
}


