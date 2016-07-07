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
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << "x=" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int t;
ll maxv;
ll v1,w1,v2,w2;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;int kase=1; 
	while (t--){
		cin >> maxv;
		cin >> v1 >> w1 >> v2 >> w2;
		if (max(v1,v2)*max(v1,v2)>=maxv){
			ll ans=0;
			if (v1<v2) {
				swap(v1,v2);
				swap(w1,w2);
			}
			for (ll i=0;i<=maxv/v1;i++){
				ans=max(ans,i*w1+(maxv-i*v1)/v2*w2);
			}
			cout << "Case #" << kase++ << ": " << ans << endl; 
		}	
		else {
			ll ans=0;
			ll a=w1*v2,b=w2*v1;
			if (a<b){
				swap(v1,v2);
				swap(w1,w2);
			}
			for (ll i=0;i<=v1;i++){
				if (i*v2>maxv) break;
				ans=max(ans,i*w2+(maxv-i*v2)/v1*w1);
			}
			cout << "Case #" << kase++ << ": " << ans << endl;
		}
	}
	return 0;
}


