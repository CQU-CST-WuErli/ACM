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

int n;
ll k;
string s;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
		cin >> n >> k;
		getchar();
		cin >> s;
//		cout << s << endl;
		int ls=s.size();
		if (k==0) {
			cout << s << endl;
		}
		else {
			for (int i=0;i<ls-1;i++){
			if (s[i]=='4' && s[i+1]=='7') {
				k--;
					if ((i+1)%2) {
					s[i]=s[i+1]='4';
						if (i+2<ls && s[i+2]=='7'){
						if (k%2==1) s[i+1]='7';
							else s[i+1]='4';
							break;
						}
					}
					else {
						s[i]=s[i+1]='7';
						if (i-1>=0 && s[i-1]=='4' ){
						if (k%2==1) s[i]='4';
							else s[i]='7';
							break;
						}
					}
					if (k==0) break;
				}	
			}
			cout << s << endl;
		}
	return 0;
}


