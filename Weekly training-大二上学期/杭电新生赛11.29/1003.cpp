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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct P{
	int a[4];
	set<int> st;
	int c[4][4];
	int flag;
	void read() {
		rep(i,1,3) cin >> a[i];
	}
	void resize() {
		st.clear();
		rep(i,1,3) st.insert(a[i]);
		if (st.size()==3) {
			flag=1;
			rep(i,1,3) c[1][i]=a[i];
			sort(c[1]+1,c[1]+4);
			reverse(c[1]+1,c[1]+4);
		}
		else if (st.size()==2) {
			flag=2;
			if (a[1]==a[2]) c[2][1]=a[1],c[2][2]=a[3];
			else if (a[2]==a[3]) c[2][1]=a[2],c[2][2]=a[1];
			else if (a[1]==a[3]) c[2][1]=a[1],c[2][2]=a[2];
		}
		else if (st.size()==1) {
			flag=3;
			c[3][1]=a[1];
		}
	}
	bool operator < (const P& rhs) const {
		if (flag!=rhs.flag) return flag<rhs.flag;
		else {
			if (flag==1) {
				rep(i,1,3) if (c[1][i]!=rhs.c[1][i]) return c[1][i]<rhs.c[1][i];
				return false;
			}
			else if (flag==2) {
				if (c[2][1]==rhs.c[2][1]) return c[2][2]<rhs.c[2][2];
				else return c[2][1]<rhs.c[2][1];
			}
			else if (flag==3) {
				return c[3][1]<rhs.c[3][1];
			}
		} 
	}
};

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;SI(t);
	while (t--) {
		P S,T;
		S.read();S.resize();
		T.read();T.resize();
		int tmp[4];
		rep(i,1,3) tmp[i]=S.a[i];
//		rep(i,1,3) cout << tmp[i] << endl;
//		cout << S.flag << endl;
		if (T<S) cout << "1.000\n";
		else {
//			cout <<1 << endl;
			int tot=0;
			rep(i,1,3){
				int flag=0;
				rep(j,1,6) if (j!=tmp[i]) {
					S.a[i]=j;
					S.resize();
					
					if (T<S) {
//						rep(k,1,3) cout << S.a[k] << ' ';
//						cout << endl;
						flag++;
					}
				}
				rep(k,1,3) S.a[k]=tmp[k];
				S.resize();
				tot=max(flag,tot);
			}
//			lookln(tot);
			double ans=tot*1.0/6.0;
			printf("%.3f\n",ans);
		}
	}
	return 0;
}

