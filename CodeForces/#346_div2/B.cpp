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

struct P
{
	string name;
	int score;
	P(string &s,int ns) {
		name=s;
		score=ns;
	}
	bool operator < (const P& rhs) const {
		return score>rhs.score;
	}
};
vector<P> reg[10010];
int n,m;
set<int> st[10010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
    	rep(i,0,m) reg[i].clear(),st[i].clear();
    	string name;
    	int score;
    	int id;
        rep(i,1,n) {
        	cin >> name;
        	SII(id,score);
        	reg[id].push_back(P(name,score));
        }
        rep(i,1,m) sort(reg[i].begin(),reg[i].end());
        for (int i=1;i<=m;i++) {
        	if (reg[i].size()<=2) cout << reg[i][0].name << ' ' << reg[i][1].name << endl;
        	else {
        		if ( reg[i][1].score==reg[i][2].score) puts("?");
        		else cout << reg[i][0].name << ' ' << reg[i][1].name << endl;
        	}
        }
    }
	return 0;
}