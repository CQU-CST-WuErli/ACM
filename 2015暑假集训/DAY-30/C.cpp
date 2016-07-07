//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

//********************BigInteger Model*******************************************
class bign{
public:
    int len, s[MAX_L];//数的长度，记录数组
//构造函数
    bign();
    bign(const char*);
    bign(int);
    bool sign;//符号 1正数 0负数
    string toStr() const;//转化为字符串，主要是便于输出
    friend istream& operator>>(istream &,bign &);//重载输入流
    friend ostream& operator<<(ostream &,bign &);//重载输出流
//重载复制
    bign operator=(const char*);
    bign operator=(int);
    bign operator=(const string);
//重载各种比较
    bool operator>(const bign &) const;
    bool operator>=(const bign &) const;
    bool operator<(const bign &) const;
    bool operator<=(const bign &) const;
    bool operator==(const bign &) const;
    bool operator!=(const bign &) const;
//重载四则运算
    bign operator+(const bign &) const;
    bign operator++();
    bign operator++(int);
    bign operator+=(const bign&);
    bign operator-(const bign &) const;
    bign operator--();
    bign operator--(int);
    bign operator-=(const bign&);
    bign operator*(const bign &)const;
    bign operator*(const int num)const;
    bign operator*=(const bign&);
    bign operator/(const bign&)const;
    bign operator/=(const bign&);
//四则运算的衍生运算
    bign operator%(const bign&)const;//取模（余数）
    bign factorial()const;//阶乘
    bign Sqrt()const;//整数开根（向下取整）
    bign pow(const bign&)const;//次方
//一些乱乱的函数
    void clean();
    ~bign();
};

bign::bign(){
    memset(s, 0, sizeof(s));
    len = 1;
    sign = 1;
}

bign::bign(const char *num){
    *this = num;
}

bign::bign(int num){
    *this = num;
}

string bign::toStr() const{
    string res;
    res = "";
    for (int i = 0; i < len; i++)
        res = (char)(s[i] + '0') + res;
    if (res == "")
        res = "0";
    if (!sign&&res != "0")
        res = "-" + res;
    return res;
}

istream &operator>>(istream &in, bign &num){
    string str;
    in>>str;
    num=str;
    return in;
}

ostream &operator<<(ostream &out, bign &num){
    out<<num.toStr();
    return out;
}

bign bign::operator=(const char *num){
    memset(s, 0, sizeof(s));
    char a[MAX_L] = "";
    if (num[0] != '-')
        strcpy(a, num);
    else
        for (int i = 1; i < strlen(num); i++)
            a[i - 1] = num[i];
    sign = !(num[0] == '-');
    len = strlen(a);
    for (int i = 0; i < strlen(a); i++)
        s[i] = a[len - i - 1] - 48;
    return *this;
}

bign bign::operator=(int num){
    if (num < 0)
        sign = 0, num = -num;
    else
        sign = 1;
    char temp[MAX_L];
    sprintf(temp, "%d", num);
    *this = temp;
    return *this;
}

bign bign::operator=(const string num){
    const char *tmp;
    tmp = num.c_str();
    *this = tmp;
    return *this;
}

bool bign::operator<(const bign &num) const{
    if (sign^num.sign)
        return num.sign;
    if (len != num.len)
        return len < num.len;
    for (int i = len - 1; i >= 0; i--)
        if (s[i] != num.s[i])
            return sign ? (s[i] < num.s[i]) : (!(s[i] < num.s[i]));
    return !sign;
}

bool bign::operator>(const bign&num)const{
    return num < *this;
}

bool bign::operator<=(const bign&num)const{
    return !(*this>num);
}

bool bign::operator>=(const bign&num)const{
    return !(*this<num);
}

bool bign::operator!=(const bign&num)const{
    return *this > num || *this < num;
}

bool bign::operator==(const bign&num)const{
    return !(num != *this);
}

bign bign::operator+(const bign &num) const{
    if (sign^num.sign){
        bign tmp = sign ? num : *this;
        tmp.sign = 1;
        return sign ? *this - tmp : num - tmp;
    }
    bign result;
    result.len = 0;
    int temp = 0;
    for (int i = 0; temp || i < (max(len, num.len)); i++){
        int t = s[i] + num.s[i] + temp;
        result.s[result.len++] = t % 10;
        temp = t / 10;
    }
    result.sign = sign;
    return result;
}

bign bign::operator++(){
    *this = *this + 1;
    return *this;
}

bign bign::operator++(int){
    bign old = *this;
    ++(*this);
    return old;
}

bign bign::operator+=(const bign &num){
    *this = *this + num;
    return *this;
}

bign bign::operator-(const bign &num) const{
    bign b=num,a=*this;
    if (!num.sign && !sign){
        b.sign=1;
        a.sign=1;
        return b-a;
    }
    if (!b.sign){
        b.sign=1;
        return a+b;
    }
    if (!a.sign){
        a.sign=1;
        b=bign(0)-(a+b);
        return b;
    }
    if (a<b){
        bign c=(b-a);
        c.sign=false;
        return c;
    }
    bign result;
    result.len = 0;
    for (int i = 0, g = 0; i < a.len; i++){
        int x = a.s[i] - g;
        if (i < b.len) x -= b.s[i];
        if (x >= 0) g = 0;
        else{
            g = 1;
            x += 10;
        }
        result.s[result.len++] = x;
    }
    result.clean();
    return result;
}

bign bign::operator * (const bign &num)const{
    bign result;
    result.len = len + num.len;

    for (int i = 0; i < len; i++)
        for (int j = 0; j < num.len; j++)
            result.s[i + j] += s[i] * num.s[j];

    for (int i = 0; i < result.len; i++){
        result.s[i + 1] += result.s[i] / 10;
        result.s[i] %= 10;
    }
    result.clean();
    result.sign = !(sign^num.sign);
    return result;
}

bign bign::operator*(const int num)const{
    bign x = num;
    bign z = *this;
    return x*z;
}
bign bign::operator*=(const bign&num){
    *this = *this * num;
    return *this;
}

bign bign::operator /(const bign&num)const{
    bign ans;
    ans.len = len - num.len + 1;
    if (ans.len < 0){
        ans.len = 1;
        return ans;
    }

    bign divisor = *this, divid = num;
    divisor.sign = divid.sign = 1;
    int k = ans.len - 1;
    int j = len - 1;
    while (k >= 0){
        while (divisor.s[j] == 0) j--;
        if (k > j) k = j;
        char z[MAX_L];
        memset(z, 0, sizeof(z));
        for (int i = j; i >= k; i--)
            z[j - i] = divisor.s[i] + '0';
        bign dividend = z;
        if (dividend < divid) { k--; continue; }
        int key = 0;
        while (divid*key <= dividend) key++;
        key--;
        ans.s[k] = key;
        bign temp = divid*key;
        for (int i = 0; i < k; i++)
            temp = temp * 10;
        divisor = divisor - temp;
        k--;
    }
    ans.clean();
    ans.sign = !(sign^num.sign);
    return ans;
}

bign bign::operator/=(const bign&num){
    *this = *this / num;
    return *this;
}

bign bign::operator%(const bign& num)const{
    bign a = *this, b = num;
    a.sign = b.sign = 1;
    bign result, temp = a / b*b;
    result = a - temp;
    result.sign = sign;
    return result;
}

bign bign::pow(const bign& num)const{
    bign result = 1;
    for (bign i = 0; i < num; i++)
        result = result*(*this);
    return result;
}

bign bign::factorial()const{
    bign result = 1;
    for (bign i = 1; i <= *this; i++)
        result *= i;
    return result;
}

void bign::clean(){
    if (len == 0) len++;
    while (len > 1 && s[len - 1] == '\0')
        len--;
}

bign bign::Sqrt()const{
    if(*this<0)return -1;
    if(*this<=1)return *this;
    bign l=0,r=*this,mid;
    while(r-l>1){
        mid=(l+r)/2;
        if(mid*mid>*this)
            r=mid;
        else
            l=mid;
    }
    return l;
}

bign::~bign(){}
//********************End of BigInteger Model*******************************************

const int N=5e5+10;
int pnt[N],pre[N],nxt[N],head[N],cap[N],cost[N];
int cnt;
int n,m; 
int g[60][60];

void add_edge(int u,int v,int c,int w){
	pnt[cnt]=v;pre[cnt]=u;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt]=c;cost[cnt++]=w;
}

int a[N],vis[N],p[N];
ll d[N];
bool spfa(int s,int t,int &Flow,ll &Cost){
	CLR(a);CLR(vis);
	for (int i=s;i<=t;i++) d[i]=INF;
	queue<int> q;
	q.push(s);
	a[s]=INF;
	vis[s]=1;
	d[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (d[v]>d[x]+cost[i] && cap[i]){
				d[v]=d[x]+cost[i];
				a[v]=min(a[x],cap[i]);
				p[v]=i;
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	} 
	if (d[t]==INF) return false;
	Flow+=a[t];
	Cost+=d[t]*a[t];
	for (int u=t;u!=s;u=pre[p[u]]){
		cap[p[u]]-=a[t];
		cap[p[u]^1]+=a[t];
	}
	return true;
}

ll Min_cost_flow(int s,int t){
	int Flow=0;ll Cost=0;
	while (spfa(s,t,Flow,Cost));
	return Cost;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T;
	SI(T);
	while (T--){
		SII(n,m);
		OFF(head);cnt=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%d",&g[i][j]);
		int s=0,t=m*n+n+1;
		// 1->n  order   n=1->n+m   fac 
		for (int i=1;i<=n;i++) {
			add_edge(s,i,1,0);
			add_edge(i,s,0,0);
		}
		for (int j=1;j<=m;j++){
			for (int k=1;k<=n;k++){
				add_edge(n+(j-1)*n+k,t,1,0);
				add_edge(t,n+(j-1)*n+k,0,0);
				for (int i=1;i<=n;i++){
					add_edge(i,n+(j-1)*n+k,1,(k)*g[i][j]);
					add_edge(n+(j-1)*n+k,i,0,-(k)*g[i][j]);
				}
			}
		}
		printf("%.6f\n",Min_cost_flow(s,t)*1.0/(double)n);
	}
	return 0;
}

