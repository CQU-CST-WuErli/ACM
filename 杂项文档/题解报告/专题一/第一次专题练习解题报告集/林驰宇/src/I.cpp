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
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int M = 3e5 + 5;
int MinimumRepresentation(int *s, int l) {
    int i = 0, j = 1, k = 0, t;
    while(i < l && j < l && k < l) {
        t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
        if(!t) k++;
        else {
            if(t > 0) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) ++ j;
            k = 0;
        }
    }
    return (i < j ? i : j);
}
int A[M];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n ;
        scanf("%d", &n);
        for(int j = 0; j < n; j++) scanf("%d", &A[j]);
        int m = MinimumRepresentation(A, n);
        for(int j = 0; j < n; j++) printf("%d%c", A[(m + j) % n], " \n"[j == n - 1]);
    }
    return 0;
}
