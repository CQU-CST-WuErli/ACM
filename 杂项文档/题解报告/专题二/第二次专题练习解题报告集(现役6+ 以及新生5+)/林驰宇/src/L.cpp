#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#include<iomanip>
#define LL long long
#define double long double
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("L.txt","w",stdout);
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int x = 0, y = 0;
        int zero = 0;
        for(int j = 1; j <= n; j++) {
            int a;
            scanf("%d", &a);
            if(a == 0) zero ++;
            x = max(a, x);
            y = __gcd(a, y);
        }
        double ans = x / y - n + zero;
        n = x / y + zero;
        for(int j = 0; j < n; j++) ans += 1.0 * n / (n - j);
        printf("%d\n",(int)ans);
    }
    return 0;
}
