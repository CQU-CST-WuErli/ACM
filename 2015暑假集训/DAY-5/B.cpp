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

int n;
int po[1100]; 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	int kase=1;
	while (cin >> n && n){
		while (cin >> po[1] && po[1]){
			for (int i=2;i<=n;i++) cin >> po[i];
			stack<int> s;
			int cnt1,cnt2;
			cnt1=cnt2=1;
			int flag=1;
			while (cnt2<=n){
				if (cnt1==po[cnt2]) {
					cnt1++;
					cnt2++;
				}
				else if (!s.empty() && s.top()==po[cnt2]) {
					s.pop();
					cnt2++;
				}
				else if (cnt1<=n){
					s.push(cnt1);
					cnt1++;
				}
				else {
					flag=0;
					break;
				}
			}
			if (flag) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		printf("\n");
	}
	return 0;
}


