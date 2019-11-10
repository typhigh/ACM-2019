#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000100;
const LL MOD = 1e9 + 7;

int n;
LL fac[MAXN], inv[MAXN];

LL quick_pow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; ++i) fac[i] = fac[i-1] * i % MOD;
    inv[MAXN-1] = quick_pow(fac[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; --i) inv[i] = inv[i+1] * (i+1) % MOD;
    assert(inv[0]==1);
}

LL C(int n, int m) {
    if (m > n) return 0;
    return fac[n] * inv[m] % MOD * inv[n-m] % MOD;
}

LL dp[MAXN], f[MAXN];
int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++dp[x];
    }
    for (int i = 0; i < 20; ++i) {
        for (int s = 0; s < MAXN; ++s) 
            if (s & (1 << i)) dp[s^(1<<i)] += dp[s];
    }
//    cout << dp[1] << endl;
    LL ans = quick_pow(2, n) - 1;
    f[0] = 0;
//    cout << ans << endl;
    for (int s = 1; s < MAXN; ++s) {
        f[s] = f[(s - 1) & s] + 1; 
        int flag = (f[s] & 1) ? -1 : 1;
        ans = (ans + flag * (quick_pow(2, dp[s]) - 1)) % MOD;
//        cout << ans << endl;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}