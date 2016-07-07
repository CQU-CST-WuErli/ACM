//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=1e5+10;

int n;
int vis[N];
int a[N]; 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		if (n==1) {
			cin >> a[0];
			cout << 1 << endl;continue;
		}
		else {
			CLR(vis);
			int flag=0;
			vector<int> v;
			for (int i=1;i<=n;i++){
				cin >> a[i];
				if (!vis[a[i]] && a[i]<=n) vis[a[i]]++;
				else {
					v.push_back(i);
					flag=1;
				}
			}
			if (flag){
				queue<int> q;
				for (int i=1;i<=n;i++) if (!vis[i]) q.push(i);
				for (int i=0;i<v.size();i++){
					int id=v[i];
					a[id]=q.front();q.pop();
				}		
			}
			for (int i=1;i<=n;i++) {
				cout << a[i];
				if (i<n) cout <<' ';
				else cout << endl;
			}
		}
	}
	return 0;
}


