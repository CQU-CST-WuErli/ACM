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
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define at(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=2e5+10;

int n,k,a;
int m;
int p[N];


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> k >> a){
		cin >>m;
		for (int i=1;i<=m;i++) scanf("%d",p+i);
		set<int> sp;
		sp.insert(0);
		sp.insert(n+1);
		int ans=-1;
		int maxn=(n+1)/(a+1);
		set<int>::iterator it;
		for (int i=1;i<=m;i++){
			sp.insert(p[i]);
			it=sp.upper_bound(p[i]);
			int r=*it;
			it=sp.lower_bound(p[i]);
			int l=*(--it);
			maxn-=(r-l)/(a+1);
			maxn+=((p[i]-l)/(a+1) + (r-p[i])/(a+1));
			if (maxn<k){
				ans=i;break;
			}
		}	
		printf("%d\n",ans);	
	} 
	return 0;
}


