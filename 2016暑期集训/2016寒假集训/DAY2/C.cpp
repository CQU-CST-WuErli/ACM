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
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Line {
	int x1,x2,y1,y2;
	void read() {
		SII(x1,y1);
		SII(x2,y2);
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
	}
	bool operator < (const Line& rhs) const {
		return x1<rhs.x1;
	}
};

int n;
vector<Line> vl,hl;

bool judge(Line& v1,Line& v2,Line& h) {
	int l=v1.x1,r=v2.x1;
	int up=min(v1.y2,v2.y2),down=max(v1.y1,v2.y1);
	if (h.x1<=l && h.x2>=r && h.y1>=down && h.y1<=up) return true;
	return false;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		Line tmp;
		vl.clear();hl.clear();
		for (int i=1;i<=n;i++) {
			tmp.read();
			if (tmp.x1==tmp.x2) vl.push_back(tmp);
			else hl.push_back(tmp);
		}
		sort(vl.begin(),vl.end());
		int ans=0;
		for (int i=0;i<vl.size();i++) {
			for (int j=i+1;j<vl.size();j++) {
				int cnt=0;
				for (int k=0;k<hl.size();k++) {
					if (judge(vl[i],vl[j],hl[k])) cnt++;
				}		
				ans+=(cnt*(cnt-1))/2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

