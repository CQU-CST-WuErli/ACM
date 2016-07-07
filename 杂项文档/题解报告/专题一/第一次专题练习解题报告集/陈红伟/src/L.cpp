//  Created by Chenhongwei on 2016-05-09 Monday 13:04
//  Copyright (c) 2016 Chenhongwei. All rights reserved.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int inf=1e9;
const int mod=1e9+7;
#define LL long long
const int MAXM = 500010;
char str[MAXM];
int N;
#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x) * 3 + 1 :((x) - tb) * 3 + 2)
const int MAXN = 1500010;
char input[MAXM];
int wa[MAXN],wb[MAXN],ws[MAXN],wv[MAXN],wsd[MAXN],r[MAXN],sa[MAXN];
//int dp[MAXM][25];
int c0(int *r,int a,int b)
{
	return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k,int *r,int a,int b)
{
	if(k == 2) 
		return r[a] < r[b] || (r[a] == r[b] && c12(1,r,a + 1,b + 1));
	else 
		return r[a] < r[b] || (r[a] == r[b] && wv[a + 1]< wv[b + 1]);}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i = 0 ; i < n ; i++) wv[i] = r[a[i]];
    for(i = 0 ; i < m ; i++) wsd[i] = 0;
    for(i = 0 ; i < n ; i++) wsd[wv[i]]++;
    for(i = 1 ; i < m ; i++) wsd[i] += wsd[i - 1];
    for(i = n - 1 ; i >= 0 ; i--) b[--wsd[wv[i]]] = a[i];
}
void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn = r + n ,*san = sa + n,ta = 0,tb = (n + 1) / 3,tbc = 0,p;
    r[n] = r[n + 1] = 0;
    for(i = 0 ; i < n ; i++) 
        if(i % 3 != 0) wa[tbc++] = i;
    sort(r + 2,wa,wb,tbc,m);
    sort(r + 1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p = 1,rn[F(wb[0])] = 0,i = 1 ; i < tbc ; i++)
        rn[F(wb[i])] = c0(r,wb[i - 1],wb[i])?p - 1 : p++;
    if(p < tbc) 
        dc3(rn,san,tbc,p);
    else 
        for(i = 0 ; i < tbc ; i++) san[rn[i]] = i;
    for(i = 0 ;i < tbc ; i++) 
        if(san[i] < tb) 
            wb[ta++] = san[i] * 3;
    if(n % 3 == 1) wb[ta++] = n - 1;
    sort(r,wb,wa,ta,m);
    for(i = 0 ; i < tbc ; i++) wv[wb[i] = G(san[i])] = i;
    for(i = 0,j = 0,p = 0 ; i < ta && j < tbc ; p++)
        sa[p]=c12(wb[j] % 3,r,wa[i],wb[j]) ? wa[i++] : wb[j++];
    for(;i < ta ; p++) sa[p] = wa[i++];
    for(;j < tbc ; p++) sa[p] = wb[j++];
}
int cmp(int *r,int a,int b,int l)
{
    return r[a ]== r[b] && r[a + l] == r[b + l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x = wa,*y = wb,*t;
    for(i = 0 ; i < m ; i++) wsd[i] = 0;
    for(i = 0 ; i < n ; i++) wsd[x[i] = r[i]]++;
    for(i = 1 ; i < m ; i++) wsd[i] += wsd[i - 1];
    for(i = n - 1 ; i >= 0 ; i--) sa[--wsd[x[i]]] = i;
    for(j = 1 , p = 1 ; p < n ; j *= 2,m = p)
    {
        for(p = 0 ,i = n - j ; i < n ; i++) y[p++] = i;
        for(i = 0 ; i < n ; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0 ; i < n ; i++) wv[i] = x[y[i]];
        for(i = 0 ; i < m ; i++) wsd[i] = 0;
        for(i = 0 ; i < n ; i++) wsd[wv[i]]++;
        for(i = 1 ; i < m ; i++) wsd[i] += wsd[i - 1];
        for(i = n - 1 ; i >= 0 ; i--) sa[--wsd[wv[i]]] = y[i];
        for(t = x,x = y,y = t,p = 1,x[sa[0]] = 0,i = 1;i < n ; i++)
            x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1 : p++;
    }
}

int Rank[MAXN],height[MAXN];
void calheight(int *r,int *sa,int n)
{
    int i,j,k = 0;
    for(i = 1 ; i <= n ; i++) Rank[sa[i]] = i;
    for(i = 0 ; i < n ; height[Rank[i++]] = k)
    for(k ? k--:0,j = sa[Rank[i] - 1] ;r[i + k]==r[j + k];k++);
}
int num[MAXN];
int Stack[MAXN],top;
int res[MAXN];
int L[MAXN],R[MAXN];
int main() 
{
    int T;
    scanf("%d",&T);
    while (T--) 
    {
        scanf("%s",str);
        N = strlen(str);
        for (int i = 0 ; i < N ; i++) 
            num[i] = str[i];
        num[N] = 0;
        dc3(num,sa,N + 1,256);
        calheight(num,sa,N);
        top = 0;
        for (int i = 2 ; i <= N ; i++) res[i - 1] = height[i];
        for (int i = 1 ; i <= N - 1; i++) {
            while (top > 0 && res[Stack[top]] >= res[i]) top--;
            if (top == 0) L[i] = 1;
            else L[i] = Stack[top] + 1;
            Stack[++top] = i;
        }
        top = 0;
        for (int i = N - 1 ; i >= 1 ; i--) {
            while (top > 0 && res[Stack[top]] > res[i]) top--;
            if (top == 0) R[i] = N - 1;
            else R[i] = Stack[top] - 1;
            Stack[++top] = i;
        }
        LL ans = 0;
        LL tmp = 0;
        for (LL i = 1 ; i <= N ; i++) 
            tmp += i * (N - 1);
        for (int i = 1 ; i < N ; i++) 
            ans += (LL)(i - L[i] + 1) * (R[i] - i + 1) * res[i];
        cout << tmp - ans * 2LL << endl;
    }
    return 0;
}