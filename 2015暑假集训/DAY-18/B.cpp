//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=50;
int n;
int dp[N*3];        // 以ID为i的方块的第几个状态为顶的最大高度 
struct Block{
	int l,w,h;
	bool operator < (const Block& rhs) const {
		return l*w>rhs.l*rhs.w;
	}
};
vector<Block> block;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && n){
		
		for (int i=0;i<n;i++){
			int l,w,h;
			cin >> l >> w >> h;
			block.push_back(Block{l,w,h});
			block.push_back(Block{w,h,l});
			block.push_back(Block{h,l,w});
		}
		CLR(dp);
		sort(ALL(block));
//		At(i,block) printf("%d %d %d\n",i.l,i.w,i.h);
		for (int i=0;i<3*n;i++){
			dp[i]=block[i].h;
			for (int j=0;j<i;j++){
				if ( (block[i].l<block[j].l && block[i].w<block[j].w) ||
				 (block[i].l<block[j].w && block[i].w<block[j].l)) 
				 	dp[i]=max(dp[i],dp[j]+block[i].h);
			}
		}
		int ans=0;
		for (int i=0;i<3*n;i++) ans=max(ans,dp[i]);
		printf("Case %d: maximum height = ",kase++);
		cout << ans << endl;
		block.clear();
	}
	return 0;
}


