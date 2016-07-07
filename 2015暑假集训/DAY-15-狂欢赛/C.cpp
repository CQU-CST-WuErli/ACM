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

string s;
int k;
struct P{
	char c;
	int sum;
	P(){sum=0;}
}a[26];
int vis[26];

bool cmp(const P& a,const P& b){
	return a.sum<b.sum;
}
int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int i=0;i<26;i++) a[i].c='a'+i; 
	cin >> s; 
	cin >> k;
	CLR(vis);
	int ls=s.size();
	if (k>=ls){
		cout << "0\n\n";
	}
	else {
		for (int i=0;s[i];i++) {
			a[s[i]-'a'].c=s[i];
			a[s[i]-'a'].sum++;
		}
//		for (int i=0;i<26;i++) cout << a[i].c << "  " << a[i].sum << endl;
		sort(a,a+26,cmp);
		int kind=0;
		for (int i=0;i<26;i++) if (a[i].sum!=0) kind++;
		for (int i=0;i<26;i++){
			if (a[i].sum==0) {
				vis[a[i].c-'a']=1;
			}
			else {
				if (k<a[i].sum) break;
				else {
					k-=a[i].sum;
					a[i].sum=0;
					vis[a[i].c-'a']=1;
					kind--;
				}
			}
		}
		cout << kind << endl;
		for (int i=0;s[i];i++) if (!vis[s[i]-'a']) cout << s[i];
		cout << endl;	
	}
	return 0;
}


