#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
int n, m, a[MAXN];
LL cnt[2*MAXN];

LL solve() {
    LL ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) cnt[i+MAXN] = 1;
    for (int i = 1; i <= m; ++i) {
        int x = a[i] - i;
        cnt[x-1+MAXN] += cnt[x+MAXN];
        cnt[x+MAXN] = 0;
    }
    for (int i = -m; i <= n; ++i) {
        ans += cnt[i+MAXN] * min(i+m+1, n);
//        cout << cnt[i+MAXN] << " " << min(i+m, n) << endl;
    }
    ans -= (LL)n * (n-1) / 2;
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    if (n == 1 && m >= 1) {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 1; i <= m; ++i) scanf("%d", a+i);
    LL ans = solve();
//    cout << ans << endl;
    for (int i = 1; i <= m; ++i) a[i] = n - a[i] + 1;
    ans += solve();
    ans -= n;
    cout << ans << endl;
}