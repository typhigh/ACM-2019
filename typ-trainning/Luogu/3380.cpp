#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000100;
const int N = 50010;
const int INF = 2147483647;
/**********/
// Treap
struct Node {
    Node* ch[2];
    int r;
    int v;
    int s;
    int c;
    Node(){}
    Node (int v) : v(v) {
        ch[0] = ch[1] = NULL;
        r = rand();
        s = 1;
        c = 1;
    }

    bool operator < (const Node& rhs) const {
        return r < rhs.r;
    }

    int cmp(int x) const {
        if (x == v) return -1;
        return x < v ? 0 : 1;
    }

    void maintain() {
        s = c;
        if (ch[0] != NULL) s += ch[0]->s;
        if (ch[1] != NULL) s += ch[1]->s;
    }
} node[MAXN];
int tot;
queue<Node*> q;

Node* newNode(int x) {
    if (q.empty()) {
        node[++tot] = Node(x);
        return &node[tot];
    }
    Node* u = q.front();
    q.pop();
    *u = Node(x);
    return u;
}

void delNode(Node* u) {
    q.push(u);
}

void rotate(Node* &o, int d) {
    Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d];k->ch[d] = o;
    o->maintain();k->maintain(); o = k;
}

void insert(Node* &o, int x) {
    if (o == NULL) o = newNode(x);
    else {
        if (x == o->v) ++o->c;
        else {
            int d = (x < o->v ? 0 : 1);
            insert(o->ch[d], x);
            if (o->ch[d]->r > o->r) rotate(o, d^1);
        }
    }
    o->maintain();
}

void remove(Node* &o, int x) {
    int d = o->cmp(x);
    if (d == -1) {
        if (o->c == 1) {
            Node* u = o;
            if (o->ch[0] != NULL && o->ch[1] != NULL) {
                int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
                rotate(o, d2); remove(o->ch[d2], x);
            } else {
                if (o->ch[0] == NULL) o = o->ch[1]; 
                else o = o->ch[0];
                delNode(u);
            }
        } else {
            --o->c;
        }
    } else {
        remove(o->ch[d], x);
    }
    if (o != NULL) o->maintain();
}

int findLess(Node* o, int x) {
    // less than x
    int cnt = 0;
    while (o != NULL) {
        int d = o->cmp(x);
        if (d <= 0) o = o->ch[0];
        else {
            cnt += (o->ch[0] == NULL) ? 0 : o->ch[0]->s;
            cnt += o->c;
            o = o->ch[1];   
        }
    }
    return cnt;
}

int findPrev(Node* o, int x) {
    int ret = -INF;
    while (o != NULL) {
        int d = o->cmp(x);
        if (d <= 0) o = o->ch[0];
        else {
            ret = max(ret, o->v);
            o = o->ch[1];
        }
    }
    return ret;
}

int findNext(Node* o, int x) {
    int ret = INF;
    while (o != NULL) {
        int d = o->cmp(x);
        if (d == 0) {
            ret = min(ret, o->v);
            o = o->ch[0];
        } else {
            o = o->ch[1];
        }
    }
    return ret;
}
/******/
// SegmentTree

Node* root[N<<2];
int n, m, a[N];

void segInsert(int id, int l, int r, int pos, int x) {
    insert(root[id], x);
    if (l == r) return;
    int mid = l + (r - l) / 2;
    if (mid >= pos) segInsert(id<<1, l, mid, pos, x);
    else segInsert(id<<1|1, mid+1, r, pos, x);
}

void segDel(int id, int l, int r, int pos, int x) {
    remove(root[id], x);
    if (l == r) return;
    int mid = l + (r - l) / 2;
    if (mid >= pos) segDel(id<<1, l, mid, pos, x);
    else segDel(id<<1|1, mid+1, r, pos, x);
}

int segQuery(int id, int l, int r, int L, int R, int x) {
    // less than x
    if (L <= l && r <= R) {
        return findLess(root[id], x);
    }
    int mid = l + (r - l) / 2;
    int ans = 0;
    if (L <= mid) ans += segQuery(id<<1, l, mid, L, R, x);
    if (R >= mid+1) ans += segQuery(id<<1|1, mid+1, r, L, R, x);
    return ans; 
}

int segPrev(int id, int l, int r, int L, int R, int x) {
    if (L <= l && r <= R) return findPrev(root[id], x);
    int ans = -INF;
    int mid = l + (r - l) / 2;
    if (L <= mid) ans = max(ans, segPrev(id<<1, l, mid, L, R, x));
    if (R >= mid+1) ans = max(ans, segPrev(id<<1|1, mid+1, r, L, R, x));
    return ans;
}

int segNext(int id, int l, int r, int L, int R, int x) {
    if (L <= l && r <= R) return findNext(root[id], x);
    int ans = INF;
    int mid = l + (r - l) / 2;
    if (L <= mid) ans = min(ans, segNext(id<<1, l, mid, L, R, x));
    if (R >= mid+1) ans = min(ans, segNext(id<<1|1, mid+1, r, L, R, x));
    return ans;
}

int QueryOP(int opt, int l, int r, int x) {
    int ret;
    if (opt == 1) {
        ret = segQuery(1, 1, n, l, r, x) + 1;
    } else if (opt == 2) {
        int L = 0, R = INF;
        while (L <= R) {
            int mid = L + (R-L) / 2;
            int tmp = segQuery(1, 1, n, l, r, mid);
//            cout << mid << " " << tmp << " " << x << endl;
            if (tmp + 1 <= x) {
                L = mid+1;
                ret = mid;
            } else {
                R = mid-1;
            }
        }
    } else if (opt == 4) {
        ret = segPrev(1, 1, n, l, r, x);
    } else if (opt == 5) {
        ret = segNext(1, 1, n, l, r, x);
    }
    return ret;
}

void UpdateOP(int pos, int x) {
    segDel(1, 1, n, pos, a[pos]);
    segInsert(1, 1, n, pos, x);
    a[pos] = x;
}

void test() {
//    cout << segQuery(1, 1, n, 1, 4, 2) << endl;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    for (int i = 1; i <= n; ++i) {
        segInsert(1, 1, n, i, a[i]);
    }

    test();
    while (m--) {
        int opt, l, r, x, pos;
        scanf("%d", &opt);
        if (opt != 3) {
            scanf("%d %d %d", &l, &r, &x);
            printf("%d\n", QueryOP(opt, l, r, x));
        }
        else {
            scanf("%d %d", &pos, &x);
            UpdateOP(pos, x);
        }
    }
}