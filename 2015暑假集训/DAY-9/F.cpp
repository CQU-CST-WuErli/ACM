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

int g[30][30];

vector<int> per;
vector<int> pp;
int in[26];

bool cmp(vector<int> a,vector<int> b){
	for (int i=0;i<a.size();i++){
		if (b[i]<a[i]) return true;
 	}
 	return false;
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	while (cin >> s){
		int n=0;
		if (s[0]=='#') break;
		int sum=0;
		CLR(g);
		CLR(in);
		int ls=s.size();
		int flag=1;
		char u;
		for (int i=0;i<ls;i++){
			if (s[i]==':') flag=0;
			if (s[i]==';') flag=1;
			if (isalpha(s[i])){
				if (flag) {
					u=s[i];
					if (!in[s[i]-'A']){
						in[s[i]-'A']=1;n++;
						per.push_back(s[i]-'A');
					}
				}
				else {
					g[u-'A'][s[i]-'A']=g[s[i]-'A'][u-'A']=1;
					int v=s[i]-'A';
					if (!in[v]){
						per.push_back(v);
						in[v]=1;n++;
					}
				}
			}
		}
//		for (int i=0;i<per.size();i++) printf("%c ",per[i]+'A');
//		cout << endl;
		sort(per.begin(),per.end());
//		for (int i=0;i<per.size();i++) printf("%c ",per[i]+'A');
		int ans=INF;
		do {
			int temp=0;int ok=0;
			for (int i=0;i<per.size();i++){
				for (int j=0;j<per.size();j++){
					if (g[per[i]][per[j]]){
						temp=max(temp,abs(i-j));
					}
				}
				if (temp>ans){
					ok=1;
				}
			}
			if (ok) continue;
			if (temp<ans) {
				pp=per;
				ans=temp;
			}
		}while (next_permutation(per.begin(),per.end()));
//		cout << ans << endl;
		for (int i=0;i<pp.size();i++) printf("%c ",pp[i]+'A');
		cout << "-> " << ans << endl;
		per.clear();pp.clear();
	}
	return 0;
}


