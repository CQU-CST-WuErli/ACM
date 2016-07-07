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
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << "x=" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int ans[1100];      // i步所能达到的值的次方 
int cnt;            // 当前步数 
int maxd;           // maxd是最大深度     


bool IDdfs(int cur, int step){
	if (step==maxd) return cur==n;
	int maxv=*max_element(ans,ans+cnt);
	if (cur<<(maxd-step)<n) return false;   // 无需去除最大的一个，只需当前的无法达到就行 402ms 
//	if (maxv<<(maxd-step) <n) return false;  //  当最大值无法达到是直接剪枝   892ms
//	if ((maxv+cur)<<(maxd-step-1)<n) return false; //当最大的与当前的和无法达到便剪枝，加上最大的等于又多了一次操作，所以-1   872ms
	for(int i=0;i<cnt;i++){
		ans[cnt++]=cur+ans[i];
		if (IDdfs(cur+ans[i],step+1)) return true;
		cnt--;              //回溯 
		ans[cnt++]=cur-ans[i];
		if (cur-ans[i]>=0 && IDdfs(cur-ans[i],step+1)) return true;
		cnt--;              //回溯 
	}
	return false;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n && n){
		for (maxd=0;;maxd++){
			CLR(ans);
			cnt=1;
			ans[0]=1;
			if (IDdfs(1,0)){
				cout << maxd << endl;
				break;
			}
		}	
	}
	return 0;
}


