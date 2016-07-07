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
//#define root 1,n,1
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

const int N=10000+100;
int n;

struct Node{
	bool have_value;
	int value;
	Node *lch,*rch;
	Node(){have_value=false;lch=NULL;rch=NULL;}
};

Node* newnode() {return new Node();};

void build(Node *root,int x){
	if (root->have_value==false) {
//		BUG;
		root->value=x;
		root->have_value=true;
		return ;
	}
	else {
		if (x<root->value){
			if (root->lch==NULL) root->lch=newnode();
			build(root->lch,x);
		}
		else if (x>root->value){
			if (root->rch==NULL) root->rch=newnode();
			build(root->rch,x);
		}
	}
}

int flag;
void dfs(Node *root,int x){
	if (x==root->value) return;
	if (x>root->value) {
		printf("W");
		dfs(root->rch,x);
	}
	else if (x<root->value){
		printf("E");
		dfs(root->lch,x);
	}
	return ;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	cin >> _;
	while (_--){
		scanf ("%d",&n);
		Node *root=newnode();
		for (int i=1;i<=n;i++) {
			int x;cin >> x;
			build(root,x);	
		} 
		int q;scanf("%d",&q);
		while (q--){
			int x;
			cin >> x;
			dfs(root,x);
			printf("\n");
		}
	}
	return 0;
}

