#include <bits/stdc++.h>
using namespace std;
set<pair<int,int>> s;
int ans[100004];
int n, m;

void solve() {
    int t = 500;
    for (int i = 1; i <= n; ++i) ans[i] = i;
    while (t--) {
        random_shuffle(ans+1, ans+n+1);
        int cnt = 0;
        ans[0] = ans[n];
        for (int i = 1; i <= n; ++i) {
            if (s.count(make_pair(ans[i], ans[i-1]))) continue;
            ++cnt;
        }
        if (cnt < m) continue;
        for (int i = 1; i <= n; ++i) {
            if (s.count(make_pair(ans[i], ans[i-1]))) continue;
            printf("%d %d\n", ans[i-1], ans[i]);
            if (--m == 0) return;
        }
    }
    puts("-1");
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        s.emplace(u, v);
        s.emplace(v, u);
    }
    solve();
}
