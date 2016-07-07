/********************************************
Author         :Crystal
Created Time   :
File Name      :
********************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
double eps = 1e-8;
int c[1003];
struct node
{
	int f;
	double r;
	int d;
}q[1000000];
int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int n,f;
	double k = (1+sqrt(5))/2;
	while(scanf("%d%d",&n,&f) != EOF){
		int ans = 0, cnt = 1;
		double hope = 0;
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		node a;
		a.r = 1,a.f = f;
		a.d = 0;
		q[ans]=a;
		while(ans < cnt){
			node x = q[ans];
			ans++;
			if(x.r <= eps) continue;
			for(int i=1;i<=n;i++){
				
				if(x.f>c[i]){
					hope += 1.0*x.r*1/(1.0*n)*((int)(k*c[i]*c[i])+x.d);
				}
				else{
					node y;
					y.f = x.f + c[i];
					y.r = x.r*1/n;
					y.d = x.d + 1;
					if(y.r >= eps)q[cnt++]=y;
				}
			}
		}
		printf("%.3lf\n",hope);
	}
	return 0;
}
