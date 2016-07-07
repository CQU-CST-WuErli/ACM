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

string s;
int n;

int maxPresetation(string &s,int l){
    int i=0,j=1,k=0,t;
	while(i<l && j<l && k<l){
		t=s[(i+k)%l]-s[(j+k)%l];  
        if(t==0)  
            k++;  
        else {  
        	if(t>0)  
                j+=k+1;  
            else i+=k+1;  
            if(i==j) j++;  
            k=0;  
        }
	}
	return min(i,j);
}

int nxt[21000];
void get_next(string &s){
	int i,j;
	i=0;j=-1;
	nxt[0]=-1;
	while (i<s.size()){
		if (j==-1 || s[i]==s[j]) i++,j++,nxt[i]=j;
		else j=nxt[j];
	}
}

int kmp(string &s,string &t){
	get_next(t);
	int i=0,j=0;
	
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	SI(_);
	while (_--){
		cin >> n;
		cin >> s;
		int pos1=maxPresetation(s,n);
		string t=s;
		reverse(ALL(t));
		int pos2=maxPresetation(t,n);
//		cout << pos1 << endl;
		string tmp1,tmp2;
		for (int i=pos1;s[i];i++) tmp1+=s[i];
		for (int i=0;i<pos1;i++) tmp1+=s[i];
		for (int i=pos2;t[i];i++) tmp2+=t[i];
		for (int i=0;i<pos2;i++) tmp2+=t[i];
		string tt=tmp2;
		tt+=tmp2;
		
	}
	return 0;
}

