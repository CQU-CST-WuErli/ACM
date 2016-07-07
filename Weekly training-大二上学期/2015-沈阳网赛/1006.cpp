/********************************************
Author         :Crystal
Created Time   :
File Name      :
********************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;cin >> t;
	int kase = 1;
	getchar();
	while(t--){
		int flag = 1;
		string s;getline(cin ,s);
//		cout << s << endl;
		if (s.size()==0) {
			printf("Case #%d: 0\n",kase++);
			continue;
		}
		for (int i=0;i<s.size();i++) {
			if (s[i]!='c' && s[i]!='f') {
				flag=0;
				break;
			}
		}
		if (!flag) {
			printf("Case #%d: -1\n",kase++);
			continue;
		}
		int ls=s.size();
//		cout << s << endl;
		int pos=-1;
		int ans=0;
		for (int i=0;i<ls;i++) {
			if (s[i]=='c') {
				pos=i;
				break;
			}
		} 
		if (pos==-1) {
			ans=ls/2+(ls%2==0?0:1);
			printf("Case #%d: %d\n",kase++,ans);
		}
		else {
			string t;
			for (int i=pos;i<ls;i++) t+=s[i];
			for (int i=0;i<pos;i++) t+=s[i];
//			cout << t << endl;
			for (int i=0;i<t.size();i++) {
				if (t[i]=='c') {
					if ((i+2)<t.size() && t[i+2]=='f' && t[i+1]=='f') ans++;
					else {
						flag=0;
						break;
					}
				}
				
			}
			if (flag) {
				printf("Case #%d: %d\n",kase++,ans);
			}
			else {
				printf("Case #%d: -1\n",kase++);
			}
		}
	}
	return 0;
}
