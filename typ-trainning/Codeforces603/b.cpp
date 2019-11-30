#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;
string a[MAXN];
int n;
bool vis[MAXN];

void solve() {
    set<string> s;
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!s.count(a[i])) {
            vis[i] = true;
            s.insert(a[i]);
        } else {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        if (s.count(a[i])) {
            for (int j = 0; j < 10; ++j) {
                a[i][0] = '0' + j;
                if (!s.count(a[i])) break;
            }
            assert(!s.count(a[i]));
            s.insert(a[i]);
        }
    }
    for (int i = 0; i < n; ++i) cout << a[i] << '\n';
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        solve();
    }
}