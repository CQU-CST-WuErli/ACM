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

int m;
string s;
string ans;
int caret;    // ÓÒ±ßµ¥´ÊµÄÎ»ÖÃ 
int tail; 
int max_len;
int mode;        // 0->insert    1->overwrite
int cop;        // 0->Nothing    1->start
int copypos;
string copbd;
void L() {
	if (caret) caret--;
}
void R() {
	if (caret<max_len) caret++;
}
void S() {
	mode^=1;
	cop=0;
}
void D() {
	if (caret<max_len && !cop) {
		ans.erase(caret);
		max_len--;
	}
	if (cop==1) {
		cop=0;
		while (caret>copypos) {
			ans.erase(caret-1);
			caret--; 
			max_len--;
		}
	}
}
void B() {
	if (caret) {
		ans.erase(caret-1);
		caret--;
	}
	cop=0;
}
void C() {
	if (cop==0) {
		cop=1;
		copypos=caret;
	} 
	else if (cop==1){
		cop=0;
		copbd.clear();
		for (int i=copypos;i<caret;i++) copbd+=ans[i];
	}
}
void V() {
	if (copbd.size()) {
		if (mode==0) {
			if (max_len+copbd.size()>m) return;
			for (int i=0;i<copbd.size();i++) {
				ans.insert(caret,1,copbd[i]);
			}
			max_len+=copbd.size();
		}
		else {
			if (caret+copbd.size()>m) return;
			for (int i=0;i<copbd.size();i++) {
				ans[caret++]=copbd[i];
			} 
			max_len=max(caret+(int)copbd.size(),max_len);
			caret+=copbd.size();
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;cin >> _;
	while (_--) {
		cin >> m;
		cin >> s;
		caret=max_len=0;
		mode=0;cop=0;tail=0;
		copypos=0;copbd.clear();
		for (int i=0;s[i];i++) {
			cop=0;
			if (s[i]>='a' && s[i]<='z') {
				if (mode==0) {
					ans+=s[i];
					caret++;max_len++;
					if (max_len>=m) continue;
				}
				else if (mode==1) {
					if (caret<max_len) ans[caret++]=s[i];
					else {
						ans+=s[i];
						caret++;max_len++;
						if (max_len>=m) continue;
					}
				}
			}
			else {
				if (s[i]=='L') {
					L();
				}
				else if (s[i]=='R') {
					R();
				}
				else if (s[i]=='S') {
					S();
				}
				else if (s[i]=='D') {
					D();
				}
				else if (s[i]=='B') {
					B();
				}
				else if (s[i]=='C') {
					C();
				}
				else if (s[i]=='V') {
					V();
				}
			}
		}
		if (ans.size()==0) cout << "NOTHING\n";
		else cout << ans << endl;
	}
	return 0;
}

