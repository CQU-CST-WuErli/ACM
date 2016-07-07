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

int n,k;
string s[8]; 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> k){
		getchar();
		for (int i=0;i<n;i++) cin >> s[i];
		int id[8]={0,1,2,3,4,5,6,7};
		int ans=INF;
		do {
			ll mmin=INF;
			ll mmax=0;
			for(int i=0;i<n;i++){
				ll tmp=0;
				for (int j=0;j<k;j++) {
					char c = s[i][id[j]];
					tmp=tmp*10+(ll)(c-'0');
				}
				if (tmp<mmin) mmin=tmp;
				if (tmp>mmax) mmax=tmp;
			} 
			if (mmax-mmin<ans) ans=mmax-mmin;
		}while(next_permutation(id,id+k));
		cout << ans << endl;
	}
	return 0;
}


