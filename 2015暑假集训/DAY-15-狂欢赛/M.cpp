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
double a,d;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> a >> d){
		double min_t=0.00;
		for (int i=0;i<n;i++){
			double t,v;
			scanf("%lf%lf",&t,&v);
			double tmp_t,tmp_d;
			tmp_t=v/a;
//			look(tmp_t);
			tmp_d=0.5*a*tmp_t*tmp_t;
//			look(tmp_d);
			double temp;
			if (tmp_d>=d){
				temp=sqrt(2*d/a)+t;
			}
			else{
				temp=tmp_t+(d-tmp_d)/v+t;
			}
			if (temp<min_t){
				printf("%.10lf\n",min_t);
			}
			else {
				min_t=temp;
				printf("%.10lf\n",min_t);
			}
		}
	}
	return 0;
}


