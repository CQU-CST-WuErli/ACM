#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 12500000;
struct e{
        int next;
        int from;
        int to;
}e[maxn];
int head[5050];
int map[5050];
int d[5050];
int in[5050];//点的入度
int out[5050];//点的出度
int cnt = 0;
void add(int v1, int v2){
        e[cnt].from = v1;
        e[cnt].to = v2;
        e[cnt].next = head[v1];
        head[v1] = cnt++;

}
int find (int x){
        return map[x] == x ? x : find(map[x]);
}

void init(int n){
        for(int i = 0; i <= n; i++) map[i] = i;
}
/*void solve(int u){
        for(int i = head[u]; ~i; i = e[i].next){
                in[i]++;
                out[u]++;
        }
}*/
int main()
{
        int t; scanf("%d", &t);
        while(t--){
                memset(head, -1, sizeof head);
                memset(d, 0, sizeof d);
                memset(out, 0, sizeof out);
                memset(in, 0, sizeof in);
                int n, m;
                scanf("%d%d", &n, &m);
                cnt = 0;
                int v1, v2;
                int flag1 = 0, flag2 = 0, flag3 = 0;
                init(n);
                for(int i = 0; i < m; i++){
                        scanf("%d%d", &v1, &v2);
                        add(v1, v2);
                        map[find(v1)] = map[find(v2)];
                }
                int flag = 0;
                for(int i = 1; i <= n; i++){
                        if(map[i] == i)
                                flag++;
                }
                //printf("%d\n", flag);
                if(flag == 1){
                        if(n == 1){
                                printf("Yes Yes\n");
                        }
                        else{
                                for(int i = 0; i < m; i++){
                                        d[e[i].from]++;
                                        d[e[i].to]++;
                                        in[e[i].to]++;
                                        out[e[i].from]++;
                                }
                                for(int i = 1; i <= n; i++){
                                        //printf("*%d\n", d[i]);
                                        if(d[i]%2) flag1++;
                                }
                                //printf("%d\n", flag1);
                                if(flag1 == 0 || flag1 == 2) printf("Yes ");
                                else printf("No ");
                                /*for(int i = 1; i <= n; i++) {
                                        solve(i);
                                }*/
                                for(int i = 1; i <= n; i++){
                                        if(in[i] == out[i]) flag2++;
                                        else if(in[i] - out[i] == 1 || out[i] - in[i] == 1) flag3++;
                                }
                                //printf("%d %d\n", flag2, flag3);
                                if((flag2 == n && flag3 == 0) || (flag2 == n-2 && flag3 == 2)) printf("Yes\n");
                                else printf("No\n");
                        }
                }
                else printf("No No\n");
        }
        return 0;
}
