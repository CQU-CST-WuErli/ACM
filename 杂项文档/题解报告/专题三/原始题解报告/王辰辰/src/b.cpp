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

int a[20];
int dir[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};
struct Node {
    int a[4][4];
    bool operator == (const Node& r) const {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(a[i][j] != r.a[i][j]) return false;
        return true;
    }
};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL

    for(int i = 1; i <= 9; i++) a[i] = i;
    vector<Node> ans;
    do {
        Node temp;
        for(int i = 1; i <= 9; i++) {
            int x = (a[i] - 1) / 3;
            int y = a[i] - x * 3 - 1;
            for(int j = 0; j < 4; j++) {
                int tempx = x + dir[j][0];
                int tempy = y + dir[j][1];
                temp.a[tempx][tempy] = a[i];
            //cout<<tempx<<" "<<tempy<<endl;
            }
        }
        ans.push_back(temp);
    }while(next_permutation(a + 1, a + 10));
    int t; scanf("%d", &t);
    while(t--) {
        Node temp;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                scanf("%d", &temp.a[i][j]);
        bool ok = false;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == temp) {
                ok = true; break;
            }
        }
        if(ok)
            printf("Lucky dog!\n");
        else
            printf("BOOM!\n");
    }
    return 0;
}
