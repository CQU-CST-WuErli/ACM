//  This is jiejianed from zzblack
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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=20000;
int ran[N];
double score[N][8];
int n;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && n){
		printf("Case %d: ",kase++);
		CLR(score);
		for (int i=1;i<=n;i++){
			double s[3];
			scanf("%lf%lf%lf",s+0,s+1,s+2);
			for (int j=0;j<8;j++){
				for (int k=0;k<3;k++){
					if (j&(1<<k)) score[i][j]+=s[k];
				}
			}
		}
		for (int i=1;i<=n;i++) scanf("%d",ran+i);
		int flag=1;
		int last_id=-1;
		double last_score=1e4;
		for (int i=1;i<=n;i++){
			int id=ran[i];
			double tmp=-1.00;
			for (int j=0;j<8;j++){
				if (score[id][j]<last_score) tmp=max(tmp,score[id][j]);
				if (abs(score[id][j]-last_score)<=eps && id>last_id) tmp=max(tmp,score[id][j]);
			}
			if (tmp<0){
				flag=0;break;
			} 
			last_id=id;
			last_score=tmp;
		}
		if (!flag) cout << "No solution\n";
		else printf("%.2lf\n",last_score);
	}
	return 0;
}


