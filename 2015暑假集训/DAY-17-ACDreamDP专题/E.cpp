//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
//
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
#define at(i,v) for (auto &i:v)
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

ll L,R;
int A[20];
ll dp[20][3];

void init(){
	CLR(dp);
	dp[0][0]=1;
	for (int i=1;i<=11;i++){
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1]; // 除了首位不能放4，可能前面可能放了7,3的情况要减掉
		dp[i][1]=dp[i-1][0];              // 开头直接放了7
		dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];
		// 已经包含,则已包含的前面随意，没有的前面放4，有7的直接放3 
	}
}
//dp[i][0] => 长度<=i的不含37 或 4 的数的个数 
//dp[i][1] => 长度==i的且最高位是7的数个数 
//dp[i][2] => 长度<=i的含37 或 4 的数的个数 
ll cal(ll  a){
	ll sum=a;
	int cnt=0;
	CLR(A);
	while (a){
		A[++cnt]=a%10;
		a/=10;
	}
	A[cnt+1]=0;
	bool flag=0; // 判断当前是否含有37或者4 
	ll ans=0;
	for (int i=cnt;i>=1;i--){
		ans+=dp[i-1][2]*A[i];
		if (flag){
			ans+=dp[i-1][0]*A[i];
		} 
		else {
			if (A[i]>4) ans+=dp[i-1][0];    // 可能会出现4开头的情况 
			if (A[i]>7 && A[i+1]==3) ans+=dp[i][1];      // 加本身，因为 这一位已经确定 
			if (A[i]>3) ans+=dp[i-1][1];    //  大于3，而他的前一位可能是7 
			if (A[i]==4 || (A[i]==7) && A[i+1]==3) flag=1; // 若本身就出现了37或者4 则变换处理方法 
		}
	}
	return sum-ans;   // 没有判断自身 
}
//dp[i][0] => 长度<=i的不含37 或 4 的数的个数 
//dp[i][1] => 长度==i的且最高位是7的数个数 
//dp[i][2] => 长度<=i的含37 或 4 的数的个数 
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	cin >> L >> R;
	cout << cal(R+1)-cal(L) << endl;
	return 0;
}


