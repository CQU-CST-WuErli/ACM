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


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n && n){
		deque<int> dq;
		for (int i=0;i<n;i++){
			int x;
			cin >> x;
			dq.push_back(x);
		}
		vector<int> ans;
		int step=2*n*n;
		for (int i=0;i<=step;i++){
			int a=dq[0];
			int b=dq[1];
			if (a==1){
				int flag=1;
				for (int j=1;j<=n;j++){
					if (dq[j-1]!=j){
						flag=0;break;
					}
				}
				if (flag) break;
			}	
			if (a>b && a!=n){
				ans.push_back(1);
				swap(dq[1],dq[0]);
			}
			else {
				ans.push_back(2);
				int tail=dq.back();
				dq.pop_back();
				dq.push_front(tail);
			}
		}
		for (int i=ans.size()-1;i>=0;i--) {
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}


