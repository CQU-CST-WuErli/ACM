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
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;
const int maxn = 1e5+5;
int a[maxn];

typedef map<int,int> mp;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    
    int n,t;
    while (cin >> n){
    	mp m;
    	for(int i = 0; i < n; i++){
   	    	cin >> a[i];
   	    	m[a[i]]++;
  		}
   		ll ans=0;
   		for(int i=0; i<n; i++){
       		if(a[i] == 0)  ans+=m[0]-1;
   	    	else if(m.count(-a[i])) ans+=m[-a[i]];
   		}
    	 cout << ans/2 << endl;
    }
    
    return 0;
}
