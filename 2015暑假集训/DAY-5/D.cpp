//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=100010;
int lft[N],rgt[N];
int nxt[N];
char s[N];
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (gets(s+1)){
		int cnt=0;       //当前字符 
		int end=0;       //最后一个字符 
		nxt[0]=0;
		for (int i=1;s[i];i++){
			char c=s[i];
			if (c=='[') cnt=0;      
			else if (c==']') cnt=end;
			else {
				nxt[i]=nxt[cnt];
				nxt[cnt]=i;
				if (cnt==end){
					end=i;
				}
				cnt=i;
			}
		}
//		cout << nxt[0] << " ";
//		for (int i=1;s[i];i++) cout << nxt[i] << " " ;
		for (int i=nxt[0];s[i];i=nxt[i]) cout << s[i] ;
		cout << endl;
	}
	return 0;
}


