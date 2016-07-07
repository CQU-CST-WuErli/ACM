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

string s;
map<string,int> mp;
map<int,string> rmp;
void init() {
	mp["063"]=0;rmp[0]="063";
	mp["010"]=1;rmp[1]="010";
	mp["093"]=2;rmp[2]="093";
	mp["079"]=3;rmp[3]="079";
	mp["106"]=4;rmp[4]="106";
	mp["103"]=5;rmp[5]="103";
	mp["119"]=6;rmp[6]="119";
	mp["011"]=7;rmp[7]="011";
	mp["127"]=8;rmp[8]="127";
	mp["107"]=9;rmp[9]="107";
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
	while(getline(cin,s)) {
	    if (s[0]=='B') break;
	    string a,b;
	    int i;
	    for (i=0;i<s.size();i++) {
	    	if (s[i]=='+') break;
	    	a+=s[i];
	    }
	    i++;
	    for(;i<s.size();i++) {
	    	if (s[i]=='=') break;
	    	b+=s[i];
	    }
	    // cout << a << b << endl;
	    ll ans=0;
	    ll tt=0;
	    for (i=0;i<a.size();i+=3) {
	    	string tmp;
	    	for (int j=0;j<3;j++) tmp+=a[i+j];
	    	tt=tt*10LL+1LL*mp[tmp];
	    }
	    // cout << tt << ' ';
	    ans+=tt;
	    tt=0;
	    for(i=0;i<b.size();i+=3) {
	    	string tmp;
	    	for (int j=0;j<3;j++) tmp+=b[i+j];
	    	tt=tt*10LL+1LL*mp[tmp];
	    }
	    ans+=tt;
	    // cout << tt << endl;
	    // cout << ans << endl;
	   	vector<string> v;
	   	while(ans) {
	   	    tt=ans%10;
	   	    ans/=10;
	   	    v.push_back(rmp[tt]);
	   	}
	   	cout << s;
	   	for(i=v.size()-1;i>=0;i--) cout << v[i];
	   	cout << endl;
	}
	return 0;
}