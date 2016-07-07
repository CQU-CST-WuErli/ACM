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
#define For_UVa if (kase!=1) cout << endl
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
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int a[50050];

struct Node {
    Node* ch[2];
    int rank;// 当前节点在序列中的位置
    int s;// 节点总数
    int flip;// 旋转标记
    int add;// 增减标记
    int val;// 节点的值
    int v;  // 原数组中下标
    int sum;
    Node() {
        rank=1;
        s=1;
        flip=0;
        add=0;
        sum=0;
        ch[0]=ch[1]=NULL;
    }
    int cmp(int x) const {
        if (x==rank) return -1;
        return x<rank? 0 : 1;
    }
    void maintain(){
        s=1;
        rank=1;
        sum=val;
        if (ch[0]!=NULL) {
            s+=ch[0]->s;
            rank+=ch[0]->s;
            sum+=ch[0]->sum;
        }
        if (ch[1]!=NULL) {
            s+=ch[1]->s;
            sum+=ch[1]->sum;
        }
    }
    void pushdown(){
        if (flip) {
            flip=0;
            if(ch[0]!=NULL) {
            	ch[0]->flip^=1;
            	swap(ch[0]->ch[0],ch[0]->ch[1]);
            }
            if(ch[1]!=NULL) {
            	ch[1]->flip^=1;
            	swap(ch[1]->ch[0],ch[1]->ch[1]);
            }
        }
        if (add) {
            if (ch[0]!=NULL) {
				ch[0]->val+=add;
                ch[0]->add+=add;
                ch[0]->sum+=add*ch[0]->s;
            }
            if (ch[1]!=NULL) {
				ch[1]->val+=add;
                ch[1]->add+=add;
                ch[1]->sum+=add*ch[1]->s;
            }
            add=0;
        }
    }
};

Node* root=NULL;

void rotate(Node* &o,int d) {
    Node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o=k;
}

void splay(Node* &o,int k) {
    //correct
    o->pushdown();
    o->maintain();
    int d= o->cmp(k);
    if (d==1) k -= o->rank;
    if (d!=-1) {
        Node* p = o->ch[d];
        p->pushdown();
        p->maintain();
        int d2 = p->cmp(k);
        int k2 = (d2==0 ? k : k-p->rank);
        if (d2!=-1) {
            splay(p->ch[d2],k2);
            if (d==d2) rotate(o,d^1);
            else rotate(o->ch[d], d);
        }
        rotate(o,d^1);
    }
}

Node* build(int l,int r) {
    Node* p;
    int mid=(l+r)>>1;
    p=new Node();
    p->val=a[mid];
    p->v=mid;
    p->s=r-l+1;
    p->rank=mid-l+1;
    p->flip=0;
    p->add=0;
    p->ch[0]=p->ch[1]=NULL;
    if (mid-1>=l) p->ch[0]=build(l,mid-1);
    if (mid+1<=r) p->ch[1]=build(mid+1,r);
    p->maintain();
    return p;
}

int flag;

void InOrder(Node* o) {
    o->pushdown();
    o->maintain();
    if (o->ch[0]!=NULL) InOrder(o->ch[0]);
    if (o->v) {
        printf("%d ",o->val);
    }
    if (o->ch[1]!=NULL) InOrder(o->ch[1]);
}

// 分裂
void split(Node* o,int k,Node* &left,Node* &right) {
    splay(o,k);
    left=o;
    right=o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}

// 合并
Node* merge(Node* left,Node* right) {
    splay(left, left->s);
    left->ch[1]=right;
    left->maintain();
    return left;
}

void update(int l,int r,int val) {
    Node *left,*mid,*right,*o;
    split(root,l,left,o);
    split(o,r-l+1,mid,right);
    mid->add+=val;
    mid->val+=val;
    mid->pushdown();
    mid->maintain();
    root=merge(merge(left,mid),right);
}

void reverse(int l,int r) {
    Node *left,*mid,*right,*o;
    split(root,l,left,o);
    split(o,r-l+1,mid,right);
    mid->flip^=1;
    swap(mid->ch[1],mid->ch[0]);
    mid->pushdown();mid->maintain();
    root=merge(merge(left,mid),right);
}

void revolve(int l,int r,int T) {
    int len=r-l+1;
    T%=len;
    Node *left,*mid,*right,*o;
    split(root,l,left,o);
    split(o,r-l+1,mid,right);
    Node *tl,*tr;
    split(mid,len-T,tl,tr);
    mid=merge(tr,tl);
    mid->pushdown();mid->maintain();
    root=merge(merge(left,mid),right);
}


int query(int l,int r) {
	Node *left,*mid,*right,*o;
	split(root,l,left,o);
	split(o,r-l+1,mid,right);
	mid->pushdown();
	mid->maintain();
	int ret=mid->sum;
	root=merge(merge(left,mid),right);
	return ret;
}

int main(int argc, char const *argv[]) {
	//freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
		SI(n);
		rep(i,1,n) SI(a[i]);
		string s;
		cout << "Case " << kase << ":\n";
		// rep(i,1,n) cout << a[i] << ' ';
		// cout << endl;
		a[0]=0;
		root=build(0,n);
		// InOrder(root);
		// cout << endl;
		while (cin >> s) {
			int l,r;
			if (s[0]=='E') break;
			SII(l,r);
			if (s[0]=='A') {
				update(l,l,r);
			}
			if (s[0]=='S') {
				update(l,l,-r);
			}
			if (s[0]=='Q') {
				cout << query(l,r) << endl;
			}
		}
	}
	return 0;
}
