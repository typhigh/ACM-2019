#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2000100;
const int MOD = 1000000009;

int n, f[MAXN], g[MAXN];

LL solve(int n) {
    LL ret = 2;
    LL cur = 1;
    for (int i = 1; i < n; ++i) {
        ret = (ret + cur * 4) % MOD;
        cur = cur * f[i+1] % MOD;
    }
    return ret;
}

int main() {
    cin >> n;
    n /= 2;
    f[1] = 1;
    f[2] = 5;
    for (int i = 3; i < n; ++i) f[i] = (3+2*f[i-1]) % MOD;
    LL x = solve(n);
//    cout << x << endl;
    x = (2 * x * x + 2) % MOD;
    cout << x << endl;
}