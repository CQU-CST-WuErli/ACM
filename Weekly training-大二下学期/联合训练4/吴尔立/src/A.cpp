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
#include <list>
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

int n;
vector<int> Vector;
list<int> List;
deque<int> Deque;
queue<int> Queue;
stack<int> Stack;
priority_queue<int> Pqueue;
bitset<100> Bitset[2];

void init() {
	Vector.clear();
	List.clear();
    Deque.clear();
	while (Queue.size()) Queue.pop();
	while (Stack.size()) Stack.pop();
	while (Pqueue.size()) Pqueue.pop();
	Bitset[0].reset(); Bitset[1].reset();
}

void pushback(string& name, int value) {
	if (name == "std::vector<int>") Vector.push_back(value);
	else if (name == "std::list<int>") List.push_back(value);
	else if (name == "std::deque<int>") Deque.push_back(value);
	else if (name == "std::queue<int>") Queue.push(value);
	else if (name == "std::priority_queue<int>") Pqueue.push(value);
}

void popback(string& name) {
	if (name == "std::vector<int>") Vector.pop_back();
	else if (name == "std::list<int>") List.pop_back();
	else if (name == "std::deque<int>") Deque.pop_back();
}

void pushfront(string& name, int value) {
	if (name == "std::vector<int>") {
		auto it = Vector.begin();
        Vector.insert(it, value);
	}
	else if (name == "std::list<int>") List.push_front(value);
	else if (name == "std::deque<int>") Deque.push_front(value);
	else if (name == "std::stack<int>") Stack.push(value);
}

void popfront(string& name) {
	if (name == "std::vector<int>") {
        auto it = Vector.begin();
        Vector.erase(it);
	}
    else if (name == "std::list<int>") List.pop_front();
    else if (name == "std::deque<int>") Deque.pop_front();
    else if (name == "std::queue<int>") Queue.pop();
    else if (name == "std::stack<int>") Stack.pop();
    else if (name == "std::priority_queue<int>") Pqueue.pop();
}

void insert(string& name, int pos, int value) {
    if (name == "std::vector<int>") {
        auto it = Vector.begin();
        advance(it, pos);
        Vector.insert(it, value);
    }
    else if (name == "std::list<int>") {
        auto it = List.begin();
        advance(it, pos);
        List.insert(it, value);
    }
    else if (name == "std::deque<int>") {
        auto it = Deque.begin();
        advance(it, pos);
        Deque.insert(it, value);
    }
}

void erase(string& name, int pos) {
    if (name == "std::vector<int>") {
        auto it = Vector.begin();
        Vector.erase(it + pos);
    }
    else if (name == "std::list<int>") {
        auto it = List.begin();
        advance(it, pos);
        List.erase(it);
    }
    else if (name == "std::deque<int>") {
        auto it = Deque.begin();
        Deque.erase(it + pos);
    }
}

int frontvalue(string& name) {
    if (name == "std::vector<int>") return Vector[0];
    else if (name == "std::list<int>") return List.front();
    else if (name == "std::deque<int>") return Deque.front();
    else if (name == "std::queue<int>") return Queue.front();
    else if (name == "std::stack<int>") return Stack.top();
    else if (name == "std::priority_queue<int>") return Pqueue.top();
}

int backvalue(string& name) {
    if (name == "std::vector<int>") return Vector.back();
    else if (name == "std::list<int>") return List.back();
    else if (name == "std::deque<int>") return Deque.back();
}

int query(string& name, int pos) {
    if (name == "std::vector<int>") return Vector[pos];
    else if (name == "std::list<int>") {
        auto it = List.begin();
        advance(it, pos);
        return *it;
    }
    else if (name == "std::deque<int>") return Deque[pos];
}

vector<int> tmp;
int kth(string& name, int k) {
    tmp.clear();
    if (name == "std::vector<int>") {
        for (int i = 0; i < Vector.size(); i++)
            tmp.push_back(Vector[i]);
        nth_element(tmp.begin(), tmp.begin() + k - 1, tmp.end());
        return tmp[k - 1];
    }
    else if (name == "std::deque<int>") {
        for (int i = 0; i < Deque.size(); i++)
            tmp.push_back(Deque[i]);
        nth_element(tmp.begin(), tmp.begin() + k - 1, tmp.end());
        return tmp[k - 1];
    }
}

//vector list deque queue stack priority_queue
int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	init();
    	SI(n);
        getchar();
   		string s, op;
    	for (int i = 1; i <= n; i++) {
    		getline(cin, s);
            // cout << s << endl;
    		stringstream ss(s);
    		ss >> op;
    		string name; int num, pos, id;
            string other;
            // cout << op << endl;
    		if(op == "construct") continue;
    		else if (op == "push_back") {
    			ss >> num;
    			ss >> name; ss >> name;
    			pushback(name, num);
    		}
    		else if (op == "pop_back") {
    			ss >> name; ss >> name;
    			popback(name);
    		}
    		else if (op == "push_front") {
    			ss >> num; ss >> name; ss >> name;
    			pushfront(name, num);
    		}
    		else if (op == "pop_front") {
    			ss >> name; ss >> name;
    			popfront(name);
    		}
            else if (op == "insert") {
                ss >> num; ss >> other;
                ss >> name; ss >> other; ss >> pos;
                insert(name, pos, num);
            }
            else if (op == "erase") {
                ss >> pos; ss >> other;
                ss >> name;
                erase(name, pos);
            }
            else if (op == "front") {
                // BUG;
                ss >> other; ss >> other; ss >> name;
                cout << frontvalue(name) << endl;
            }
            else if (op == "back") {
                ss >> other; ss >> other; ss >> name;
                cout << backvalue(name) << endl;
            }
            else if (op == "query") {
                // BUG;
                ss >> pos; ss >> other; ss >> name;
                cout << query(name, pos) << endl;
            }
            else if (op[op.size() - 1] == 'h' && op[op.size() - 2] == 't') {
                ss >> other; ss >> name;
                int k = 0;
                for (int i = 0; i < op.size(); i++) {
                    if (op[i] == '-') break;
                    k = k * 10 + op[i] - '0';
                }
                cout << kth(name, k) << endl;
            }
            else if (op == "set" && s[4] != 'i') {
                ss >> pos; ss >> other;
                ss >> name; ss >> id;
                Bitset[id].set(pos);
            }
            else if (op == "reset" && s[6] != 'i') {
                ss >> pos; ss >> other;
                ss >> name; ss >> id;
                Bitset[id].reset(pos);
            }
            else if (op == "set" && s[4] == 'i') {
                ss >> other; ss >> name; ss >> id;
                Bitset[id].set();
            }
            else if (op == "reset" && s[6] == 'i') {
                ss >> other; ss >> name; ss >> id;
                Bitset[id].reset();
            }
            else if (op == "flip" && s[5] != 'i') {
                ss >> pos; ss >> other; ss >> name; ss >> id;
                Bitset[id].flip(pos);
            }
            else if (op == "flip" && s[5] == 'i') {
                ss >> other; ss >> name; ss >> id;
                Bitset[id].flip();
            }
            else if (op == "count") {
                ss >> other; ss >> name; ss >> id;
                cout << Bitset[id].count() << endl;
            }
            else if (op == "test") {
                ss >> pos; ss >> other; ss >> name;
                ss >> id;
                puts(Bitset[id].test(pos) ? "true" : "false");
            }
            else if (op == "intersection") {
                int flag = 0;
                for (int i =0; i < (int)Bitset[0].size(); i++) {
                    if (Bitset[0][i] && Bitset[1][i]) {
                        flag = 1;
                        break;
                    }
                }
                puts(flag ? "true" : "false");
            }
    	}
    }
	return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			佛祖保佑		永无BUG
*/