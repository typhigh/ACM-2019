#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;
int K, tot, qtot, ans[MAXN];
struct Op {
    int op, x, y, z, qtime;
    bool operator < (const Op& rhs) const {
        return x < rhs.x;
    }
} a[MAXN<<2], tmp[MAXN<<2];

int BIT[MAXN << 2];
void add(int x, int d) {
    for (; x <= K; x += x & -x) BIT[x] += d;
}

int sum(int x) {
    int ret = 0; 
    for (;x > 0; x -= x & -x) ret += BIT[x];
    return ret;
}

void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid+1, r);
    int t = 0;
    for (int i = l; i <= r; ++i) {
        if (i <= mid && a[i].op == 1) tmp[++t] = a[i];
        if (i > mid && a[i].op == 2) tmp[++t] = a[i]; 
    }
    sort(tmp+1, tmp+t+1);
//   cout << t << endl;    
    for (int i = 1; i <= t; ++i) {
        Op& e = tmp[i];
//        cout << e.op << ' ' << e.y << ' ' << e.z << ' ';
        if (e.op == 1) add(e.y, e.z);
        else ans[e.qtime] += sum(e.y) * e.z;
    }

    for (int i = 1; i <= t; ++i) {
        Op& e = tmp[i];
        if (e.op == 1) add(e.y, -e.z);
    }
} 

int main() {
    scanf("%d", &K);
    int op;
    while (~scanf("%d", &op) && op != 3) {
        if (op == 1) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            a[++tot] = Op {op, x, y, z, -1};
        } else if (op == 2) {
            ++qtot;
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            a[++tot] = Op {op, x1-1, y1-1, 1, qtot};
            a[++tot] = Op {op, x1-1, y2, -1, qtot};
            a[++tot] = Op {op, x2, y1-1, -1, qtot};
            a[++tot] = Op {op, x2, y2, 1, qtot};
        }
    }
    cdq(1, tot);
 //   int last_ans = 0;
    for (int i = 1; i <= qtot; ++i) {
//        last_ans ^= ans[i];
        printf("%d\n", ans[i]);
    }
}