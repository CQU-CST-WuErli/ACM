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

int ans, rans;
int num[20], nownum[20], a[20][20], now[20], sum[20], maintemp[6];
int id[6] = {100, 50, 20, 10, 5, 1};
P p[20];
bool leap[4][7][16][31][91][91];

struct Node {
    int a[6], ans;
};
vector<Node>vt[3];

/*
int edfs(int temp[], int tot) {
    int& ans = edp[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]];
    if(ans != -1) return ans;
    if(tot == now[1]) {
        ans = 0;
        for(int i = 0; i < 6; i++) ans = ans +
    }
    ans = inf;
    int e[6];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) e[j] = temp[j];
        if(temp[i] >= a[1][i] && temp[i] < num[i]) {
            e[i]++;
            ans = min(ans, dfs(e, tot + id[i]) + 1);
        }
    }
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) e[j] = temp[j];
        if(temp[i] <= a[1][i] && temp[i]) {
            e[i]--;
            ans = min(ans, dfs(e, tot - id[i]) + 1);
        }
    }
    return ans;
}
*/


void dfs(int temp[], int tot, int idx) {
    if(tot > now[idx]) return ;
//    for(int i = 0; i < 6; i++) cout<<temp[i]<<" ";
//    cout<<endl;
    bool& ans = leap[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]];
    if(ans) return ;
    ans = true;
    if(tot == now[idx]) {
        Node nxt; nxt.ans = 0;
        for(int i = 0; i < 6; i++) {
            nxt.a[i] = temp[i];
            nxt.ans += abs(temp[i] - a[idx][i]);
        }
        vt[idx].push_back(nxt);
        return ;
    }
    int e[6];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) e[j] = temp[j];
        if(temp[i] < num[i]) {
            e[i]++;
            dfs(e, tot + id[i], idx);
        }
    }
}

bool check(int x, int y) {
    for(int i = 0; i < 6; i++) {
        if(vt[p[0].second][x].a[i] + vt[p[1].second][y].a[i] > num[i]) return false;
    }
    return true;
}

void prln(int x, int y) {
    for(int i = 0; i < 6; i++) cout << vt[0][x].a[i] << " "; cout << vt[0][x].ans << endl;
    for(int i = 0; i < 6; i++) cout << vt[1][y].a[i] << " "; cout << vt[1][y].ans << endl;
    cout << endl;
}

void work() {
    for(int i = 0; i < vt[p[0].second].size(); i++) {
        for(int j = 0; j < vt[p[1].second].size(); j++) {
            if(!check(i, j)) continue;
            int temp = vt[p[0].second][i].ans + vt[p[1].second][j].ans;
            for(int k = 0; k < 6; k++)
                temp = temp + abs(num[k] - vt[p[0].second][i].a[k] - vt[p[1].second][j].a[k] - a[p[2].second][k]);
            ans = min(ans, temp);
        }
    }
}

int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	while(t--) {
        for(int i = 0; i < 3; i++) vt[i].clear();
        int x1, x2, x3; scanf("%d%d%d", &x1, &x2, &x3);
        for(int i = 0; i < 3; i++) {
            sum[i] = 0;
            for(int j = 0; j < 6; j++) {
                scanf("%d", &a[i][j]);
                sum[i] = sum[i] + id[j] * a[i][j];
            }
        }
        now[0] = sum[0] - x1 + x3;
        now[1] = sum[1] - x2 + x1;
        now[2] = sum[2] - x3 + x2;
        if(now[0] < 0 || now[1] < 0 || now[2] < 0) {
            printf("impossible\n"); continue;
        }
        memset(num, 0, sizeof(num));
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 3; j++) num[i] = num[i] + a[j][i];
        }
        for(int i = 0; i < 3; i++) p[i] = P(now[i], i);
        sort(p, p + 3);
        //cout<<p[0].second<<" "<<p[1].second<<" "<<p[2].second<<endl;
        memset(leap, false, sizeof(leap));
        memset(maintemp, 0, sizeof(maintemp));
        dfs(maintemp, 0, p[0].second);

        memset(leap, false, sizeof(leap));
        memset(maintemp, 0, sizeof(maintemp));
        dfs(maintemp, 0, p[1].second);

/*
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < vt[i].size(); j++) {
                for(int k = 0; k < 6; k++)
                    cout<<vt[i][j].a[k]<< " ";
                cout<<endl;
            }
            cout<<endl;
        }
*/

        ans = inf;

        work();

        if(ans == inf)
            printf("impossible\n");
        else
            printf("%d\n", ans / 2);
	}
	return 0;
}
