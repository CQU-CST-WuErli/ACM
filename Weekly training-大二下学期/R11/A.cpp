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


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    string tmp;
    while(cin >> tmp) {
        s += tmp;
    }
    for(int i=0;i<s.size();i++) {
        if(i<s.size()-4) {
            if(s[i]=='A' && s[i+1]=='p' && s[i+2]=='p' && s[i+3]=='l' && s[i+4]=='e') puts("MAI MAI MAI!");
        }
        if(i<s.size()-5) {
            if(s[i]=='i' && s[i+1]=='P' && s[i+2]=='h' && s[i+3]=='o' && s[i+4]=='n' && s[i+5]=='e') puts("MAI MAI MAI!");
        }
        if(i<s.size()-3) {
            if(s[i]=='i' && s[i+1]=='P' && (s[i+2]== 'o'|| s[i+2]=='a') && s[i+3]=='d') puts("MAI MAI MAI!");
        }
        if(i<s.size()-3) {
            if(s[i]=='S' && s[i+1]=='o' && s[i+2]=='n' && s[i+3]=='y') puts("SONY DAFA IS GOOD!");
        }
    }
	return 0;
}