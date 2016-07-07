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
#define look(x) cout << #x << " = " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
ll a,b;
int q;
ll l,r;
ll gcd[1000000];
int cnt;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> a >> b){
		cnt=0;
		ll max_gcd=__gcd(a,b);
//		look(max_gcd);
		for (int i=1;i*i<=max_gcd;i++){
			if (max_gcd%i==0) {
				gcd[cnt++]=i;
				gcd[cnt++]=max_gcd/i;
			}
		}
		sort(gcd,gcd+cnt);
//		for (int i=0;i<cnt;i++) cout << gcd[i]  << " ";
//		cout << endl;
		cin >> q;
		for (int i=0;i<q;i++){
			cin >> l >> r;
			int tcnt=cnt-1;
			while (gcd[tcnt]>r) tcnt--;
			if (gcd[tcnt]>=l) cout << gcd[tcnt] << endl;
			else cout << "-1\n";
		}
	}
	return 0;
}


