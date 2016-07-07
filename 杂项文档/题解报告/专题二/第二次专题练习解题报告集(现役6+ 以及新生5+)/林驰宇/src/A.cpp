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
const int matrix_size = 3, mod = 1e9 + 7;
struct matrix {
    int mat[matrix_size + 5][matrix_size + 5];
    matrix() {
        memset(mat, 0, sizeof(mat));
    }
};
matrix operator * (matrix a, matrix b) {
    matrix ans;
    int j, k, i;
    for(j = 1; j <= matrix_size; j++) {
        for(k = 1; k <= matrix_size; k++) {
            for(i = 1; i <= matrix_size; i++) {
                ans.mat[j][k] = (ans.mat[j][k] + 1LL * a.mat[j][i] * b.mat[i][k]) % mod;
            }
        }
    }
    return ans;
}
matrix operator + (matrix a, matrix b) {
    matrix ans;
    int j, k;
    for(j = 1; j <= matrix_size; j++) {
        for(k = 1; k <= matrix_size; k++) {
            //printf("%d %d\n",j,k);
            ans.mat[j][k] = (a.mat[j][k] + b.mat[j][k]) % mod;
        }
    }
    return ans;
}
matrix operator ^ (matrix a, LL b) {
    matrix res;
    for(int j = 1; j <= matrix_size; j++) res.mat[j][j] = 1;
    while(b) {
        //printf("%lld\n",b);
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

LL A[505];

matrix X, Y;
void build(matrix &X) {
    X.mat[1][1] = 1; X.mat[1][2] = 1; X.mat[1][3] = 1;
    X.mat[2][1] = 1; X.mat[2][2] = 0; X.mat[2][3] = 0;
    X.mat[3][1] = 0; X.mat[3][2] = 1; X.mat[3][3] = 0;
}
void build(matrix &Y, int a, int b, int c) {
    Y.mat[1][1] = a;
    Y.mat[2][1] = b;
    Y.mat[3][1] = c;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        LL n;
        int m;
        scanf("%lld%d", &n, &m);
        int oka = 1, okb = 2, okc = 3;
        int okd = 1;
        for(int j = 1; j <= m; j++) {
            scanf("%lld", &A[j]);
            if(A[j] == 1) oka = 0;
            if(A[j] == 2) okb = 0;
            if(A[j] == 3) okc = 0;
            if(A[j] == n) okd = 0;
        }
        A[m + 1] = n;
        sort(A + 1, A + m + 2);
        LL now = 4;
        LL a = oka ? 1 : 0, b = okb ? a + 1 : 0, c = okc ? 1 + a + b : 0;
        matrix res;
        int ans = 0;
        for(int j = 1; j <= m + 1; j++) {
            if(A[j] > n) break;
            if(A[j] < now) continue;
            if(A[j] == now) {
                if(A[j] == n) ans = (a + b + c) % mod;
                LL a1 = b, b1 = c, c1 = 0;
                a = a1; b = b1; c = c1;
                now = A[j] + 1;
            } else {
                build(X);
                build(Y, c, b, a);
                LL t = A[j] - now;
                res = (X ^ t) * Y;
                c = res.mat[1][1]; b = res.mat[2][1]; a = res.mat[3][1];
                if(A[j] == n) ans = (a + b + c) % mod;
                LL a1 = b, b1 = c, c1 = 0;
                a = a1; b = b1; c = c1;
                now = A[j] + 1;
            }
        }
        if(n == 1) ans = a;
        if(n == 2) ans = b;
        if(n == 3) ans = c;
        if(!okd) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
