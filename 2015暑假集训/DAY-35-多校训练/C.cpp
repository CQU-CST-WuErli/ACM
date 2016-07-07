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

const int maxn=1320;
const int maxm=13530;
int n,m,num,head[maxn];      //head记录每个点的邻接表的表头，不是指针，指向边的下表，-1表示指向表尾
int match[100],step[maxn][4];  //到每个结点四个状态的距离，到每个结点四个状态所用的步数
long long dist[maxn][4];

struct node
{
    int u;             //结点编号
    int k;             //结点状态,实际上是到达该结点的边的状态，这样便于保证得到完整的'LOVE’
    int step;          //到达该结点所用的步骤数
    long long len;     //到达该结点的最短距离
}point1,point2;

struct Edge
{
    int v;            //边的终点
    int k;            //边的状态
    int w;            //边的权值
    int next;         //下一条边的编号
}edge[4*maxm];

void addEdge(int s,int t,int w,int k)    //邻接表的方式存储图
{
    edge[num].v=t;
    edge[num].w=w;
    edge[num].k=k;
    edge[num].next=head[s];
    head[s]=num++;
}

void SPFA()
{
    int i,j,k,v;
    queue<node> q;
    point1.step=0;
    point1.len=0;
    point1.u=1;
    point1.k=3;   //开始走的边的状态必须是'L'，所以第一个入队的结点是处于3状态的1号结点
    q.push(point1);
    while(!q.empty())
    {
        point2=q.front();
        q.pop();
        for(i=head[point2.u];i!=-1;i=edge[i].next)   //从队首开始访问邻接表的每一个元素
        {
            k=(point2.k+1)%4;     //保证形成完整的'LOVE'
            v=edge[i].v;
            if(k==edge[i].k)      //保证走的路径是实际存在的
            {
                if(dist[v][k]>point2.len+edge[i].w || dist[v][k]==point2.len+edge[i].w && step[v][k]<point2.step+1)
                {
                    dist[v][k]=point2.len+edge[i].w;
                    step[v][k]=point2.step+1;
                    point1.u=v;
                    point1.k=k;
                    point1.len=dist[v][k];
                    point1.step=step[v][k];
                    q.push(point1);
                }
            }
        }
    }    //如果dist[n][3]大小没有变，说明没有走到第n个结点的第三个状态
    if(dist[n][3]==dist[n+1][0])   //走到第n个结点时是该结点的状态（实际上就是到达该点的边的状态）必须是'E'
    printf("Binbin you disappoint Sangsang again, damn it!\n");
    else
    printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",dist[n][3],step[n][3]/4);
}

int main()
{
    int i,j,t,u,v,l,cas;
    char str[3];
    match['L']=0;
    match['O']=1;
    match['V']=2;
    match['E']=3;
    scanf("%d",&t);
    cas=1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        num=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%s",&u,&v,&l,str);
            addEdge(u,v,l,match[str[0]]);
            addEdge(v,u,l,match[str[0]]);
        }
        printf("Case %d: ",cas++);
        memset(dist,0x3f,sizeof(dist));
        memset(step,0,sizeof(step));
        SPFA();
    }
    return 0;
}
