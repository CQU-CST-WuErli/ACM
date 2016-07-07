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
const int N=100111;
int t;
int n;
int sta[N];
int cons[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	for (int kase=1;kase<=t;kase++){
		cin >> n;
		for (int i=0;i<n;i++) cin >> sta[i];
		for (int i=0;i<n;i++) cin >> cons[i];
		int pos,suc,cnt;
		for (pos=0;pos<n;){
			int now=0;
			suc=1;
			for (int i=0;i<n;i++){
				cnt=(pos+i)%n;
				now=now+sta[cnt]-cons[cnt];
				if (now<0){
					suc=0;break;
				}
			}
			if (suc) break;
			if (cnt<pos){
				suc=0;break;
			}
			pos=cnt+1;
		} 
		cout << "Case " << kase << ": " ;
		if (suc) cout << "Possible from station " << pos+1<< endl ;
		else cout << "Not possible" << endl;
		
	}
	return 0;
}


