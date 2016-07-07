//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
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
const int N=1010;
int t;  
int n;  
int dead[N];
int score[N];
struct Node{
	int dead,score;
	bool operator < (const Node& rhs) const {
		if (score==rhs.score) return dead<rhs.dead;
		else return score>rhs.score;
	}   
}a[N];  
bool vis[N];
        
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif  
	cin >> t;
	while (t--){
		cin >> n;
		CLR(vis);
		for (int i=1;i<=n;i++) scanf("%d",&a[i].dead);
		for (int i=1;i<=n;i++) scanf("%d",&a[i].score);
		sort(a+1,a+1+n);
		int ans=0;
//		for (int i=1;i<=n;i++) cout << a[i].dead << " " << a[i].score << endl;
		for (int i=1;i<=n;i++){
			int j;
			for (j=a[i].dead;j>0;j--){
				if (!vis[j]) {
					vis[j]=1;break;
				}
			}
			if (j==0) ans+=a[i].score;
		}
		cout << ans << endl;
	}   
	return 0;
}       


