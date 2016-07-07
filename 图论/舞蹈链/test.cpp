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
#define sacnf scanf
using namespace std;
const int maxn = 1e6 + 15;
const int inf = 0x3f3f3f3f;

struct Node {
    int c, r;
    Node *left, *right, *up, *down;
};

Node pool[maxn], head, *p, col[1005], row[1005];

int cnt, size[1005];
int ans[1005], m, n;

    void init(int r, int c) {
        cnt = 0, head.r = 0, head.c = 0;
        head.left = head.right = head.up = head.down = &head;
        for(int i = 1; i <= c; i++) {
            col[i].r = 0, col[i].c = i;
            col[i].left = &head;
            col[i].right = head.right;
            col[i].left->right = col[i].right->left = &col[i];
            col[i].up = col[i].down = &col[i];
            size[i] = 0;
        }

        for(int i = r; i >= 1; i--) {
            row[i].r = i, row[i].c = 0;
            row[i].up = &head;
            row[i].down = head.down;
            row[i].up->down = row[i].down->up = &row[i];
            row[i].left = row[i].right = &row[i];
        }
    }

    void add(int r, int c) {
        p = &pool[cnt++];
        p->r = r, p->c = c;

        p->right = &row[r];
        p->left  = row[r].left;
        p->left->right = p->right->left = p;

        p->up = &col[c];
        p->down = col[c].down;
        p->up->down = p->down->up = p;

        size[c]++;
    }

    void delLR(Node *pt) {
        pt->left->right = pt->right;
        pt->right->left = pt->left;
    }

    void delUD(Node *pt) {
        pt->up->down = pt->down;
        pt->down->up = pt->up;
    }

    void resumeLR(Node *pt) { pt->left->right = pt->right->left = pt; }

    void resumeUD(Node *pt) { pt->up->down = pt->down->up = pt; }

    void cover(int c) {
        if(!c) return;
        delLR(&col[c]);
        Node *R, *C;
        for(C = col[c].down; C != (&col[c]); C = C->down) {
            if(!C->c) continue;
            for(R = C->left; R != C; R = R->left) {
                if(!R->c) continue;
                --size[R->c];
                delUD(R);
            }
            delLR(C);
        }
    }

    void resume(int c) {
        if(!c) return;
        Node *R, *C;
        for(C = col[c].up; C != (&col[c]); C = C->up) {
            if(!C->c) continue;
            resumeLR(C);
            for(R = C->right; R != C; R = R->right) {
                if(!R->c) continue;
                size[R->c]++;
                resumeUD(R);
            }
        }
        resumeLR(&col[c]);
    }

    bool search(int k) {
        if(head.left == (&head)) {
            printf("%d ", k);
            for(int i = 0; i < k; i++)
                printf("%d%c", ans[i], " \n"[i == k - 1]);
            return true;
        }

        int c = -1, mi = inf;

        for(p = head.left; p != (&head); p = p->left) {
            if(size[p->c] < mi) {
                mi = size[p->c];
                c = p->c;
            }
        }

        cover(c);

        for(p = col[c].down; p != (&col[c]); p = p->down) {
            Node* rc;
            p->right->left = p;
            for(rc = p->left; rc != p; rc = rc->left)
                cover(rc->c);
            p->right->left = p->left;
            ans[k] = p->r;

            if(search(k + 1)) return true;

            p->left->right = p;
            for(rc = p->right; rc != p; rc = rc->right)
                resume(rc->c);

            p->left->right = p->right;

        }
        resume(c);
        return false;
    }


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(~scanf("%d %d", &m, &n)) {
        init(m, n);
        for(int i = 1; i <= m; i++) {
            int x, j;
            scanf("%d", &x);
            while(x--) {
                scanf("%d", &j);
                add(i, j);
            }
        }
        if(!search(0)) puts("NO");
    }
    return 0;
}