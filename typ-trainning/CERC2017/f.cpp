#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001000;
typedef long long LL;
LL n, p, r;
int inv[MAXN];

pair<int, int> solve() {
    if (r == 0) {
        if (n >= p) {
            if (n == p && n == 2) return make_pair(-1, -1); 
            if (p == 2) return make_pair(p+1, 1);
            return make_pair(2, 1);
        }
        return make_pair(-1, -1);
    }
    if (n >= 2*p) return make_pair(-1, -1);
    if (n >= p) {
        LL now = p - 1;
        for (int i = p+1; i <= n; ++i) now = now * (i-p) % p;
//        cout << now << endl;
        LL ans = inv[now] * r % p;
        return make_pair(p, ans);
    }
    LL now = 1;
    for (int i = 1; i <= n; ++i) now = i * now % p;
//    cout << now << " " << inv[now] << endl;
    for (int i = 2; i <= n; ++i) {
        int ans = r * i % p * inv[now] % p;
        if (ans >= i) continue;
        return make_pair(i, ans);
    }
    return make_pair(-1, -1);
}

int main() {
    cin >> n >> p >> r;
    inv[1] = 1;
    for (int i = 2; i < p; ++i) inv[i] = 1LL * (p - p/i) * inv[p % i] % p;
    auto ans = solve();
    cout << ans.first << " " << ans.second << endl;
}