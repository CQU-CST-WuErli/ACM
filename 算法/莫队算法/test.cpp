//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


class CFraction
{
public:
    CFraction(int a=1,int b=1);
    virtual ~CFraction(){};
    float GetValue()const;//获取分数值
    void Simplification();//化简
    void Show();//显示分数
    friend ostream& operator<<(ostream& os,CFraction& f);
    //重载四则运算操作符
    CFraction operator +(const CFraction& f)const;
    CFraction operator -(const CFraction& f)const;
    CFraction operator *(const CFraction& f)const;
    CFraction operator /(CFraction& f)const;
    //重载比较操作符
    bool operator ==(const CFraction& f)const;
    bool operator >(const CFraction& f)const;
    bool operator <(const CFraction& f)const;
    CFraction GetReciprocal();//获取分数的倒数
    void ChangeValue(int a,int b);//改变当前分数分子和分母
private:
    int m_molecular;//分子
    int m_denomilator;//分母
    bool m_IsNegative;//是否为负数
};

int Function(int& a,int& b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
ostream& operator<<(ostream& os,CFraction& f)
{
    f.Simplification();
    if(f.m_IsNegative)//负数
        os<<"  -"<<f.m_molecular<<"/"<<f.m_denomilator<<endl;
    else//正数
        os<<"   "<<f.m_molecular<<"/"<<f.m_denomilator<<endl;
    return os;
}
CFraction::CFraction(int a, int b):m_IsNegative(false)
{//默认分数为正1
    while(b==0)
    {
        cout<<"分母不能为0，请重新输入分母:"<<endl;
        cin>>b;
    }
    this->m_molecular=abs(a);
    this->m_denomilator=abs(b);
    if(a<0&&b<0)
        this->m_IsNegative=false;
    else if(a<0||b<0)
        this->m_IsNegative=true;
    else
        this->m_IsNegative=false;
    this->Simplification();
}
float CFraction::GetValue()const
{
    return this->m_molecular/(float)m_denomilator;
}
void CFraction::Simplification()
{
    int a=m_molecular,b=m_denomilator;
    int ret=Function(a,b);
    m_molecular/=ret;
    m_denomilator/=ret;
}
CFraction CFraction::operator +(const CFraction &f)const
{
    CFraction temp;
    if(m_IsNegative==f.m_IsNegative)//同号相加
    {
        temp.m_molecular=m_molecular*f.m_denomilator+m_denomilator*f.m_molecular;
        temp.m_denomilator=m_denomilator*f.m_denomilator;
        temp.m_IsNegative=m_IsNegative;
    }
    else// 不同号
    {
        temp.m_molecular=abs(m_molecular*f.m_denomilator-m_denomilator*f.m_molecular);
        temp.m_denomilator=abs(m_denomilator*f.m_denomilator);
        if(this->GetValue()>f.GetValue())
            temp.m_IsNegative=m_IsNegative;
        else
            temp.m_IsNegative=f.m_IsNegative;
    }
    return temp;
}
void CFraction::Show()
{
    cout<<*this;
}
CFraction CFraction::operator -(const CFraction &f) const
{
    CFraction temp;
    if(m_IsNegative==f.m_IsNegative)//同号相减
    {
        temp.m_molecular=abs(m_molecular*f.m_denomilator-m_denomilator*f.m_molecular);
        temp.m_denomilator=m_denomilator*f.m_denomilator;
        if(GetValue()>=f.GetValue())
            temp.m_IsNegative=false;
        else
            temp.m_IsNegative=true;
    }
    else//异号相减
    {
        temp.m_molecular=m_molecular*f.m_denomilator+m_denomilator*f.m_molecular;
        temp.m_denomilator=m_denomilator*f.m_denomilator;
        temp.m_IsNegative=m_IsNegative;
    }
    return temp;
}
CFraction CFraction::operator *(const CFraction &f) const
{
    CFraction temp;
    temp.m_molecular=m_molecular*f.m_molecular;
    temp.m_denomilator=m_denomilator*f.m_denomilator;
    //接下来确定符号
    if(m_IsNegative==f.m_IsNegative)//同号相乘符号为正
        temp.m_IsNegative=false;
    else
        temp.m_IsNegative=true;
    return temp;

}
CFraction CFraction::operator /(CFraction &f) const
{
    CFraction temp,r;
    r=f.GetReciprocal();
    temp=*this*r;
    return temp;
}
CFraction CFraction::GetReciprocal()
{
    CFraction temp;
    temp.m_denomilator=m_molecular;
    temp.m_molecular=m_denomilator;
    temp.m_IsNegative=m_IsNegative;
    return temp;
}
bool CFraction::operator ==(const CFraction &f) const
{
    if(m_IsNegative!=f.m_IsNegative)//不同号肯定不相等
        return false;
    if(GetValue()==f.GetValue())
        return true;
    else
        return false;
}
bool CFraction::operator <(const CFraction &f) const
{
    if(m_IsNegative==f.m_IsNegative)//同号比较大小
    {
        if(GetValue()<f.GetValue())
        {
            if(m_IsNegative)
                return false;
            else
                return true;
        }
        else if(GetValue()>f.GetValue())
        {
            if(m_IsNegative)
                return true;
            else
                return false;
        }
        else//相等的分数
            return false;
    }
    else if(m_IsNegative)//左负友正
        return true;
    else// 左正右负
        return false;
}
bool CFraction::operator >(const CFraction& f)const//大于号小于号刚好相反
{
    return (f<*this);
}
void CFraction::ChangeValue(int a,int b)
{
    *this=CFraction(a,b);
}



int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    CFraction tt;
    tt.ChangeValue(2,3);
    cout << tt << endl;
    return 0;
}
