#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;
int tot, n, m, BIT[MAXN], pos[MAXN];
LL ans[MAXN];
void BITAdd(int x, int d) {
    for (; x <= n; x += x&-x) BIT[x] += d; 
}

int BITSum(int x) {
    int ret = 0;
    for (; x > 0; x -= x & -x) ret += BIT[x];
    return ret;
}

struct Node {
    int v, m, pos, id;
    bool operator < (const Node& rhs) const {
        return pos < rhs.pos;
    }
} a[MAXN];

void CDQ(int l, int r) {
    if (l == r) return;
    int mid = l + (r - l) / 2;
    CDQ(l, mid);
    CDQ(mid+1, r);
    sort(a+l, a+mid+1);
    sort(a+mid+1, a+r+1);
    // [l, mid] -> [mid+1, r] 
    int j = l;
    for (int i = mid+1; i <= r; ++i) {
        while (j <= mid && a[j].pos <= a[i].pos) {
            BITAdd(a[j].v, a[j].m);   
            ++j;
        }
        ans[a[i].id] += a[i].m * (BITSum(n) - BITSum(a[i].v));
    }
    for (int i = l; i < j; ++i) BITAdd(a[i].v, -a[i].m);
    j = mid;
    for (int i = r; i >= mid+1; --i) {
        while (j >= l && a[j].pos >= a[i].pos) {
            BITAdd(a[j].v, a[j].m);
            --j;
        }
        ans[a[i].id] += a[i].m * BITSum(a[i].v-1);
    }
    for (int i = mid; i > j; --i) BITAdd(a[i].v, -a[i].m);
}
void solve() {
    CDQ(1, tot);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[++tot] = Node {x, 1, i, 0};
        pos[x] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        a[++tot] = Node {x, -1, pos[x], i};
    }
    solve();
    for (int i = 1; i < m; ++i) ans[i] += ans[i-1];
    for (int i = 0; i < m; ++i) printf("%lld\n", ans[i]);
}