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

int t;
int n;
int cnt;
typedef set<int> S;

map<S,int> ms;
S sn[3000];
int get_n(S a){
	if (ms.count(a)) return ms[a];
	else {
		sn[cnt]=a;
		ms[a]=cnt++;
		return ms[a];
	}
}


int main(){

#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	cin >> t;
	for (int kase=1;kase<=t;kase++){
		stack<int> st;
		string s;
		cnt=1;
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> s;
			if (s == "PUSH"){
				S a;
				st.push(get_n(a));
			}
			else if (s == "DUP"){
				st.push(st.top());
			}
			else if (s == "UNION"){
				int a=st.top();st.pop();
				int b=st.top();st.pop();
				S c=sn[a],d=sn[b];
				S tmp;
				set_union(c.begin(),c.end(),d.begin(),d.end(),inserter(tmp,tmp.begin()));
				st.push(get_n(tmp));
			}
			else if (s == "INTERSECT"){
				int a=st.top();st.pop();
				int b=st.top();st.pop();
				S c=sn[a],d=sn[b];
				S tmp;
				set_intersection(c.begin(),c.end(),d.begin(),d.end(),inserter(tmp,tmp.begin()));
				st.push((get_n(tmp)));
			}
			else if (s == "ADD"){
				int a=st.top();st.pop();
				int b=st.top();st.pop();
				S c=sn[a],d=sn[b];
				S tmp=d;
				tmp.insert(a);
				st.push(get_n(tmp));
			}
			int tmp=st.top();
			cout << sn[tmp].size() << endl;
		}
		ms.clear();
		printf("***\n");
	}
	return 0;
}


