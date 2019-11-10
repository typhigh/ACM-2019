#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;

int n, a[MAXN], id[MAXN];
int d[MAXN][20];

void init() {
    for (int i = 1; i <= n; ++i) d[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i + (1<<j) - 1 <= n; ++i) d[i][j] = max(d[i][j-1], d[i+(1<<j-1)][j-1]);
    } 
}

int query(int l, int r) {
    int k = 0;
    while ((1 << k) <= r - l + 1) ++k;
    return max(d[l][k-1], d[r-(1<<k-1)+1][k-1]);
}

LL solve(int l, int r) {
    if (l >= r) return 0;
    LL ret = 0;
    int m = query(l, r);
    int p = id[m];
    if (p - l < r - p) {
        for (int i = l; i < p; ++i) {
            int x = id[m - a[i]];
            if (x > p && x <= r) ++ret;
        }
    } else {
        for (int i = p + 1; i <= r; ++i) {
            int x = id[m - a[i]];
            if (x >= l && x < p) ++ret;
        }
    }
    ret += solve(l, p-1) + solve(p+1, r);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        id[a[i]] = i;
    }
    init();
    cout << solve(1, n) << endl;  
}