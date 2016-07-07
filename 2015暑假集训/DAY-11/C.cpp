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
int ans[1100];      // i�����ܴﵽ��ֵ�Ĵη� 
int cnt;            // ��ǰ���� 
int maxd;           // maxd��������     


bool IDdfs(int cur, int step){
	if (step==maxd) return cur==n;
	int maxv=*max_element(ans,ans+cnt);
	if (cur<<(maxd-step)<n) return false;   // ����ȥ������һ����ֻ�赱ǰ���޷��ﵽ���� 402ms 
//	if (maxv<<(maxd-step) <n) return false;  //  �����ֵ�޷��ﵽ��ֱ�Ӽ�֦   892ms
//	if ((maxv+cur)<<(maxd-step-1)<n) return false; //�������뵱ǰ�ĺ��޷��ﵽ���֦���������ĵ����ֶ���һ�β���������-1   872ms
	for(int i=0;i<cnt;i++){
		ans[cnt++]=cur+ans[i];
		if (IDdfs(cur+ans[i],step+1)) return true;
		cnt--;              //���� 
		ans[cnt++]=cur-ans[i];
		if (cur-ans[i]>=0 && IDdfs(cur-ans[i],step+1)) return true;
		cnt--;              //���� 
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


