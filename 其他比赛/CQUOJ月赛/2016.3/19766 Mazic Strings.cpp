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
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <ctype.h>
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
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

bool check(int base, char c) {
    if (base<=10) return c>='0' && c<='0'+base-1;
    else {
    	int ex=base-10;
    	if (c>='0' && c<='9') return true;
    	c=tolower(c);
    	return (c>='0' && c<='9') || (c>='a' && c<='a'+ex-1);
    }
}

int getval(char c) {
	if (c>='0' && c<='9') return c-'0';
	else return tolower(c)-'a'+10;
}


int get(string& s) {
	int i=0;
	int ret=-1;
	while(i<s.size()) {
	    if (!isdigit(s[i])) {
	    	i++;
	    	continue;
	    }
	    int base=0;
	    for (;isdigit(s[i]);i++) base=base*10+s[i]-'0';
	    i++;
		int tmp=0;
		for(;check(base,s[i]);i++) {
			tmp=tmp*base+getval(s[i]);
		}
		ret=max(ret,tmp);
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    string s;
    while(getline(cin,s)) {
        int ans=get(s);
        while (getline(cin,s)) {
        	if (s.size()==0) break;
        	ans=max(ans,get(s));
        }
        if (ans==-1) cout << "Poor TaoSama\n";
        else cout << ans << endl;
    }
	return 0;
}