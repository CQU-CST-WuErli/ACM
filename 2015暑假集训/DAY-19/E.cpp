//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015�� CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 1000000000
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=125;
const int S=8;
int n,m,s,c[N],st[N],dp[N][1<<S][1<<S];
// s1��һ���˽̵�  s2�������˵�   s0��ʾʣ��γ̼��� 
int dfs(int i,int s0,int s1,int s2){
	if (i==m+n) return s2==(1<<s)-1?0:INF;
	int &ans=dp[i][s1][s2];
	if (ans>=0) return ans;
	ans=INF;
	if (i>=m) ans=dfs(i+1,s0,s1,s2);    // ǰm����ѡ������n����ѡ�ɲ�ѡ 
	// ���ѡ�����
	int m0=st[i]&s0;    // ʣ��γ��п��Խ̵� 
	int m1=st[i]&s1;    // �̵ܽĿ����Ѿ���һ���˽̵� 
	s0 ^=m0;            // ����ɾ�� 
	s1=(s1^m1)|m0;      // �ѱ�������˽̵�ɾ�����Ұѱ��һ���˽̵���ӽ�ȥ 
	s2|=m1;     		// ��һ���˽̵ķ���s2�� 
	// �����˵���λ���� 
	ans=min(ans,c[i]+dfs(i+1,s0,s1,s2));
	return ans; 
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string tmp;
	while (getline(cin,tmp)){
		stringstream ss (tmp);
		ss >> s >> m >> n;
		if (s==0) break;
		for (int i=0;i<m+n;i++){
			getline(cin,tmp);
			stringstream ss(tmp);
			ss >> c[i];
			st[i]=0;
			int x;
			while (ss >> x) st[i] |= (1<<(x-1));    // ��λ���������� 
		}
		OFF(dp); 
		cout << dfs(0,(1<<s)-1,0,0) << endl;
	}
	return 0;
}


