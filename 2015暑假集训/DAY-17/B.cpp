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

const int N=1e6+10;

struct P{
	int x,y;
	int w,h;
}pot[N];

int n,W,H;
int t;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	for (int kase=1;kase<=t;kase++){
		if (kase!=1) cout << endl;
		scanf("%d%d%d",&n,&W,&H);
		int cnt=0;
		pot[cnt].x=pot[cnt].y=0;
		pot[cnt].w=W;pot[cnt++].h=H;
		for (int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
//			look(a);look(b);
			for (int j=0;j<cnt;j++){
				int x=pot[j].x,y=pot[j].y;
				int w=pot[j].w,h=pot[j].h;
				if (a>x && a<x+w && b>y && b<y+h){
					pot[cnt].x=x;pot[cnt].y=y;
					pot[cnt].w=w;pot[cnt++].h=b-y;
					pot[cnt].x=x;pot[cnt].y=y;
					pot[cnt].w=a-x;pot[cnt++].h=h;
					pot[cnt].x=x;pot[cnt].y=b;
					pot[cnt].w=w;pot[cnt++].h=h+y-b;
					pot[cnt].x=a;pot[cnt].y=y;
					pot[cnt].w=w+x-a;pot[cnt++].h=h;
					pot[j].w=0;
//					BUG(74);
				}
			}			
		}
		int id,len=0;
		for (int i=0;i<cnt;i++){
			int tmp=min(pot[i].w,pot[i].h);
			if (tmp>len){
				len=tmp;
				id=i;
			}
		}
		printf("%d %d %d\n",pot[id].x,pot[id].y,len);
	}
	return 0;
}


