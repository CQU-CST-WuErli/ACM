#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pii pair<int, int>
#define pr(x) cout << "#x = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e5 + 111;

map<int, int> col, row;
map<pii, int> fruit;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t, n, m, k, w, q, op, x, y; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase)
    {
        scanf("%d%d%d", &n, &m, &k);
        int r,c;
        r=c=1;
        col.clear();
        row.clear();
        fruit.clear();
        for (int i = 0; i < k; ++i)
        {
            scanf("%d%d%d", &x, &y, &w);
            if (!row.count(x)) {
            	row[x]=r++;
            	x=r-1;
            }
            else x=row[x];
            if (!col.count(y)) {
            	col[y]=c++;
            	y=c-1;
            }
            else y=col[y];
            pii tmp;
            tmp.first=x;tmp.second=y;
            fruit[tmp]=w;
        }
        printf("Case #%d:\n", kase);
        scanf("%d", &q);
        for (int i = 0; i < q; ++i)
        {
            scanf("%d%d%d", &op, &x, &y);
            if (op == 1)
            {
                swap(row[x],row[y]); 
            }
            else if (op == 2)
            {
                swap(col[x],col[y]); 
            }
            else if (op==3) printf("%d\n", fruit[pii(row[x],col[y])]);
        }
    }
    return 0;
}
