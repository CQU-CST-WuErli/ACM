#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;

char s[MAXN];
double ans[9] = {
0.0,
0.0234375,
0.04632568359375,
0.06867742538452148,
0.09050529822707176,
0.11182158029987477,
0.13263826201159645,
0.15296705274569966,
0.17281938744697234
};

int getans(char *a) {
    switch(a[0]) {
        case 'B': return 0;
        case 'K': return 1;
        case 'M': return 2;
        case 'G': return 3;
        case 'T': return 4;
        case 'P': return 5;
        case 'E': return 6;
        case 'Z': return 7;
        case 'Y': return 8;
        default: return -1;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    int kase = 0;
    while (t --) {
        scanf("%s", s);
        int len = strlen(s);
        char x[3];
        x[0] = x[1] = x[2] = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '[') {
                x[0] = s[i + 1];
                break;
            }
        }
        double fans = ans[getans(x)];
        fans *= 100;
        //if (s[0] == '0') fans = 0;
        printf("Case #%d: %.2f\%\n", ++kase, fans);
    }
    return 0;
}
