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
//********************Gloden Finger*****************************************************
inline int Read() {
    int ret = 0;
    char c; bool sgn = false;
    c = getchar();
    while(c <= ' ') c = getchar();
    if(c == '-') sgn = true, c = getchar();
    for(ret = 0; c >= '0'; c = getchar())
        ret = ret * 10 + (c - '0');
    if(sgn) ret = - ret;
    return ret;
}
// For negative number//
inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
// For positive number//
//********************Gloden Finger*****************************************************

const int N=1e5;
int pnt[N],nxt[N],head[N],pre[N],cap[N];
int cnt;
int n;
int ID;

void add_edge(int u,int v,int c){
	pnt[cnt]=v;pre[cnt]=u;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=c;
}

map<int,int> mp;
int get_id(int x){
	if (!mp.count(x)) mp[x]=ID++;
	return mp[x];
}

int level[500];
bool bfs(int s,int t){
	OFF(level);
	level[s]=0;
	queue<int> q;
	q.push(s);
	while (!q.empty()){
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (level[v]==-1 && cap[i]){
				level[v]=level[x]+1;
				q.push(v);
			}
		}
	}
	return level[t]!=-1;
}

int iter[500];
int dfs(int u,int t,int Flow){
	if (u==t) return Flow;
	int delta=Flow;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(delta,cap[i]));
			delta-=d;
			iter[u]=i;
			cap[i]-=d;
			cap[i^1]+=d;
			if (!delta) return Flow;
		}
	}
	level[u]=-1;
	return Flow-delta;
} 

int Dinic(int s,int t){
	int Max_flow=0;
	while (bfs(s,t)){
		for (int i=s;i<=t;i++) iter[i]=head[i];
		Max_flow+=dfs(s,t,INF);
	}
	return Max_flow;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		OFF(head);cnt=0;ID=1;mp.clear();
		int s=0;
		for (int i=1;i<=n;i++){
			int A,B,C;
			A=read();B=read();C=read();
			add_edge(s,i,C);
			add_edge(i,s,0);
			while (A--){
				int x;
				x=read();
				add_edge(i,get_id(x)+n,1);
				add_edge(get_id(x)+n,i,0);
			} 
		}
		int t=n+ID;
		int x;x=read();
		add_edge(s,x,INF);add_edge(x,s,0);
		for (int i=n+1;i<t;i++) {
			add_edge(i,t,1);
			add_edge(t,i,0);
		}
		cout << Dinic(s,t) << endl;
	}
	return 0;
}

