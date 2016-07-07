#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 500100;
double sum[maxn], rev[maxn], con[maxn];
int a[maxn], dep[maxn];
double dp[55][maxn];
double getup(int id, int y ,int x){
    return dp[id - 1][y] - con[y] + sum[y] * rev[y] - (dp[id - 1][x] - con[x] + sum[x] * rev[x]);
}
double getdown(int y, int x){
    return sum[y] - sum[x];
}
double getdp(int id, int x, int y){
    return dp[id - 1][x] + con[y] - con[x] - sum[x] * (rev[y] - rev[x]);
}
int main()
{
	#ifdef LOCAL
	//freopen("C:\\Users\\¦±¦±\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\¦±¦±\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	while(t--) {
	    int n, k;
	    scanf("%d %d", &n, &k);
	    sum[0] = rev[0] = con[0] = 0;
	    for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            rev[i] = rev[i - 1] + 1.0 / a[i];
            con[i] = con[i - 1] + sum[i] / a[i];
            dp[1][i] = con[i];
	    }
	    /*for(int i = 1; i <= n; i++)
            dp[i][1] = con[i];*/
        int head, tail;
        for(int i = 2; i <= k; i++){
            head = tail = 0;
            dep[tail++] = i - 1;
            for(int j = i; j <= n; j++){
                while(head < tail - 1 && (getup(i, dep[head + 1], dep[head]) <= getdown(dep[head + 1], dep[head]) * rev[j]))
                    head++;
                int k = dep[head];
                dp[i][j] = dp[i - 1][k] + con[j] - con[k] - sum[k] * (rev[j] - rev[k]);
                //dp[j][i] = getdp(i, dep[head], j);dp
                while(head < tail - 1 && (getup(i, dep[tail - 1], dep[tail - 2]) * getdown(j, dep[tail - 2]) >=
                                          getup(i, j, dep[tail - 2]) * getdown(dep[tail - 1], dep[tail - 2])))
                    tail--;
                dep[tail++] = j;
            }
        }
        printf("%.4lf\n", dp[k][n]);
	}
	return 0;
}
