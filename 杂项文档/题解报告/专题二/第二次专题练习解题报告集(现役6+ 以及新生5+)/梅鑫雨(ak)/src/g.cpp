/*  ^^ ====== ^^ 
ID: meixiuxiu
PROG: test
LANG: C++11
*/
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
typedef unsigned long long ull;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
#define pi acos(-1.0)
#define maxn 40000
#define maxv 100005
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define LOCAL
const int MAXN = 24;
int N, A[MAXN], use[MAXN], c;
bool dfs(int p, int s, int k){
  if(p == N) return c == N - 1;
  if(k == 0) return dfs(p + 1, p, A[p + 1] - 1);
  for(int i = s; i >= 0; i--){
    if(use[i] || A[i] > k || A[i] == A[p] - 1) continue;
    use[i] = 1;
    c++;
    if(dfs(p, i - 1, k - A[i])) return 1;
    use[i] = 0;
    c--;
  }
  return 0;
}
int main(){
  
  freopen("input.txt","r",stdin);
  //freopen("out.txt","r",stdout);
  int t;cin >> t;
  while(t--){
      scanf("%d",&N);
      for(int i = 0; i < N; i++) scanf("%d",&A[i]);
      sort(A, A + N);
      MEM(use,0);
      c = 0;
      bool res = dfs(0, -1, A[0] - 1);
      cout << (res ? "YES\n" : "NO\n");
  }
  
}