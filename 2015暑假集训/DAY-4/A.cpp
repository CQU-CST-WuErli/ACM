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

string s[1100][200]; 
int maxl[200]={0};
int counter[1100];

void print(string str,int len){
	int ls=str.size();
	cout << str;
	for (int i=0;i<len-ls-1;i++) cout << " ";
}

int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	string t;
	int kase=0;
	while (getline(cin,t)){
		string tmp;
		int cnt=0;
		int lt=t.size();
		for (int i=0;i<lt;i++){
			if (t[i]!=' '){
				tmp+=t[i];
			}
			else {
				if (tmp.size()){
					 s[kase][cnt++]=tmp;
					 tmp.clear();
				}
				
			}
			if (i==lt-1){
				if (tmp.size()){
					s[kase][cnt++]=tmp;
					tmp.clear();
				}
			}
		}
		for (int i=0;i<cnt;i++) {
			int l=s[kase][i].size();
			maxl[i]=max(maxl[i],l);
		}
		counter[kase]=cnt;
		kase++;
	}
	for (int i=0;i<kase;i++){
		for (int j=0;j<counter[i];j++){
			if (j<counter[i]-1)print(s[i][j],maxl[j]+2);
			else cout << s[i][j];
		}
		cout << endl;
	}
	
	return 0;
}


