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

double L;
double D;
typedef pair<double,double> P;
vector<P> vp;
int n;

double get_dis(double x,double y,double a,double b){
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> L){
		cin >> D;
		cin >> n;
		for (int i=0;i<n;i++){
			double x,y;
			cin >> x >>  y;
			double l,r;
			int dis=sqrt(D*D-y*y);
			l=(x-dis>=0?x-dis:0);
			r=(x+dis<=L?x+dis:L);
			vp.push_back(P(l,r));
		}	
		sort(vp.begin(),vp.end());
		int ans=1;
		double p=vp[0].second;
		for (int i=0;i<vp.size();i++){
			P x=vp[i];
			if (x.first<=p) continue;
			else {
				ans++;
				p=x.second;
			}			
		}
		cout << ans << endl;
		vp.clear();
	}
	return 0;
}


