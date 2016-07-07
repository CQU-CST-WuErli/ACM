//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
#define look(x) cout << #x  << "= "<< x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

vector<ll> vc;
queue<ll> llq;
set<ll> st;
void init(){
	llq.push(4);
	llq.push(7);
	vc.push_back(4);
	vc.push_back(7);
	st.insert(4);
	st.insert(7);
	while(!llq.empty()){	
		ll x=llq.front();llq.pop();
		if (x>1e10) break;
		vc.push_back(x*10+4);
		vc.push_back(x*10+7);
		llq.push(x*10+4);
		llq.push(x*10+7);
		st.insert(x*10+4);
		st.insert(x*10+7);
	}
	sort(vc.begin(),vc.end());
}
ll fac[15]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int Hash[15],pos[15];

ll n,k;

void CantorReverse(int index,int t){ // index是第k-1个序列，不包含开始序列， t是个元素 
	index--;int tmp;
	for (int i=0;i<t;i++){
		tmp=index/fac[t-i-1];
//		look(index);
//		look(tmp);
		for (int j=0;j<=tmp;j++)
			if (Hash[j]) tmp++;
		pos[i]=tmp+1;
//		cout << tmp+1 << endl;
		Hash[tmp]=1;
		index%=fac[t-i-1];
	}
//	for (int i=0;;i++) {
//		if (pos[i]) cout << pos[i] << endl;
//		else break;
//	}
//	cout << endl;
	return ;
}


int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	CLR(Hash);CLR(pos);
	scanf("%lld%lld",&n,&k);
	if (n<=12 && k>fac[n]) printf("-1\n");
	else {
		int amount=13;
		for (int i=1;i<=12;i++){
			if (k<fac[i]){
				amount=i;break;
			}
		}
//		look(amount);
		int ans=0;
		CantorReverse(k,amount);
		int stay=n-amount;
		for (int i=0;i<vc.size();i++){
			if (vc[i]>n) break;
			if (vc[i]<=stay) ans++;
			else {
				int num=pos[vc[i]-stay-1]+stay;
				if (st.count(num)) ans++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}


