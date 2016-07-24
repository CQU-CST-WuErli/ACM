//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <bitset>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int k, n, m, q;
map<string, int> mp;
string name[111];
int ID_cnt;
int getID(string& s) {
	if (mp.find(s) == mp.end()) mp[s] = ++ID_cnt;
	return mp[s];
}
int has[111][111];
vector<pair<int, int> > need[111];

int getNum(string& s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++)
		ret = ret * 10 + s[i] - '0';
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    SIII(k, n, m);
    SI(q);
    CLR(has);
    ID_cnt = 0;
    string s;
    for (int i = 1; i <= n; i++) {
    	cin >> s;
		name[getID(s)] = s;
		// cout << getID(s) << ' ' << s << endl;
    }
    getchar();
    string t;
    for (int i = 1; i <= m; i++) {
    	getline(cin, s);
    	// cout << s << endl;
    	stringstream ss(s);
    	ss >> t;
    	t.pop_back();
    	int tid;
    	name[tid = getID(t)] = t;
    	while (ss >> t) {
    		int id = getID(t);
    		ss >> t;
    		if (t.back() == ',') t.pop_back();
    		need[tid].push_back(make_pair(id, getNum(t)));
    		// cout << tid << ' ' << id << ' ' << getNum(t) << endl;
    	}
    }
    int id;
    for (int i = 1; i <= q; i++) {
    	// lookln(i);
    	cin >> id >> s;
    	int tid = getID(s);
    	has[id][tid]++;
    	for (int j = n + 1; j <= n + m; j++) {
    		int flag = 1;
    		for (auto& it : need[j]) {
    			if (has[id][it.first] < it.second) {
    				flag = 0;
    				break;
    			}
    		}
    		if (flag) {
    			for (auto& it : need[j]) {
    				has[id][it.first] -= it.second;
    			}
    			has[id][j]++;
    		}
    	}
    }
    for (int i = 1; i <= k; i++) {
    	int sum = 0;
    	for (int j = 1; j <= n + m; j++) if (has[i][j]) sum++;
    	printf("%d\n", sum);
    	vector<pair<string, int> > ans;
    	for (int j = 1; j <= n + m; j++) if (has[i][j]) {
    		ans.push_back(make_pair(name[j], has[i][j]));
    	}
    	sort(ans.begin(), ans.end());
    	for (auto& it : ans)
    		cout << it.first << ' ' << it.second << '\n';
    }
	return 0;
}