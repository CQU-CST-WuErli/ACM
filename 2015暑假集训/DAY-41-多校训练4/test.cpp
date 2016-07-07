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
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	freopen("C:\\Users\\john\\Desktop\\in.txt","w",stdout);
#endif
	for (int i=1;i<=500;i++) cout << i << endl;
	for (int i=2;i*i<=54631;i++) if (54631%i==0) cout << "ss" << endl;
//    int t, n, m, k, c, q, op, x, y; scanf("%d", &t);
//    for (int kase = 1; kase <= t; ++kase)
//    {
//        scanf("%d%d%d", &n, &m, &k);
//        col.clear();
//        row.clear();
//        fruit.clear();
//        for (int i = 0; i < k; ++i)
//        {
//            scanf("%d%d%d", &x, &y, &c);
//            col[y] = y;
//            row[x] = x;
//            fruit[pii(x,y)] = c;
//        }
//        printf("Case #%d:\n", kase);
//        scanf("%d", &q);
//        for (int i = 0; i < q; ++i)
//        {
//            scanf("%d%d%d", &op, &x, &y);
//            if (op == 1)
//            {
////                if (row[x] == 0)
////                {
////                    row[x] = y;
////                    row[y] = x;
////                    continue;
////                }
//                int tem = row[x];
//                row[x] = row[y];
//                row[y] = tem;
//            }
//            else if (op == 2)
//            {
////                if (col[x] == 0)
////                {
////                    col[x] = y;
////                    col[y] = x;
////                    continue;
////                }
//                int tem = col[x];
//                col[x] = col[y];
//                col[y] = tem;
//            }
//            else printf("%d\n", fruit[pii(row[x],col[y])]);
//        }
//    }
    return 0;
}
