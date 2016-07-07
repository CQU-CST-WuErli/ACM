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
const int N=2e5+10;

int t;
int n;
int a[N];
int pre[N],suf[N];

bool check(int l, int r){           //[l,r]
	if (l-r>=0) return true;
	for (int i=0;i<=(r-l)/2;i++){
		if (pre[l+i]<l && suf[l+i]>r) 
			return (check(l,l+i-1) && check(l+i+1,r));
		if (pre[r-i]<l && suf[r-i]>r) 
			return (check(l,r-i-1) && check(r-i+1,r));
	}
	return false;
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	while (t--){
		scanf("%d",&n);
		map<int,int> mp;
//		memset(suf,n+1,sizeof(suf));    //TLE
		for (int i=0;i<=n;i++) suf[i]=0x3f3f3f;     //473ms
		for (int i=0;i<n;i++){
			scanf("%d",a+i);
			if (!mp.count(a[i])) {
				pre[i]=-1;
			}
			else {
				pre[i]=mp[a[i]];
				suf[pre[i]]=i;                 //473ms
			}
			mp[a[i]]=i;
		}
//		mp.clear();                                  //673ms
//		for (int i=n-1;i>=0;i--){
//			if (!mp.count(a[i])) suf[i]=0x3f3f3f;
//			else suf[i]=mp[a[i]];
//			mp[a[i]]=i;
//		}			
//		for (int i=0;i<n;i++) cout << "pre[" << i << "]=" << pre[i] << " ";
//		cout  << endl;
//		for (int i=0;i<n;i++) cout << "suf[" << i << "]=" << suf[i] << " ";
//		cout << endl;
		if (check(0,n-1)) cout << "non-boring\n";
		else cout << "boring\n";
	}
	return 0;
}


