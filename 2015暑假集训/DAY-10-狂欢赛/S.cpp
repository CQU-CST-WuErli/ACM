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
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
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
#define MOD 1e9+7

struct P{
	string str;
	int pos;
	bool operator < (const P &rhs ) const {
		return str > rhs.str;
	}
	
};

priority_queue<P> pq;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	int k;
	cin >> s;
	cin >> k;
	int i;
	for (i=0;s[i];i++) {
		string tt="";
		tt+=s[i];
		pq.push(P{tt,i});
	}
	int ls=s.size();
	int cnt=0;
	while (!pq.empty()){
		P x=pq.top();pq.pop();
		cnt++;
		if (cnt==k) {
			cout << x.str << endl;
			return 0;
		}
		if (x.pos<i-1){
			P tmp;
			tmp.str=x.str+s[x.pos+1];
			tmp.pos=x.pos+1;
			pq.push(tmp);
		}
	}
	cout << "No such line.\n";
	return 0;
}


