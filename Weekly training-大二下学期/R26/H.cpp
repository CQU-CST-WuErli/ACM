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
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node() {left = NULL; right = NULL; val = 0;}
};

Node* newNode() {
	return new Node();
}
void insert(Node* root, int val) {
	if (root->val == 0) {
		root->val = val;
		return;
	}
	if (val < root->val) {
		if (root->left == NULL) root->left = newNode();
		insert(root->left, val);
	}
	if (val > root->val) {
		if (root->right == NULL) root->right = newNode();
		insert(root->right, val);
	}
}

void dfs(Node* root, int val) {
	if (val == root-> val) return;
	if (val < root->val) {
		printf("E");
		dfs(root->left, val);
	}
	if (val > root->val) {
		printf("W");
		dfs(root->right, val);
	}
}
int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SI(n);
        Node* root = newNode();
        for (int i = 1; i <= n; i++) {
        	int x; SI(x);
        	insert(root, x);
        }
        int q;
        SI(q);
        // BUG;
        for (int i = 1; i <= q; i++) {
        	int x; SI(x);
        	dfs(root, x);
        	printf("\n");
        }
    }
	return 0;
}