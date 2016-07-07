//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct P{
	int x,y;
}p[4];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y) {
		int	area=0;
		for (int i=1;i<=3;i++) area+=p[i].x*p[i].y;
		double x=sqrt((double)area);
		if ((int)x*(int)x!=area) {
			cout << -1 << endl;
			continue;
		}
		int len=(int)sqrt(area);
//		lookln(len);
		int flag=1;
		for (int i=1;i<=3;i++) if (p[i].x>len || p[i].y>len) {
			flag=0;
			break;
		}
		int id=0;
		queue<int> q;
		if (flag) {
			flag=0;
			for (int i=1;i<=3;i++) {
				if (p[i].x==len || p[i].y==len) {
					id=i;flag++;q.push(i);
				}
			}
		}
		if (flag) {
			if (flag==1) {
				int a,b;
				for (int i=1;i<=3;i++) {
					if (i==id) continue;
					else {
						a=i;break;
					}
				}
				for (int i=1;i<=3;i++) {
					if (i==id || i==a) continue;
					else {
						b=i;break;
					}
				}
				int tmp=len-(p[id].x==len?p[id].y:p[id].x);
				if (p[a].x==tmp && p[b].x==tmp && p[a].y+p[b].y==len) { 
					cout << len << endl;
					for (int i=1;i<=(p[id].y==len?p[id].x:p[id].y);i++) {
						for (int j=1;j<=(p[id].y==len?p[id].y:p[id].x);j++) printf("%c",'A'+id-1);
						cout << endl;
					}
					
					char A='A'+a-1,B='A'+b-1;
					for (int i=1;i<=tmp;i++) {
						for (int j=1;j<=len;j++) {
							if (j<=p[a].y) cout << A;
							else cout << B;
						}
						cout << endl;
					}
				}
				else if (p[a].x==tmp && p[b].y==tmp && p[a].y+p[b].x==len) {
					cout << len << endl;
					for (int i=1;i<=(p[id].y==len?p[id].x:p[id].y);i++) {
						for (int j=1;j<=(p[id].y==len?p[id].y:p[id].x);j++) printf("%c",'A'+id-1);
						cout << endl;
					}
					char A='A'+a-1,B='A'+b-1;
					for (int i=1;i<=tmp;i++) {
						for (int j=1;j<=len;j++) {
							if (j<=p[a].y) cout << A;
							else cout << B;
						}
						cout << endl;
					}
				}
				else if (p[a].y==tmp && p[b].x==tmp && p[a].x+p[b].y==len) { 
					cout << len << endl;
					for (int i=1;i<=(p[id].y==len?p[id].x:p[id].y);i++) {
						for (int j=1;j<=(p[id].y==len?p[id].y:p[id].x);j++) printf("%c",'A'+id-1);
						cout << endl;
					}
					char A='A'+a-1,B='A'+b-1;
					for (int i=1;i<=tmp;i++) {
						for (int j=1;j<=len;j++) {
							if (j<=p[a].x) cout << A;
							else cout << B;
						}
						cout << endl;
					}
				}
				else if (p[a].y==tmp && p[b].y==tmp && p[a].x+p[b].x==len) { 
					cout << len << endl;
//					lookln(id);
					for (int i=1;i<=(p[id].y==len?p[id].x:p[id].y);i++) {
						for (int j=1;j<=(p[id].y==len?p[id].y:p[id].x);j++) printf("%c",'A'+id-1);
						cout << endl;
					}
					char A='A'+a-1,B='A'+b-1;
					for (int i=1;i<=tmp;i++) {
						for (int j=1;j<=len;j++) {
							if (j<=p[a].x) cout << A;
							else cout << B;
						}
						cout << endl;
					}
				}
				else flag=0;
			}
			else if (flag==2) flag=0;
			else if (flag==3) {
				cout << len << endl;
				int tt=0;
				for (int i=1;i<=3;i++) {
					tt+=(p[i].x==len?p[i].y:p[i].x);
				}
				if (tt!=len) flag=0;
				else {
					for (int i=1;i<=3;i++) {
						for (int j=1;j<=(p[i].y==len?p[i].x:p[i].y);j++) {
							for (int k=1;k<=(p[i].x==len?p[i].x:p[i].y);k++) printf("%c",'A'+i-1);
							cout << endl;
						}
					}
				}
			} 
		}
		if (!flag) cout << -1 << endl;
	}
	return 0;
}

