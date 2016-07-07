//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

typedef queue<ll> Q;
typedef set<int> S;




int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int t;
	int kase=1;
	while (cin >> t && t){
		printf("Scenario #%d\n",kase++);
		Q all[1100];
		map<ll,int> mq;
		Q teamq;
		for (int i=1;i<=t;i++){
			ll tot;
			scanf("%lld",&tot);
			for (int j=1;j<=tot;j++){
				int temp;
				scanf("%d",&temp);
				mq[temp]=i;
			}
		}                            
		//Ó³Éä
		string s;
		while(cin>> s){
			if (s == "STOP") break;
			if (s == "ENQUEUE"){
				ll ele;
				scanf("%lld",&ele);
				int temp=mq[ele];
				if (all[temp].empty()) teamq.push(temp);
				all[temp].push(ele);
			}
			else if (s == "DEQUEUE"){
				int temp=teamq.front();
				printf("%lld\n",all[temp].front());all[temp].pop();
				if (all[temp].empty()) teamq.pop();
			}
		}
		printf("\n");
	}
	return 0;
}


