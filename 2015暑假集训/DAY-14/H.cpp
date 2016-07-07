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

int n;

string s[1100];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n && n){
		getchar();
		for (int i=1;i<=n;i++) cin >> s[i];
		sort(s+1,s+1+n);
//		for (int i=1;i<=n;i++) cout << s[i] << " ";
//		cout << endl;
		int mid=(n%2==0?n/2:n/2+1);
		string ans="";
		int l1=s[mid].size(),l2=s[mid+1].size();
		int i=0;
		for (i=0;i<min(l1,l2);i++){
			if (s[mid][i]==s[mid+1][i]) ans+=s[mid][i];
			else break;
		}
		int flag=0;
		if (i==l1 && i<l2) flag=1;
		while(i<max(l1,l2) && !flag){
			flag=0;
			string tmp=ans;
			tmp+=' ';
			for (char j=(i<l1?s[mid][i]:'A');j<=(i<l2?s[mid+1][i]:'Z');j++){
				tmp[i]=j;
				if (tmp>=s[mid] && tmp<s[mid+1]){
					ans=tmp;flag=1;break;
				}	
			}
			if (flag) break;
			else {
				ans+=(i<l1?s[mid][i]:'A');i++;
			}
		}
		if (!flag) ans+='A';
		cout <<  ans << endl; 
	}
	return 0;
}


