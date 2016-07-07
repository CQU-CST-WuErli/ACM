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
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int num[100], a[100], e[200];
bool dfs(int now) {
    int need = now - 1;
    if(need == 0) return true;
    int pos = now - 2;
    queue<int>p;
    while(1) {
        if(pos <= 0) break;
        if(need == 0) break;
        if(pos > need) pos--;
        else if(num[pos] == 0) pos--;
        else {
            need = need - pos;
            p.push(pos);
            num[pos]--;
        }
    }
    if(need) return false;
    while(p.size()) {
        int u = p.front(); p.pop();
        if(dfs(u)) continue;
        else
            return false;
    }
    return true;
}

bool edfs(int now) {
    e[now]--;
    int need = now - 1;
    if(need == 0) return true;
    int pos = now - 2;
    while(1) {
        if(pos <= 0) break;
        if(e[pos] == 0 || pos > need) pos--;
        else{
            if(edfs(pos)) {
                need = need - pos;
                if(need == 0) break;
            }
            else return false;
        }
    }
    if(need == 0) return true;
    return false;
}

int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	while(t--) {
        int n; scanf("%d", &n);
        memset(num, 0 , sizeof(num));
        memset(e, 0, sizeof(e));
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            num[a[i]]++;
        }
        for(int i = 1; i <= n; i++) e[i] = num[i];
        if(num[n] != 1 || num[1] == 0 || num[2] > 0)
            printf("NO\n");
        else {
            if(dfs(n) || edfs(n))
                printf("YES\n");
            else
                printf("NO\n");
        }
	}

	return 0;
}
