// SOJ 01的时间.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
int T; ll n;
void biteAdd(ll& a){
	ll t = a;
	ll tn = 1;
	ll i = 1;
	while (tn){
		if (t%10 == 1){
			a -= i * 1;
			tn = 1;
		}
		else{
			a += i * 1;
			tn = 0;
		}
		i *= 10;
		t /= 10;
	}
}
ll find(ll a){
	ll t = 1;
	while (t < a || t%a){
		biteAdd(t);
	}
	return t;
}
int main()
{
	cin >> T;
	while (T--){
		cin >> n;
		cout << find(n) << endl;
	}
	return 0;
}

