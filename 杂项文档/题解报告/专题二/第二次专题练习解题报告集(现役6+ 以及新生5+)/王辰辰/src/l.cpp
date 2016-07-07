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
const int maxn = 60100;
int a[maxn];
int Gcd(int a, int b) {
    return b == 0 ? a : Gcd(b, a%b);
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
        bool ok = false;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if(a[i] == 0) ok = true;
        }
        int maxx = a[1];
        for(int i = 2; i <= n; i++) maxx = max(maxx, a[i]);
        int gcd = Gcd(a[1], a[2]);
        for(int i = 3; i <= n; i++) gcd = Gcd(gcd, a[i]);
        int num = maxx / gcd;
        if(ok) num++;
        double ans = 0;
        for(int i = 1; i <= num; i++) ans = ans + 1.0 / i;
        //cout<<ans<<endl;
        ans = ans * num;
        //cout<<ans<<endl;
        ans = ans + num - n;
        int rans = ans;
        printf("%d\n", rans);
	}
	return 0;
}
