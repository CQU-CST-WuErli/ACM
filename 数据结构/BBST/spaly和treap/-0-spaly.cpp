//-------------------------//
//         /\_/\           //
//    ____/ o o \  Nya~~   //
//  /~____ = ω =/          //
// (______)__m_m)          //
//-------------------------//
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define lson id << 1
#define rson id << 1 | 1
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf  = 0x3f3f3f3f;
const int maxn = 2e6 + 15;

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


class SplayTree {
public:
	struct Node {
		int key, sz, flip; char c;
		Node *pre, *ch[2];
		Node(){}
		Node(int a, int b){ key = a, sz = b; flip = 0; }
		void rs() { sz = ch[0]->sz + ch[1]->sz + 1; }
	}*null, *root, pool[maxn];
	int psz;
	SplayTree() { clear(); }

	void clear() {
		null = new Node(-1, 0);
		root = null; psz = 0;
	}

	Node* NewNode(int x, char c) {
		Node *p = &pool[psz++]; p->c = c;
		p->key = x, p->sz = 1, p->flip = 0;
		p->ch[0] = p->ch[1] = p->pre = null;
		return p;
	}

	void pushDown(Node* x) {
		if(!x->flip) return; x->flip = 0;
		if(x->ch[0] != null) x->ch[0]->flip ^= 1;
		if(x->ch[1] != null) x->ch[1]->flip ^= 1;
		swap(x->ch[0], x->ch[1]);
	}

	void rotate(Node* &x, int k) {
		Node *y = x->pre;
		pushDown(y), pushDown(x);
		y->ch[!k] = x->ch[k];
		if(x->ch[k] != null) x->ch[k]->pre = y;
		x->pre = y->pre;
		if(y->pre != null)
			if(y->pre->ch[0] == y) y->pre->ch[0] = x;
			else y->pre->ch[1] = x;
		x->ch[k] = y, y->pre = x;
		if(y == root) root = x; y->rs();
	}

	void splay(Node* x, Node* target) {
		pushDown(x);
		while(x->pre != target) {
			Node *y = x->pre;
			int d = x != y->ch[0];
			if(y->pre != target && y == y->pre->ch[d])
				rotate(y, d ^ 1);
			rotate(x, d ^ 1);
		}
		if(target == null) root = x; x->rs();
	}

    void select(int k, Node* x, Node* target) {
        while(true) {
			pushDown(x);
		    if(k == x->ch[0]->sz + 1) break;
			if (k <= x->ch[0]->sz)
                x = x->ch[0];
            else {
                k -= x->ch[0]->sz + 1;
            	x = x->ch[1];
        	}
        }
        splay(x, target);
    }

	Node* move(int k) {
		select(k + 1, root, null);
		return root;
	}

	void insert(Node* &x, int l, int r, char *s, Node* &fa) {
		if(r < l) return;
		int mid = l + r >> 1;
		x = NewNode(psz, s[mid]); x->pre = fa;
		insert(x->ch[0], l, mid - 1, s, x);
		insert(x->ch[1], mid + 1, r, s, x);
		x->rs();
	}

	void build(char *s) {
		Node* x = root;
		Node* y = getMin(x->ch[1]);
		splay(y, x);
		insert(y->ch[0], 0, strlen(s) - 1, s, y);
		y->ch[0]->rs(); y->rs(); x->rs();
	}

	Node* getMin(Node* x) {
		pushDown(x);
		while(x->ch[0] != null) {
			x = x->ch[0];
			pushDown(x);
		}
		return x;
	}

	Node* getMax(Node* x) {
		pushDown(x);
		while(x->ch[1] != null) {
			x = x->ch[1];
			pushDown(x);
		}
		return x;
	}

	void del(int n) {
		Node* x = root;
		pushDown(x);
		select(n + 1, x->ch[1], x);
		x->ch[1]->ch[0] = null;
		root->ch[1]->rs(); root->rs();
	}

	void flip(int n) {
		Node* x = root;
		select(n + 1, x->ch[1], x);
		root->ch[1]->ch[0]->flip ^= 1;
	}

	char get() {
		Node* x = getMin(root->ch[1]);
		return x->c;
	}

	void prev() {
		Node* x = getMax(root->ch[0]);
		splay(x, null);
	}

	void next() {
		Node* x = getMin(root->ch[1]);
		splay(x, null);
	}

	void init() {
		clear();
		char p[3] = "xx";
		this->insert(root, 0, 1, p, null);
		move(0);
	}

} editor;

char s[maxn];

int main(){
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif
	int n, m; char ope[15];
	while(~scanf("%d", &n)) {
		editor.init();
		for(int i = 1; i <= n; i++) {
			scanf("%s", ope);
			switch(ope[0]) {
				case 'M':
					m = read();
					editor.move(m);
					break;
				case 'I':
					m = read();
					gets(s);
					editor.build(s);
					break;
				case 'D':
					m = read();
					editor.del(m);
					break;
				case 'R':
					m = read();
					editor.flip(m);
					break;
				case 'G':
					putchar(editor.get());
					putchar('\n');
					break;
				case 'P':
					editor.prev();
					break;
				case 'N':
					editor.next();
					break;
			}
		}
	}
	return 0;
}