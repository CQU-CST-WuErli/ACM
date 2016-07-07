#include <cstring>  
#include <iostream>  
#include <cmath>  
#include <algorithm>  
#include <cstdio>  
#include <queue>
using namespace std;  
#define mod 100000007  
#define maxn 1010  
int dp[maxn][2030][2];  
int main()  
{ 
	int n;
	string s;
	cin >> n;	
	cin >> s;
	deque<char> q;
	int ans=0;
	for (int i=0;s[i];i++) {
		if (q.empty()) {
			q.push_back(s[i]);
		}
		else {
			if (s[i]==q.back()) ans++;
			else q.push_back(s[i]);
		}
	}
	cout << ans << endl;
	return 0;
}  
