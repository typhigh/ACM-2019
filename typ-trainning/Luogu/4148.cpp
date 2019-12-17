#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;

int tot, N;
struct Point {
    int x[2], w;
};

int ch[MAXN][2], sz[MAXN], mi[MAXN][2], mx[MAXN][2], sum[MAXN], st[MAXN], top;
Point tp[MAXN], tmp[MAXN];
int tmpTot;

int newNode() {
    if (tot == MAXN-1 || top == MAXN-1) {
        puts("NO");
        exit(1);
        //while (1);
    }
    if (!top) return ++tot;
    return st[top--];
}

void delNode(int& x) {
    st[++top] = x;
    ch[x][0] = ch[x][1] = sz[x] = sum[x] = mi[x][0] = mi[x][1] = mx[x][0] = mx[x][1] = 0;
    x = 0;
}

void pushUp(int id) {
    for (int i = 0; i < 2; ++i) {
        int child = ch[id][i];
        if (!child) continue;
        sum[id] += sum[child];
        sz[id] += sz[child];
        for (int k = 0; k < 2; ++k) {
            mi[id][k] = min(mi[id][k], mi[child][k]);
            mx[id][k] = max(mx[id][k], mx[child][k]);
        }
    }
}

void pre(int id) {
    if (!id) return;
    int lch = ch[id][0], rch = ch[id][1];
    if (lch) pre(lch); 
    tmp[++tmpTot] = tp[id];
    delNode(id);
    if (rch) pre(rch);
}

int build(int l, int r, int dim) {
    if (l > r) return 0;
    int k = newNode();
    sz[k] = 1;
    sum[k] = tmp[l].w;
    for (int i = 0; i < 2; ++i) mi[k][i] = mx[k][i] = tmp[l].x[i];
    if (l == r) return k;

    int mid = (l+r) >> 1;
    nth_element(tmp+l, tmp+mid+1, tmp+r+1, [dim](const Point& lsh, const Point& rhs){
        return lsh.x[dim] < rhs.x[dim];
    });
    ch[k][0] = build(l, mid-1, dim^1);
    ch[k][1] = build(mid+1, r, dim^1);
    pushUp(k);
    return k;
}

void check(int &id) {
//    if (sz[id] < 7) return;
    if (sz[ch[id][0]] < sz[id] * 0.75 || sz[ch[id][1]] < sz[id] * 0.75) {
        tmpTot = 0;
        pre(id);
        id = build(1, tmpTot, 0);
    }
}

void insert(int x, int y, int c, int& id, int dim) {
    if (!id) { 
        id = newNode();
        sz[id] = 1;
        tp[id] = Point {x, y, c};
        sum[id] = c;
        mi[id][0] = mx[id][0] = x;
        mi[id][1] = mx[id][1] = y;
        return;
    } 
     
    int nx = dim == 0 ? x : y;  
    if (nx <= tp[id].x[dim]) {
        insert(x, y, c, ch[id][0], dim^1);
    } else {
        insert(x, y, c, ch[id][1], dim^1);
    }
    pushUp(id);
    check(id);
}

bool in(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
    // [X1Y1, X2Y2] rec in [x1y1,x2y2]
    return x1 <= X1 && y1 <= Y1 && X2 <= x2 && Y2 <= y2;
} 

bool out(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
    // No intersection
    return x1 > X2 || x2 < X1 || y1 > Y2 || y2 < Y1;
}

int query(int x1, int y1, int x2, int y2, int id) {
    if (!id) return 0;
    int ret = 0;
    if (in(x1, y1, x2, y2, mi[id][0], mi[id][1], mx[id][0], mx[id][1])) return sum[id];
    if (out(x1, y1, x2, y2, mi[id][0], mi[id][1], mx[id][0], mx[id][1])) return 0;
    if (in(x1, y1, x2, y2, tp[id].x[0], tp[id].x[1], tp[id].x[0], tp[id].x[1])) ++ret;
    ret += query(x1, y1, x2, y2, ch[id][0]) + query(x1, y1, x2, y2, ch[id][1]);
    return  ret;
} 

int main() {
    scanf("%d", &N);
    int op, ans = 0;
    int root = 0;
    while (~scanf("%d", &op) && op != 3) {
        if (op == 1) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            x ^= ans, y ^= ans, c ^= ans;
//            cout << x << " " << y << " " << c << '\n';
            insert(x, y, c, root, 0);    
        } else {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x1 ^= ans, y1 ^= ans, x2 ^= ans, y2 ^= ans;
//            cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
            ans = query(x1, y1, x2, y2, 1);
            printf("%d\n", ans);
        }
    }
}