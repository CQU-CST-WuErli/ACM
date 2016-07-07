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
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=100000+100;

int tree[30][N];//��ʾÿ��ÿ��λ�õ�ֵ
int sorted[N];//�Ѿ��������
int toleft[30][N];//toleft[p][i]��ʾ��i���1��i�ж��ٸ����������

void build(int l,int r,int dep) {
    if(l==r)return;
    int mid=(l+r)>>1;
    int same=mid-l+1;//��ʾ�����м�ֵ���ұ�������ߵĸ���
    for(int i=l;i<=r;i++)
      if(tree[dep][i]<sorted[mid])
         same--;
    int lpos=l;
    int rpos=mid+1;
    for(int i=l;i<=r;i++) {
        if(tree[dep][i]<sorted[mid])//���м����С���������
             tree[dep+1][lpos++]=tree[dep][i];
        else if(tree[dep][i]==sorted[mid]&&same>0) {
            tree[dep+1][lpos++]=tree[dep][i];
            same--;
        }
        else  //���м�ֵ������ұ�
            tree[dep+1][rpos++]=tree[dep][i];
        toleft[dep][i]=toleft[dep][l-1]+lpos-l;//��1��i����ߵĸ���

    }
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}


//��ѯ�����k�������[L,R]�Ǵ����䣬[l,r]��Ҫ��ѯ��С����
int query(int l,int r,int k,int L,int R,int dep) {
    if(l==r)return tree[dep][l];
    int mid=(L+R)>>1;
    int cnt=toleft[dep][r]-toleft[dep][l-1];//[l,r]��λ����ߵĸ���
    if(cnt>=k) {
        //L+Ҫ��ѯ������ǰ��������ߵĸ���
        int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
        //��˵���ϲ�ѯ����ᱻ������ߵĸ���
        int newr=newl+cnt-1;
        return query(newl,newr,k,L,mid,dep+1);
    }
    else {
         int newr=r+toleft[dep][R]-toleft[dep][r];
         int newl=newr-(r-l-cnt);
         return query(newl,newr,k-cnt,mid+1,R,dep+1);
    }
}

int n,m;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2) {
		CLR(tree);
		rep(i,1,n) {
			scanf("%d",tree[0]+i);
			sorted[i]=tree[0][i]; 
		}
		sort(sorted+1,sorted+1+n);
		build(1,n,0);
		while (m--) {
			int u,v,k;
			SIII(u,v,k);
			cout << query(u,v,k,1,n,0) << endl;
		}
	}
	return 0;
}

