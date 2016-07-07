//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015�� CQU_CST_WuErli. All rights reserved.
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
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1]; // ������λ���ܷ�4������ǰ����ܷ���7,3�����Ҫ����
		dp[i][1]=dp[i-1][0];              // ��ͷֱ�ӷ���7
		dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];
		// �Ѿ�����,���Ѱ�����ǰ�����⣬û�е�ǰ���4����7��ֱ�ӷ�3 
	}
}
//dp[i][0] => ����<=i�Ĳ���37 �� 4 �����ĸ��� 
//dp[i][1] => ����==i�������λ��7�������� 
//dp[i][2] => ����<=i�ĺ�37 �� 4 �����ĸ��� 
ll cal(ll  a){
	ll sum=a;
	int cnt=0;
	CLR(A);
	while (a){
		A[++cnt]=a%10;
		a/=10;
	}
	A[cnt+1]=0;
	bool flag=0; // �жϵ�ǰ�Ƿ���37����4 
	ll ans=0;
	for (int i=cnt;i>=1;i--){
		ans+=dp[i-1][2]*A[i];
		if (flag){
			ans+=dp[i-1][0]*A[i];
		} 
		else {
			if (A[i]>4) ans+=dp[i-1][0];    // ���ܻ����4��ͷ����� 
			if (A[i]>7 && A[i+1]==3) ans+=dp[i][1];      // �ӱ�����Ϊ ��һλ�Ѿ�ȷ�� 
			if (A[i]>3) ans+=dp[i-1][1];    //  ����3��������ǰһλ������7 
			if (A[i]==4 || (A[i]==7) && A[i+1]==3) flag=1; // ������ͳ�����37����4 ��任������ 
		}
	}
	return sum-ans;   // û���ж����� 
}
//dp[i][0] => ����<=i�Ĳ���37 �� 4 �����ĸ��� 
//dp[i][1] => ����==i�������λ��7�������� 
//dp[i][2] => ����<=i�ĺ�37 �� 4 �����ĸ��� 
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


