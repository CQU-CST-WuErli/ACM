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
#include <functional>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
//#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int lch[300],rch[300];

string s1,s2;

int build(int L1, int R1, int L2,int R2){
	if (L1>R1 || L2>R2) {
		return 0;
	}
	int root = s1[L1];
	int cnt=L2;
	while (s2[cnt]!=root) cnt++;
	int p=cnt-L2; 
	lch[root]=build(L1+1,L1+p,L2,cnt-1);
	rch[root]=build(L1+1+p,R1,cnt+1,R2);
	return root;
} 

void dfs(int root){
	if (lch[root]>0) dfs(lch[root]);
	if (rch[root]>0) dfs(rch[root]);
	printf("%c",root);
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	string s;
	while (getline(cin,s)){
		int cnt;
		for (int i=0;s[i];i++){
			if (s[i]==' '){
				cnt=i;
				break;
			}
			else s1+=s[i];
		} 
		for (int i=cnt+1;s[i];i++) s2+=s[i];
//		cout << s1 << endl << s2 << endl;
		CLR(lch);CLR(rch);
		int ls=s1.size();
		build(0,ls-1,0,ls-1);
		dfs(s1[0]);
		cout << endl;
		s1.clear();s2.clear();
	}
	return 0;
}


