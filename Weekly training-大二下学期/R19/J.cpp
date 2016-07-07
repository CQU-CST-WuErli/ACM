//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
struct P
{
	int id,grade;
	P(int id,int grade):id(id),grade(grade){}
	bool operator < (const P& rhs) const {
		if (grade==rhs.grade) return id<rhs.id;
		return grade < rhs.grade;
	}
};

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1 && n) {
	    set<P> st;
	    st.insert(P(1,1000000000));
	    int id,grade;
	    rep(i,1,n) {
	    	SII(id,grade);
	    	set<P>::iterator it1,it2;
	    	it1=st.lower_bound(P(id,grade));
	    	if (st.size()==1) {
	    		printf("%d %d\n", id,st.begin()->id);
	    	}
	    	else if (it1!=st.begin()) {
	    		it2=it1;it1--;
		   		int tt;
		   		if (abs(it1->grade-grade)<=abs(it2->grade-grade)) tt=it1->id;
	    		else tt=it2->id;
	    		printf("%d %d\n", id,tt);
	   		}
	   		else printf("%d %d\n", id,it1->id);
	    	st.insert(P(id,grade));
	    }
	}
	return 0;
}