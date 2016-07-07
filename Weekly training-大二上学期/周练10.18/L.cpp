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
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Node{
	int val;
	Node *left,*right;
	Node():val(-1),left(NULL),right(NULL){}
};
int flag;

Node* newnode() {return new Node();}

void build(Node* root,int val,string &s) {
	if (s.size()==0) {
		if (root->val!=-1) flag=0;
		root->val=val;
		return;
	}
	for (int i=0;i<s.size();i++){
		if (s[i]=='L') {
			if (root->left==NULL) root->left=newnode();
			root=root->left;
		}
		else if (s[i]=='R') {
			if (root->right==NULL) root->right=newnode();
			root=root->right; 
		}
	}
	if (root->val!=-1) flag=0;
	root->val=val;
}


void judge(Node* root) {
	if (root->val==-1) flag=0;
	if (root->left!=NULL) judge(root->left);
	if (root->right!=NULL) judge(root->right);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	while (cin >> s) {
		if (s=="()")break;
		flag=1;
		Node* root=newnode();
		string tmp;int tt=0;
		int to=0;
		tmp.clear();
		for (int i=0;i<s.size();i++){
			if (s[i]=='(' || s[i]==')') continue;
			else if (s[i]==',') {
				to=1;continue;
			}
			if (to==0) tt=tt*10+s[i]-'0';
			else tmp+=s[i];
		}
		build(root,tt,tmp);
//		cout << s << endl;
		while (cin >> s) {
			if (s=="()")break;
			tmp.clear();tt=0;to=0;
			for (int i=0;i<s.size();i++){
				if (s[i]=='(' || s[i]==')') continue;
				else if (s[i]==',') {
					to=1;continue;
				}
				if (to==0) tt=tt*10+s[i]-'0';
				else tmp+=s[i];
			}
			
			if (tt==0) flag=0;
 			else {
 				build(root,tt,tmp);
 			}
// 			cout << s << endl;
		}
		judge(root);
		if (flag==0) {
			cout << "not complete\n";
			continue;
		}
		else {
			queue<Node*> q;
			cout << root->val;
			if (root->left!=NULL) q.push(root->left);
			if (root->right!=NULL) q.push(root->right);
			while(!q.empty()) {
				Node* x=q.front();q.pop();
				cout << ' ' << x->val;
				if (x->left!=NULL) q.push(x->left);
				if (x->right!=NULL) q.push(x->right);
			}
			cout << endl;
		}
	}
	return 0;
}

