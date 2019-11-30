#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, tot, ans[MAXN];

void solve() {
    tot = 0;
    for (int i = 1, last; i <= n; i = last + 1) {
        last = n / (n / i);
        ans[tot++] = n / i;
    }
    ans[tot++] = 0;
    printf("%d\n", tot);
    for (int i = tot-1; i >= 0; --i) printf("%d%c", ans[i], " \n"[i==0]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        solve();
    }
}